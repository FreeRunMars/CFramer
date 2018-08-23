#include "cqtitlebar.h"
#include <QDebug>
#include <QHBoxLayout>

CQTitleBar *CQTitleBar::instance = nullptr;

CQTitleBar::CQTitleBar(QWidget *parent) : QFrame(parent) {
  initData();
  initUI();
  initConnects();
  m_lockButton->click();
}

CQTitleBar::~CQTitleBar() {}

void CQTitleBar::setSettingMenu(QMenu *menu) { m_settingButton->setMenu(menu); }

void CQTitleBar::initUI() {
  setTitleHeight(DEFAULT_TITLE_HEIGHT);
  setObjectName(QString("CTitleBar"));
  setLogoButton(":/images/skin/images/QFramer.png");
  setTitleLabel(tr("CFramer"), "CTitleLabel");
  setSettingButton(":/skin/icons/dark/appbar.control.down.png");
  setSkinButton(":/skin/icons/dark/appbar.clothes.shirt.png");
  setLockButton(":/skin/icons/dark/appbar.lock.png");
  setMinButton(":/skin/icons/dark/appbar.minus.png");
  setMaxButton(":/skin/icons/dark/appbar.app.png");
  setCloseButton(":/skin/icons/dark/appbar.close.png");

  QHBoxLayout *barLayout = new QHBoxLayout;
  barLayout->addWidget(m_logoButton);
  barLayout->addWidget(m_titleBarLabel);
  barLayout->addStretch();
  barLayout->addWidget(m_settingButton);
  barLayout->addWidget(m_skinButton);
  barLayout->addWidget(m_lockButton);
  barLayout->addWidget(m_minButton);
  barLayout->addWidget(m_maxButton);
  barLayout->addWidget(m_closeButton);
  barLayout->setContentsMargins(0, 0, 5, 0);
  barLayout->addSpacing(0);
  setLayout(barLayout);
  setWindowFlags(Qt::FramelessWindowHint);
}

void CQTitleBar::initData() {
  title = tr("");
  m_logoButton = new CToolButton();
  m_logoButton->setObjectName(QString(BUTTONNAME));
  m_logoButton->setFocusPolicy(Qt::NoFocus);
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

  m_normal_max_flag = true;
  m_lock_flag = false;
  m_maxIcon = new QIcon(QString(":/skin/icons/dark/appbar.fullscreen.box.png"));
  m_normalIcon = new QIcon(QString(":/skin/icons/dark/appbar.app.png"));
}

void CQTitleBar::initConnects() {
  connect(m_settingButton, SIGNAL(clicked()), m_settingButton,
          SLOT(showMenu()));
  connect(m_skinButton, SIGNAL(clicked()), m_skinButton, SLOT(showMenu()));
  connect(m_lockButton, SIGNAL(clicked()), this, SLOT(changeLock()));
  connect(m_minButton, SIGNAL(clicked()), this, SIGNAL(minimuned()));
  connect(m_maxButton, SIGNAL(clicked()), this, SIGNAL(maximuned()));
  connect(m_closeButton, SIGNAL(clicked()), this, SIGNAL(closed()));
  connect(m_maxButton, SIGNAL(clicked()), this, SLOT(switchMaxMin()));
}

void CQTitleBar::setTitleHeight(const int &height) {
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
    // qDebug() << "title use the default height. " << DEFAULT_TITLE_HEIGHT;
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

CQTitleBar *CQTitleBar::getInstance() {
  if (!instance) {
    instance = new CQTitleBar();
  }
  return instance;
}

void CQTitleBar::setLogoButton(const char *str, const char *objectName) {
  m_logoButton->setIcon(QIcon(QString(str)));
  m_logoButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_logoButton->setObjectName(QString(objectName));
  }
}

CToolButton *CQTitleBar::getLogoButton() { return m_logoButton; }

void CQTitleBar::setLogoButtonVisible(bool visible) {
  m_logoButton->setVisible(visible);
}

bool CQTitleBar::isLogoButtonVisible() { return m_logoButton->isVisible(); }

void CQTitleBar::setTitleLabel(QString str, const char *objectName) {
  m_titleBarLabel->setText(str);
  m_titleBarLabel->setFixedHeight(height());
  if (objectName) {
    m_titleBarLabel->setObjectName(QString(objectName));
  }
}

QLabel *CQTitleBar::getTitleLabel() { return m_titleBarLabel; }

void CQTitleBar::setTitleLabelVisible(bool visible) {
  m_titleBarLabel->setVisible(visible);
}

bool CQTitleBar::isTitleLabelVisible() { return m_titleBarLabel->isVisible(); }

void CQTitleBar::setSettingButton(const char *str, const char *objectName) {
  m_settingButton->setIcon(QIcon(QString(str)));
  m_settingButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_settingButton->setObjectName(QString(objectName));
  }
}

CToolButton *CQTitleBar::getSettingButton() { return m_settingButton; }

void CQTitleBar::setSettingButtonVisible(bool visible) {
  m_settingButton->setVisible(visible);
}

bool CQTitleBar::isSettingButtonVisible() {
  return m_settingButton->isVisible();
}

void CQTitleBar::setSkinButton(const char *str, const char *objectName) {
  m_skinButton->setIcon(QIcon(QString(str)));
  m_skinButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_skinButton->setObjectName(QString(objectName));
  }
}

CToolButton *CQTitleBar::getSkinButton() { return m_skinButton; }

void CQTitleBar::setSkinButtonVisible(bool visible) {
  m_skinButton->setVisible(visible);
}

bool CQTitleBar::isSkinButtonVisible() { return m_skinButton->isVisible(); }

void CQTitleBar::setLockButton(const char *str, const char *objectName) {
  m_lockButton->setIcon(QIcon(QString(str)));
  m_lockButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_lockButton->setObjectName(QString(objectName));
  }
}

CToolButton *CQTitleBar::getLockButton() { return m_lockButton; }

void CQTitleBar::setLockButtonVisible(bool visible) {
  m_lockButton->setVisible(visible);
}

bool CQTitleBar::isLockButtonVisible() { return m_lockButton->isVisible(); }

void CQTitleBar::setMinButton(const char *str, const char *objectName) {
  m_minButton->setIcon(QIcon(QString(str)));
  m_minButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_minButton->setObjectName(QString(objectName));
  }
}

CToolButton *CQTitleBar::getMinButton() { return m_minButton; }

void CQTitleBar::setMinButtonVisible(bool visible) {
  m_minButton->setVisible(visible);
}

bool CQTitleBar::isMinButtonVisible() { return m_minButton->isVisible(); }

void CQTitleBar::setMaxButton(const char *str, const char *objectName) {
  m_maxButton->setIcon(QIcon(QString(str)));
  m_maxButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_maxButton->setObjectName(objectName);
  }
}

void CQTitleBar::setCloseButton(const char *str, const char *objectName) {
  m_closeButton->setIcon(QIcon(QString(str)));
  m_closeButton->setIconSize(QSize(height(), height()));
  if (objectName) {
    m_closeButton->setObjectName(objectName);
  }
}

void CQTitleBar::switchMaxMin() {
  if (m_normal_max_flag) {
    m_maxButton->setIcon(*m_maxIcon);
    m_normal_max_flag = false;
  } else {
    m_maxButton->setIcon(*m_normalIcon);
    m_normal_max_flag = true;
  }
}

void CQTitleBar::clearChecked() {
  m_settingButton->setChecked(false);
  m_skinButton->setChecked(false);
  m_lockButton->setChecked(false);
  m_minButton->setChecked(false);
  m_maxButton->setChecked(false);
  m_closeButton->setChecked(false);
}

void CQTitleBar::changeLock() {
  if (m_lock_flag) {
    m_lockButton->setIcon(QIcon(":/skin/icons/dark/appbar.lock.png"));
  } else {
    m_lockButton->setIcon(QIcon(":/skin/icons/dark/appbar.unlock.keyhole.png"));
  }

  m_lock_flag = not m_lock_flag;
}
