#include "cstatusbar.h"

CStatusBar::CStatusBar(QWidget *parent) : QFrame(parent)
{
    initUi();
}

void CStatusBar::initUi()
{
    this->setFixedHeight(30);
    this->setStyleSheet("background-color:lightgreen;");
}

void CStatusBar::initConnect()
{

}
