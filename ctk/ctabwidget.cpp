#include "ctabwidget.h"

CTabWidget::CTabWidget(QWidget *parent) : QFrame(parent)
{
    initUi();
    initConnect();
}

void CTabWidget::initUi()
{
    m_tabBar = new CTabBar(this);
    m_stackWidget = new QStackedWidget(this);
    m_stackWidget->setStyleSheet("backgound-color:lightgray");

    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0,0,0,0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_tabBar);
    m_layout->addWidget(m_stackWidget);
    setLayout(m_layout);
}

void CTabWidget::initConnect()
{

}
