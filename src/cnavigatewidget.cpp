#include "cnavigatewidget.h"

CNavigateWidget::CNavigateWidget(QWidget *parent) : QFrame(parent)
{
    initUi();
    initConnect();
}

void CNavigateWidget::initUi()
{
    m_navigateBar = new CNavigateBar(this);
    m_stackWidget = new QStackedWidget(this);
    m_stackWidget->setStyleSheet("backgound-color:lightgray");

    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0,0,0,0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_navigateBar);
    m_layout->addWidget(m_stackWidget);
    setLayout(m_layout);
}

void CNavigateWidget::initConnect()
{

}
