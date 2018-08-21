#include "cnavigatebar.h"

CNavigateBar::CNavigateBar(QWidget *parent) : QFrame(parent)
{
    initUi();
}

void CNavigateBar::initUi()
{
    this->setFixedHeight(60);
    this->setStyleSheet("background-color:lightblue;");
}
