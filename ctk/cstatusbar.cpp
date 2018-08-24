#include "cstatusbar.h"

CStatusBar::CStatusBar(QWidget *parent) : QFrame(parent)
{
    initUi();
}

void CStatusBar::initUi()
{
    this->setMinimumHeight(30);
    this->setMaximumHeight(30);
    this->setStyleSheet("background-color:lightgreen;");
}

void CStatusBar::initConnect()
{

}
