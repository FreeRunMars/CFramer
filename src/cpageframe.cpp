#include "cpageframe.h"

CPageFrame::CPageFrame(QWidget *parent) : QFrame(parent)
{
    initUi();
    initConnect();
}

void CPageFrame::initUi()
{
    this->setFixedHeight(680);
    this->setStyleSheet("background-color:lightgrey;");
}

void CPageFrame::initConnect()
{

}
