#ifndef CSHADOWLABEL_H
#define CSHADOWLABEL_H

#include <QLabel>

class cShadowLabel : public QLabel {
  Q_OBJECT

 public:
  explicit cShadowLabel(QWidget* parent = nullptr);
  explicit cShadowLabel(const QString& text, QWidget* parent = nullptr);
};

#endif  // CSHADOWLABEL_H
