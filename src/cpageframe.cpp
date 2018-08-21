#include "cpageframe.h"

CPageFrame::CPageFrame(QWidget *parent) : QFrame(parent)
{
    initUi();
    initConnect();
}

void CPageFrame::initUi()
{
    //this->setAutoFillBackground(true);
    this->setStyleSheet("background-color:lightgrey;");
}

void CPageFrame::initConnect()
{

}
