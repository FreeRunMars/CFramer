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

void CMainWindow::initUi()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    m_titleBar = new CTitleBar();
    m_navigateBar = new CNavigateBar();
    m_statusBar = new CStatusBar();

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_titleBar);
    m_layout->addWidget(m_navigateBar);
    m_layout->addWidget(m_statusBar);
    setLayout(m_layout);
}

void CMainWindow::initConnect()
{

}
