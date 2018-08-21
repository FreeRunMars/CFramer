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
    CCenterFrame *centerFrame = new CCenterFrame(this);
    this->setCentralWidget(centerFrame);
}

void CMainWindow::initConnect()
{

}
