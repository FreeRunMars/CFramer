#include "ctitlebar.h"

CTitleBar::CTitleBar(QWidget *parent) : QFrame(parent)
{
    initData();
    initUi();
}

void CTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton && m_moving)
    {
        this->window()->move(event->globalPos() - m_relativeDragPoint);
        event->accept();
    }
}

void CTitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        m_moving = true;
        m_pressPoint = event->globalPos();
        m_relativeDragPoint = event->globalPos() - this->window()->pos();
        event->accept();
    }
}

void CTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_moving = false;
    event->accept();
}

void CTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(this->window()->windowState() == Qt::WindowMaximized){
        this->window()->showNormal();
    }else{
        this->window()->showMaximized();
    }
    event->accept();
}

void CTitleBar::initUi()
{
    this->setMinimumHeight(30);
    this->setMaximumHeight(30);
    this->setStyleSheet("background-color:black;");
}

void CTitleBar::initConnect()
{

}

void CTitleBar::initData()
{
    m_moving = false;
}
