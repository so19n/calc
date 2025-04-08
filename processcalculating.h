#ifndef PROCESSCALCULATING_H
#define PROCESSCALCULATING_H

#include <QObject>
#include <QTimer>

class ProcessCalculating : public QObject
{
    Q_OBJECT
public:
    explicit ProcessCalculating(QObject *parent = nullptr);

signals:
    void sendToNowN(QString);
    void sendToBeforeN(QString);
    void sendToQml(QString);
    void secretMenuActive();

public slots:
    void receiveFromQml(QString str);
    void itIsSecret(QString str);
    QString formatNumber(double num);

private:
    double resultNum;
    QString expression;
    QString operation;
    QString bN, nN;
    QTimer timer;
    QString secretCode;
    void updateDisplay();
    bool secretInputMode;

};

#endif // PROCESSCALCULATING_H
