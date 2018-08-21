#include "ctitlebar.h"

CTitleBar::CTitleBar(QWidget *parent) : QFrame(parent)
{
    initData();
    initUi();
}

void CTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "titleBar mouseMoveEvent";
    if(event->buttons() == Qt::LeftButton && m_moving)
    {
        QWidget *parentWidget = this->parentWidget();
        qDebug() << "titleBar's parentWidget: " << parentWidget;
        if(parentWidget){
            QWidget *grandParent = parentWidget->parentWidget();
            qDebug() << "titleBar's grandParent: " << grandParent;
            if(grandParent){
                qDebug() << "grandParentPos before move: " << grandParent->pos();
                grandParent->move(event->globalPos());
                qDebug() << "grandParentPos after move: " << grandParent->pos();
                qDebug() << "mouse pos: " << event->globalPos();
            }else{
                qDebug() << "parentPos before move: " << parentWidget->pos();
                parentWidget->move(event->globalPos());
                qDebug() << "parentPos after move: " << parentWidget->pos();
                qDebug() << "mouse pos: " << event->globalPos();
            }
        }else{
            qDebug() << "titleBar before move: " << this->pos();
            this->move(event->globalPos());
            qDebug() << "titleBar after move: " << this->pos();
            qDebug() << "mouse pos: " << event->globalPos();
        }
    }
}

void CTitleBar::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "titleBar mousePressEvent";
    if(event->buttons() == Qt::LeftButton)
    {
        m_moving = true;
        m_pressedPoint = event->globalPos();
        qDebug() << "titleBar mousePressEvent pressedPoint: " << m_pressedPoint;
    }
}

void CTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "titleBar mouseReleaseEvent";
    m_moving = false;
    qDebug() << "titleBar mousePressEvent releasedPoint: " << event->globalPos();
}

void CTitleBar::initUi()
{
    this->setFixedHeight(30);
    this->setStyleSheet("background-color:black;");
}

void CTitleBar::initConnect()
{

}

void CTitleBar::initData()
{
    m_moving = false;
}
