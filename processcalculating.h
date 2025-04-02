#ifndef PROCESSCALCULATING_H
#define PROCESSCALCULATING_H
#include <QString>
#include <QTimer>
#include <QObject>
class ProcessCalculating : public QObject
{
    Q_OBJECT
public:
    explicit ProcessCalculating(QObject *parent = 0);
signals:
    void sendToQml(double resultNum);
    void sendToBeforeN(QString bN);
    void sendToNowN(QString nN);
    void secretMenuActive();
public slots:
    void receiveFromQml(QString str);
    void itIsSecret(QString str);
private:
    double resultNum;
    QString nN;
    QString bN;
    QString operation;
    QTimer timer;
    QString secretCode;


};

#endif
