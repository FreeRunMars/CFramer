#include "ccenterframe.h"

CCenterFrame::CCenterFrame(QWidget *parent) : QFrame(parent)
{
    initUi();
    initConnect();
}

void CCenterFrame::initUi()
{
    m_titleBar = new CTitleBar(this);
    m_navigateBar = new CNavigateBar(this);
    m_pageFrame = new CPageFrame(this);
    m_statusBar = new CStatusBar(this);

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0,0,0,0);
    m_layout->setSpacing(0);

    m_layout->addWidget(m_titleBar);
    m_layout->addWidget(m_navigateBar);
    m_layout->addWidget(m_pageFrame);
    m_layout->addWidget(m_statusBar);
    setLayout(m_layout);
}

void CCenterFrame::initConnect()
{

}
