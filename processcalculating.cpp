#include "processcalculating.h"
#include <QDebug>
#include <QRegularExpression>
#include <iomanip>

ProcessCalculating::ProcessCalculating(QObject *parent) : QObject(parent)
{
    resultNum = 0;
    bN = "";
    nN = "";
    timer.setInterval(5000);
    secretCode = "";
}

void ProcessCalculating::itIsSecret(QString str)
{
    if (str == "=")
    {
        timer.start();
    }
}

void ProcessCalculating::receiveFromQml(QString str)
{
    if (timer.isActive())
    {
        secretCode += str;
        if (secretCode == "123")
        {
            emit secretMenuActive();
            secretCode = "";
        }
    }

    static QMap<QString, std::function<double(double, double)>> operations = {
        {"+", [](double a, double b) { return a + b; }},
        {"-", [](double a, double b) { return a - b; }},
        {"x", [](double a, double b) { return a * b; }},
        {"/", [](double a, double b) { return (b != 0) ? a / b : 0; }}
    };

    if (str.contains(QRegularExpression("^[0-9.]$")))
    {
        nN += str;
        emit sendToNowN(nN);
    }
    else if (operations.contains(str))
    {
        operation = str;
        bN = nN;
        nN = "";
        emit sendToBeforeN(bN);
        emit sendToNowN("0");
    }
    else if (str == "+/-" && nN != "0")
    {
        nN = QString::number(nN.toDouble() * -1);
        emit sendToNowN(nN);
    }
    else if (str == "%")
    {
        nN = QString::number(nN.toDouble() * 0.01);
        emit sendToNowN(nN);
    }
    else if (str == "C")
    {
        bN = "";
        nN = "";
        emit sendToBeforeN("");
        emit sendToNowN("0");
    }
    else if (str == "=" && operations.contains(operation))
    {
        resultNum = operations[operation](bN.toDouble(), nN.toDouble());
        QString resultStr = QString::number(resultNum, 'f', 6);

        resultStr.remove(QRegularExpression("(\\.\\d*?[1-9])0+$"));
        resultStr.remove(QRegularExpression("\\.$"));

        nN = resultStr;
        bN = nN;

        emit sendToBeforeN("");
        emit sendToQml(nN.toDouble());
    }
}
