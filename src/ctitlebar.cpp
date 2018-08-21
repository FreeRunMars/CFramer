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
        QPoint widgetOldPos;
        QPoint mousePos = event->globalPos();
        int mouseRelativeX = mousePos.x() - m_lastMousePos.x();
        int mouseRelativeY = mousePos.y() - m_lastMousePos.y();
        qDebug() << "mouse pos: " << mousePos
                 << "last mouse pos: " << m_lastMousePos
                 << "relative x: " << mouseRelativeX
                 << "relative y: " << mouseRelativeY;

        QWidget *parentWidget = this->parentWidget();
        qDebug() << "titleBar's parentWidget: " << parentWidget;
        if(parentWidget){
            QWidget *grandParent = parentWidget->parentWidget();
            qDebug() << "titleBar's grandParent: " << grandParent;
            if(grandParent){
                widgetOldPos = grandParent->pos();
                qDebug() << "grandParentPos before move: " << widgetOldPos;
                grandParent->move(widgetOldPos.x() + mouseRelativeX,
                                  widgetOldPos.y() + mouseRelativeY);
                qDebug() << "grandParentPos after move: " << grandParent->pos();
            }else{
                widgetOldPos = parentWidget->pos();
                qDebug() << "parentPos before move: " << widgetOldPos;
                parentWidget->move(widgetOldPos.x() + mouseRelativeX,
                                   widgetOldPos.y() + mouseRelativeY);
                qDebug() << "parentPos after move: " << parentWidget->pos();
            }
        }else{
            widgetOldPos = this->pos();
            qDebug() << "titleBar before move: " << widgetOldPos;
            this->move(widgetOldPos.x() + mouseRelativeX,
                       widgetOldPos.y() + mouseRelativeY);
            qDebug() << "titleBar after move: " << this->pos();
        }
        m_lastMousePos = mousePos;
    }
}

void CTitleBar::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "titleBar mousePressEvent";
    if(event->buttons() == Qt::LeftButton)
    {
        m_moving = true;
        m_pressedPoint = event->globalPos();
        m_lastMousePos = m_pressedPoint;
        qDebug() << "titleBar mousePressEvent pressedPoint: " << m_pressedPoint;
    }
}

void CTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "titleBar mouseReleaseEvent";
    m_moving = false;
    qDebug() << "titleBar mousePressEvent releasedPoint: " << event->globalPos();
}

void CTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "titleBar mouseDoubleClickEvent";

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
