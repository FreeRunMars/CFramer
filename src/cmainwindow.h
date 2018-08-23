#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "ctitlebar.h"
#include "ccenterframe.h"
#include "cstatusbar.h"
#include <QMainWindow>

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

    void setTitleBar(CTitleBar *titleBar);
    CTitleBar *getTitleBar();

signals:

public slots:
    void minWindow();
    void maxWindow();
    void restoreWindow();
    void closeWindow();

protected:

private:
    void initUi();
    void initConnect();
    void initData();

    CTitleBar *m_titleBar;
    CCenterFrame *m_centerFrame;
    CStatusBar *m_statusBar;
};

#endif // CMAINWINDOW_H
