#ifndef CICONBUTTON_H
#define CICONBUTTON_H

#include <QPushButton>

namespace CButtons {
class CIconButton;
struct DEFAULT_BUTTON_SHADOW {
  DEFAULT_BUTTON_SHADOW() : offset(-5, 5), blurRadius(6), color(Qt::gray) {}
  const QPointF offset;
  const qreal blurRadius;
  const QColor color;
};
}

class QGraphicsDropShadowEffect;
class QMenu;

class CIconButton : public QPushButton {
  Q_OBJECT

 public:
  explicit CIconButton(QWidget* parent = nullptr);
  CIconButton();

  void setShadowEffect(QGraphicsDropShadowEffect* shadow_effect);
  void setShadowEffect(const QPointF& offset, const qreal& blurRadius,
                       const QColor& color);
  void setShadowEffect(const qreal& xoffset, const qreal& yoffset,
                       const qreal& blurRadius, const QColor& color);

  void setMenu(QMenu* menu);

  inline const bool& getShadowFlag() { return m_shadowFlag; }
  inline void setShadowFlag(bool flag) { m_shadowFlag = flag; }

 private:
  QGraphicsDropShadowEffect* m_shadow_effect;
  bool m_shadowFlag;

 public slots:
  void hideOrNotShadow(bool flag);

 private:
  void InitUI();
  void InitData();
  void InitConnect();

 public:
  void recover();
};

#endif  // CICONBUTTON_H
