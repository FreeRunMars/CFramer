#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "signalmanager.h"
#include "ccenterframe.h"
#include <QMainWindow>

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

signals:

public slots:

private:
    void initUi();
    void initConnect();
};

#endif // CMAINWINDOW_H
