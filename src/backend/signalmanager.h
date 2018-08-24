#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include <QObject>

class SignalManager : public QObject
{
    Q_OBJECT
public:
    inline static SignalManager* instance(){
        static SignalManager instance;
        return &instance;
    }

signals:
    //to do
    void changeStyleSheet(const QString &s);

private:
    explicit SignalManager(QObject *parent = 0){Q_UNUSED(parent);}
    ~SignalManager(){}
    SignalManager(const SignalManager &s):QObject(0){Q_UNUSED(s);}
    SignalManager & operator=(const SignalManager &s){Q_UNUSED(s);return *this;}
};

#endif // SIGNALMANAGER_H
