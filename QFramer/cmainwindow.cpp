#include "cmainwindow.h"
#include <QDebug>
#include <QStatusBar>

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
  qDebug("mainwindow init");
  initData();
  initUI();
  initConnects();
}

void CMainWindow::setStatusBarHeight(const int &height) {
  // in my appalication I define the status's height is less than 1/10 of the
  // current height of mainwindow.
  if (height < STATUSBARMINHEIGHT || height > this->height() / 10) {
    m_statusBar->setFixedHeight(STATUSBARMINHEIGHT);
    return;
  }

  m_statusBar->setFixedHeight(height);
}

void CMainWindow::initData() {}

void CMainWindow::initUI() {
  m_titleBar = CQTitleBar::getInstance();
  m_titleBar->setTitleHeight(25);
  m_titleBar->show();

  m_statusBar = new QStatusBar();
  m_statusBar->setFixedHeight(STATUSBARMINHEIGHT);
  setStatusBar(m_statusBar);
  setObjectName(QString("CMainWindow"));

  setWindowFlags(Qt::FramelessWindowHint);
  setWindowTitle("CFramer");
}

void CMainWindow::initConnects() {}
