#ifndef CCENTERFRAME_H
#define CCENTERFRAME_H

#include "Logger.h"
#include "logmanager.h"
#include "ctitlebar.h"
#include "cstatusbar.h"
#include "cnavigatebar.h"
#include "cpageframe.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>

class CCenterFrame : public QFrame
{
public:
    explicit CCenterFrame(QWidget *parent);

signals:

public slots:

private:
    CTitleBar *m_titleBar;
    CNavigateBar *m_navigateBar;
    CPageFrame *m_pageFrame;
    CStatusBar *m_statusBar;
    QVBoxLayout *m_layout;
    QPushButton *m_testButton;

    void initUi();
    void initConnect();
};

#endif // CCENTERFRAME_H
