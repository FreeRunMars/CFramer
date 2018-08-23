#include "cmainwindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initUi();
    initConnect();
}

CMainWindow::~CMainWindow()
{

}

void CMainWindow::setTitleBar(CTitleBar *titleBar)//share_ptr<CTitleBar>
{
    if(!titleBar){
        return;
    }
    if(m_titleBar){
        delete m_titleBar;
    }
    m_titleBar = titleBar;
    m_titleBar->move(0, 0);
    initConnect();//initConnectTitleBar();
}

CTitleBar *CMainWindow::getTitleBar()
{
    return m_titleBar;
}

void CMainWindow::minWindow()
{
    if(!windowState().testFlag(Qt::WindowMinimized)){
        showMinimized();
    }
}

void CMainWindow::maxWindow()
{
    if(!windowState().testFlag(Qt::WindowMaximized)){
        showMaximized();
    }
}

void CMainWindow::restoreWindow()
{
    if(!windowState().testFlag(Qt::WindowNoState)){
        showNormal();
    }
}

void CMainWindow::closeWindow()
{
    close();
}

void CMainWindow::initUi()
{
    this->setMinimumSize(1200, 800);
    this->setWindowFlags(Qt::FramelessWindowHint);

    m_titleBar = new CTitleBar(this);
    m_centerFrame = new CCenterFrame(this);
    m_statusBar = new CStatusBar(this);

    m_titleBar->move(0, 0);
    this->setCentralWidget(centerFrame);
    this->setStatusBar(m_statusBar);

    this->layout()->setContentsMargins(0, 0, 0, 0);
    this->layout()->setSpacing(0);
}

void CMainWindow::initConnect()
{
    if(m_titleBar){
        connect(m_titleBar, &CTitleBar::minButtonClicked, this, &CMainWindow::minWindow);
        connect(m_titleBar, &CTitleBar::maxButtonClicked, this, &CMainWindow::maxWindow);
        connect(m_titleBar, &CTitleBar::restoreButtonClicked, this, &CMainWindow::restoreWindow);
        connect(m_titleBar, &CTitleBar::closeButtonClicked, this, &CMainWindow::closeWindow);
    }
}

void CMainWindow::initData()
{

}
