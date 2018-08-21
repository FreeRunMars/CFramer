#ifndef CTOOLBUTTON_H
#define CTOOLBUTTON_H

#include <QMenu>
#include <QToolButton>

class CToolButton : public QToolButton {
 public:
  CToolButton();

  void setMenu(QMenu *menu);
 private slots:
  void recover();
};

#endif  // CTOOLBUTTON_H
