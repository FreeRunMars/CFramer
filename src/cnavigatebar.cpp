#include "cnavigatebar.h"

CNavigateBar::CNavigateBar(QWidget *parent) : QFrame(parent)
{
    initUi();
}

void CNavigateBar::initUi()
{
    this->setMinimumHeight(60);
    this->setMaximumHeight(60);
    this->setStyleSheet("background-color:lightblue;");
}
