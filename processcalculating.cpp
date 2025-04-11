#include "processcalculating.h"
#include <QDebug>
#include <QRegularExpression>
#include <QJSEngine>

ProcessCalculating::ProcessCalculating(QObject *parent) : QObject(parent)
{
    resultNum = 0;
    expression = "";
    timer.setInterval(5000);
    secretCode = "";
    secretInputMode = false;

}

void ProcessCalculating::itIsSecret(QString str)
{
    if (str == "=")
    {
        secretCode = "";
        secretInputMode = true;
    }
}


void ProcessCalculating::receiveFromQml(QString str)
{
    if (secretInputMode)
    {
        if (str == "=") return;

        secretCode += str;

        if (secretCode == "123")
        {
            emit secretMenuActive();
            secretCode = "";
            secretInputMode = false;
        }
        else if (secretCode.length() >= 3)
        {
            secretCode = "";
            secretInputMode = false;
        }

        return;
    }


    if (str == "()")
    {
        int open = expression.count("(");
        int close = expression.count(")");
        if (open > close)
            expression += ")";
        else
            expression += "(";

        emit sendToNowN(expression);
        return;
    }

    if (str.contains(QRegularExpression("^[0-9.]$")))
    {
        QRegularExpression re("([0-9.]+)$");
        QRegularExpressionMatch match = re.match(expression);
        if (match.hasMatch()) {
            QString lastNumber = match.captured(1);
            if (lastNumber.length() >= 12)
                return;
        }

        expression += str;
        updateDisplay();
        return;
    }


    if (str.contains(QRegularExpression("[+\\-*/]$")))
    {
        if (!expression.isEmpty() && expression.right(1).contains(QRegularExpression("[+\\-*/]")))
        {
            expression.chop(1);
        }
        expression += str;

        emit sendToBeforeN(expression);
        emit sendToNowN("0");
        return;
    }

    else if (str == "C")
    {
        expression = "";
        emit sendToBeforeN("");
        emit sendToNowN("0");
    }

    else if (str == "±" && !expression.isEmpty())
    {
        QRegularExpression re("([\\-]?[0-9.]+)$");
        QRegularExpressionMatch match = re.match(expression);

        if (match.hasMatch())
        {
            QString lastNumber = match.captured(1);
            double negated = -lastNumber.toDouble();
            QString newNumber = formatNumber(negated);

            expression.chop(lastNumber.length());
            expression += newNumber;

            emit sendToBeforeN("");
            emit sendToNowN(expression);
        }
    }


    else if (str == "%")
    {
        QJSEngine engine;
        QJSValue result = engine.evaluate("(" + expression + ") * 0.01");

        if (!result.isError())
        {
            expression = formatNumber(result.toNumber());
            emit sendToNowN(expression);
        }
    }

    else if (str == "=")
    {
        QJSEngine engine;

        QString cleaned = expression;
        cleaned.remove(QRegularExpression("[+\\-*/]+$"));

        QJSValue result = engine.evaluate(cleaned);

        if (!result.isError())
        {
            QString resultStr = formatNumber(result.toNumber());

            emit sendToBeforeN(expression);
            emit sendToNowN(resultStr);

            expression = resultStr;
        }

        else
        {
            emit sendToBeforeN("Ошибка");
            emit sendToNowN("0");
        }
    }
}

void ProcessCalculating::updateDisplay()
{
    QRegularExpression re("([0-9.]+)$");
    QRegularExpressionMatch match = re.match(expression);

    if (match.hasMatch())
    {
        QString lastNumber = match.captured(1);
        QString beforeExpr = expression;
        beforeExpr.chop(lastNumber.length());

        emit sendToBeforeN(beforeExpr);
        emit sendToNowN(lastNumber);
    }
    else
    {
        emit sendToBeforeN(expression);
        emit sendToNowN("0");
    }
}

QString ProcessCalculating::formatNumber(double num)
{
    return QString::number(num, 'g', 10);
}
