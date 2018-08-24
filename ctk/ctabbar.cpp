#include "ctabbar.h"

CTabBar::CTabBar(QWidget *parent) : QFrame(parent)
{
    initUi();
}

void CTabBar::initUi()
{
    this->setMinimumHeight(60);
    this->setMaximumHeight(60);
    this->setStyleSheet("background-color:lightblue;");
}
