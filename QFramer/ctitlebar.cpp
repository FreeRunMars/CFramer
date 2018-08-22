#include "ctitlebar.h"
#include <QDebug>
#include <QHBoxLayout>
#include "ctoolbutton.h"

CTitleBar *CTitleBar::instance = nullptr;

CTitleBar::CTitleBar(QWidget *parent) : QFrame(parent) {
  initData();
  initUI();
  initConnects();
}

CTitleBar::~CTitleBar() {}

void CTitleBar::setTitleHeight(const int &height) {
  if (height < DEFAULT_TITLE_HEIGHT || height >= 200) {
    setFixedHeight(DEFAULT_TITLE_HEIGHT);
    m_titleBarLabel->setFixedHeight(DEFAULT_TITLE_HEIGHT);
    m_logoButton->setIconSize(
        QSize(DEFAULT_TITLE_HEIGHT, DEFAULT_TITLE_HEIGHT));
    m_settingButton->setIconSize(
        QSize(DEFAULT_TITLE_HEIGHT, DEFAULT_TITLE_HEIGHT));
    m_skinButton->setIconSize(
        QSize(DEFAULT_TITLE_HEIGHT, DEFAULT_TITLE_HEIGHT));
    m_lockButton->setIconSize(
        QSize(DEFAULT_TITLE_HEIGHT, DEFAULT_TITLE_HEIGHT));
    m_minButton->setIconSize(QSize(DEFAULT_TITLE_HEIGHT, DEFAULT_TITLE_HEIGHT));
    m_maxButton->setIconSize(QSize(DEFAULT_TITLE_HEIGHT, DEFAULT_TITLE_HEIGHT));
    m_closeButton->setIconSize(
        QSize(DEFAULT_TITLE_HEIGHT, DEFAULT_TITLE_HEIGHT));
    qDebug() << "title use the default height. " << DEFAULT_TITLE_HEIGHT;
    return;
  }

  m_titleBarLabel->setFixedHeight(height);
  m_logoButton->setIconSize(QSize(height, height));
  m_settingButton->setIconSize(QSize(height, height));
  m_skinButton->setIconSize(QSize(height, height));
  m_lockButton->setIconSize(QSize(height, height));
  m_minButton->setIconSize(QSize(height, height));
  m_maxButton->setIconSize(QSize(height, height));
  m_closeButton->setIconSize(QSize(height, height));
  this->update();
}

void CTitleBar::setSettingMenu(QMenu *menu) { m_settingButton->setMenu(menu); }

CTitleBar *CTitleBar::getInstance() {
  if (!instance) {
    instance = new CTitleBar();
  }
  return instance;
}

void CTitleBar::setLogoButton(const char *str, const char *objectName) {
  m_logoButton->setIcon(QIcon(QString(str)));
  m_logoButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_logoButton->setObjectName(QString(objectName));
  }
}

CToolButton *CTitleBar::getLogoButton() { return m_logoButton; }

void CTitleBar::setLogoButtonVisible(bool visible) {
  m_logoButton->setVisible(visible);
}

bool CTitleBar::isLogoButtonVisible() { return m_logoButton->isVisible(); }

void CTitleBar::setTitleLabel(QString str, const char *objectName) {
  m_titleBarLabel->setText(str);
  m_titleBarLabel->setFixedHeight(height());
  if (objectName) {
    m_titleBarLabel->setObjectName(QString(objectName));
  }
}

QLabel *CTitleBar::getTitleLabel() { return m_titleBarLabel; }

void CTitleBar::setTitleLabelVisible(bool visible) {
  m_titleBarLabel->setVisible(visible);
}

bool CTitleBar::isTitleLabelVisible() { return m_titleBarLabel->isVisible(); }

void CTitleBar::setSettingButton(const char *str, const char *objectName) {
  m_settingButton->setIcon(QIcon(QString(str)));
  m_settingButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_settingButton->setObjectName(QString(objectName));
  }
}

CToolButton *CTitleBar::getSettingButton() { return m_settingButton; }

void CTitleBar::setSettingButtonVisible(bool visible) {
  m_settingButton->setVisible(visible);
}

bool CTitleBar::isSettingButtonVisible() {
  return m_settingButton->isVisible();
}

void CTitleBar::setSkinButton(const char *str, const char *objectName) {
  m_skinButton->setIcon(QIcon(QString(str)));
  m_skinButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_skinButton->setObjectName(QString(objectName));
  }
}

CToolButton *CTitleBar::getSkinButton() { return m_skinButton; }

void CTitleBar::setSkinButtonVisible(bool visible) {
  m_skinButton->setVisible(visible);
}

bool CTitleBar::isSkinButtonVisible() { return m_skinButton->isVisible(); }

void CTitleBar::setLockButton(const char *str, const char *objectName) {
  m_lockButton->setIcon(QIcon(QString(str)));
  m_lockButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_lockButton->setObjectName(QString(objectName));
  }
}

CToolButton *CTitleBar::getLockButton() { return m_lockButton; }

void CTitleBar::setLockButtonVisible(bool visible) {
  m_lockButton->setVisible(visible);
}

bool CTitleBar::isLockButtonVisible() { return m_lockButton->isVisible(); }

void CTitleBar::setMinButton(const char *str, const char *objectName) {
  m_minButton->setIcon(QIcon(QString(str)));
  m_minButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_minButton->setObjectName(QString(objectName));
  }
}

CToolButton *CTitleBar::getMinButton() { return m_minButton; }

void CTitleBar::setMinButtonVisible(bool visible) {
  m_minButton->setVisible(visible);
}

bool CTitleBar::isMinButtonVisible() { return m_minButton->isVisible(); }

void CTitleBar::setMaxButton(const char *str, const char *objectName) {
  m_maxButton->setIcon(QIcon(QString(str)));
  m_maxButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_maxButton->setObjectName(objectName);
  }
}

CToolButton *CTitleBar::getMaxButton() { return m_maxButton; }

void CTitleBar::setMaxButtonVisible(bool visible) {
  m_maxButton->setVisible(visible);
}

bool CTitleBar::isMaxButtonVisible() { return m_maxButton->isVisible(); }

void CTitleBar::setCloseButton(const char *str, const char *objectName) {
  m_closeButton->setIcon(QIcon(QString(str)));
  m_closeButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_closeButton->setObjectName(objectName);
  }
}

CToolButton *CTitleBar::getCloseButton() { return m_closeButton; }

void CTitleBar::setCloseButtonVisible(bool visible) {
  m_closeButton->setVisible(visible);
}

bool CTitleBar::isCloseButtonVisible() { return m_closeButton->isVisible(); }

void CTitleBar::initUI() {
  setTitleHeight(DEFAULT_TITLE_HEIGHT);
  setObjectName(QString("CTitleBar"));
}

void CTitleBar::initData() {
  title = tr("");
  m_logoButton = new CToolButton();
  m_logoButton->setObjectName(QString(BUTTONNAME));
  m_lockButton->setFocusPolicy(Qt::NoFocus);
  m_titleBarLabel = new QLabel;
  m_settingButton = new CToolButton();
  m_settingButton->setFocusPolicy(Qt::NoFocus);
  m_settingButton->setObjectName(QString(BUTTONNAME));
  m_skinButton = new CToolButton();
  m_skinButton->setObjectName(QString(BUTTONNAME));
  m_skinButton->setFocusPolicy(Qt::NoFocus);
  m_lockButton = new CToolButton();
  m_lockButton->setObjectName(QString(BUTTONNAME));
  m_lockButton->setFocusPolicy(Qt::NoFocus);
  m_minButton = new CToolButton();
  m_minButton->setObjectName(QString(BUTTONNAME));
  m_minButton->setFocusPolicy(Qt::NoFocus);
  m_maxButton = new CToolButton();
  m_maxButton->setObjectName(QString(BUTTONNAME));
  m_maxButton->setFocusPolicy(Qt::NoFocus);
  m_closeButton = new CToolButton();
  m_closeButton->setObjectName(QString(BUTTONNAME));
  m_closeButton->setFocusPolicy(Qt::NoFocus);

  m_nomal_max_flag = true;
  m_lock_flag = false;
  m_maxIcon = new QIcon(QString(":/skin/icons/dark/appbar.fullscreen.box.png"));
  m_normalIcon = new QIcon(QString(":/skin/icons/dark/appbar.app.png"));
}

void CTitleBar::initConnects() {}
