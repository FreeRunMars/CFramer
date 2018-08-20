#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H

#include <QObject>
#include <QWidget>

class CStatusBar : public QWidget
{
    Q_OBJECT
public:
    explicit CStatusBar(QWidget *parent = 0);

signals:

public slots:
};

#endif // CSTATUSBAR_H