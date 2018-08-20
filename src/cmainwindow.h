#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "signalmanager.h"
#include "ctitlebar.h"
#include "cnavigatebar.h"
#include "cstatusbar.h"
#include <QMainWindow>
#include <QVBoxLayout>

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

    CTitleBar *m_titleBar;
    CNavigateBar *m_navigateBar;
    CStatusBar *m_statusBar;
    QVBoxLayout *m_layout;
};

#endif // CMAINWINDOW_H
