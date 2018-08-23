#include "cshadowlabel.h"
#include <QGraphicsDropShadowEffect>

cShadowLabel::cShadowLabel(QWidget *parent) : QLabel(parent) {
  QGraphicsDropShadowEffect *shadow_effect =
      new QGraphicsDropShadowEffect(this);
  shadow_effect->setOffset(-5, 5);
  shadow_effect->setColor(Qt::darkGreen);
  shadow_effect->setBlurRadius(8);
  setGraphicsEffect(shadow_effect);
}

cShadowLabel::cShadowLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent) {
  QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect();
  shadow_effect->setOffset(-5, 5);
  shadow_effect->setColor(Qt::darkGreen);
  shadow_effect->setBlurRadius(8);
  setGraphicsEffect(shadow_effect);
}
