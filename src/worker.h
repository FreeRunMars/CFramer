#ifndef WORKER_H
#define WORKER_H

#include "Logger.h"
#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    void initConnect();

signals:

public slots:

private:

};

#endif // WORKER_H
