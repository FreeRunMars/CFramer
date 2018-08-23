#include "ctitlebar.h"

CTitleBar::CTitleBar(QWidget *parent) : QFrame(parent)
{
    initData();
    initUi();
    initConnect();
}

void CTitleBar::setTitleFlag(CTitleBar::titleFlag flag)
{

}

void CTitleBar::setTitleContent(const QString &title, int titleFontSize)
{

}

QString CTitleBar::getTitleContent()
{

}

void CTitleBar::setTitleIcon(const QString &filePath, const QSize iconSize)
{

}

void CTitleBar::addButton(QPushButton *btn)
{

}

void CTitleBar::setTitleBarHeight(const int h)
{

}

int CTitleBar::getTitleBarHeight()
{

}

void CTitleBar::setTitleBarWidth(const int w)
{

}

int CTitleBar::getTitleBarWidth()
{

}

void CTitleBar::onCloseButtonClicked()
{
    qDebug() << "closeButtonClicked";
}

void CTitleBar::onMaxButtonClicked()
{

}

void CTitleBar::onRestoreButtonClicked()
{

}

void CTitleBar::onMinButtonClicked()
{

}

void CTitleBar::onSettingsButtonClicked()
{

}

void CTitleBar::onSkinButtonClicked()
{

}

void CTitleBar::onLogoButtonClicked()
{

}

void CTitleBar::onLoadStyleSheet(const QString &sheet)
{

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
    this->setFixedHeight(TITLE_HEIGHT);

    m_closeButton = new QPushButton(tr("X"));
    m_maxButton = new QPushButton;
    m_restoreButton = new QPushButton;
    m_minButton = new QPushButton;
    m_skinButton = new QPushButton;
    m_settingsButton = new QPushButton;
    m_logoButton = new QPushButton;
    m_titleLabel = new QLabel(tr("haha"));

    m_closeButton->setFixedSize(BUTTON_HEIGHT, BUTTON_HEIGHT);
    m_maxButton->setFixedSize(BUTTON_HEIGHT, BUTTON_HEIGHT);
    m_restoreButton->setFixedSize(BUTTON_HEIGHT, BUTTON_HEIGHT);
    m_minButton->setFixedSize(BUTTON_HEIGHT, BUTTON_HEIGHT);
    m_skinButton->setFixedSize(BUTTON_HEIGHT, BUTTON_HEIGHT);
    m_settingsButton->setFixedSize(BUTTON_HEIGHT, BUTTON_HEIGHT);
    m_logoButton->setFixedSize(BUTTON_HEIGHT, BUTTON_HEIGHT);
    m_titleLabel->setFixedHeight(BUTTON_HEIGHT);

    m_closeButton->setObjectName(tr("CloseButton"));
    m_maxButton->setObjectName(tr("MaxButton"));
    m_restoreButton->setObjectName(tr("RestoreButton"));
    m_minButton->setObjectName(tr("MinButton"));
    m_skinButton->setObjectName(tr("SkinButton"));
    m_settingsButton->setObjectName(tr("SettingsButton"));
    m_logoButton->setObjectName(tr("LogoButton"));
    m_titleLabel->setObjectName(tr("TitleLabel"));

    m_layout = new QHBoxLayout;
    m_layout->addWidget(m_logoButton);
    m_layout->addWidget(m_titleLabel);
    m_layout->addStretch();
    m_layout->addWidget(m_settingsButton);
    m_layout->addWidget(m_skinButton);
    m_layout->addWidget(m_minButton);
    m_layout->addWidget(m_restoreButton);
    m_layout->addWidget(m_maxButton);
    m_layout->addWidget(m_closeButton);

    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);
    this->setLayout(m_layout);

    this->setStyleSheet("CTitleBar{background-color:black;}"
                        "QLabel{background-color:black;color:white;}"
                        "QPushButton{background-color:black;color:white;border:none;}"
                        "QPushButton:hover{background-color:white;color:black;}"
                        "QPushButton:pressed{background-color:blue;color:black;}"
                        "QPushButton#CloseButton:hover{background-color:red;color:white;}"
                        "QPushButton#CloseButton:pressed{background-color:blue;color:black;}");
}

void CTitleBar::initConnect()
{
    connect(m_minButton, &QPushButton::clicked, this, &CTitleBar::onMinButtonClicked);
    connect(m_restoreButton, &QPushButton::clicked, this, &CTitleBar::onRestoreButtonClicked);
    connect(m_maxButton, &QPushButton::clicked, this, &CTitleBar::onMaxButtonClicked);
    connect(m_closeButton, &QPushButton::clicked, this, &CTitleBar::onCloseButtonClicked);
}

void CTitleBar::initData()
{
    m_moving = false;
}
