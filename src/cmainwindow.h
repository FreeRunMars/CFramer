#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "ctitlebar.h"
#include "cnavigatewidget.h"
#include "cstatusbar.h"

#include <QFrame>
#include <QVBoxLayout>

class CMainWindow : public QFrame
{
    Q_OBJECT

public:
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 1200;

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
    CNavigateWidget *m_navigateWidget;
    CStatusBar *m_statusBar;
    QVBoxLayout *m_layout;
};

#endif // CMAINWINDOW_H
