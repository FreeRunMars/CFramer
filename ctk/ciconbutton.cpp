#include "ciconbutton.h"
#include <QGraphicsDropShadowEffect>
#include <QMenu>

CIconButton::CIconButton(QWidget *parent) : QPushButton(parent) {
  InitData();
  InitUI();
  InitConnect();
}

CIconButton::CIconButton() {}

void CIconButton::setShadowEffect(QGraphicsDropShadowEffect *shadow_effect) {
  m_shadow_effect = shadow_effect;
}

void CIconButton::setShadowEffect(const QPointF &offset,
                                  const qreal &blurRadius,
                                  const QColor &color) {
  if (m_shadow_effect != nullptr) {
    m_shadow_effect->setOffset(offset);
    m_shadow_effect->setBlurRadius(blurRadius);
    m_shadow_effect->setColor(color);

    return;
  }

  m_shadow_effect = new QGraphicsDropShadowEffect();
  m_shadow_effect->setOffset(offset);
  m_shadow_effect->setBlurRadius(blurRadius);
  m_shadow_effect->setColor(color);
}

void CIconButton::setShadowEffect(const qreal &xoffset, const qreal &yoffset,
                                  const qreal &blurRadius,
                                  const QColor &color) {
  if (m_shadow_effect != nullptr) {
    m_shadow_effect->setOffset(xoffset, yoffset);
    m_shadow_effect->setBlurRadius(blurRadius);
    m_shadow_effect->setColor(color);
  }

  m_shadow_effect = new QGraphicsDropShadowEffect();
  m_shadow_effect->setOffset(xoffset, yoffset);
  m_shadow_effect->setBlurRadius(blurRadius);
  m_shadow_effect->setColor(color);
}

void CIconButton::setMenu(QMenu *menu) {
  connect(menu, SIGNAL(aboutToHide()), this, SLOT(recover()));
  QPushButton::setMenu(menu);
}

void CIconButton::hideOrNotShadow(bool flag) {
  if (flag) {
    setGraphicsEffect(m_shadow_effect);
    return;
  }

  setGraphicsEffect(nullptr);
}

void CIconButton::InitUI() {
  // initialiate the default shadow.
  m_shadow_effect->setOffset(-5, 5);
  m_shadow_effect->setColor(Qt::gray);
  m_shadow_effect->setBlurRadius(6);
  setGraphicsEffect(m_shadow_effect);
}

void CIconButton::InitData() {
  m_shadow_effect = new QGraphicsDropShadowEffect();
  m_shadowFlag = true;
}

void CIconButton::InitConnect() {}

void CIconButton::recover() {}
