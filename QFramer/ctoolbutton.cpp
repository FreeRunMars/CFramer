#include "ctoolbutton.h"
#include <QCursor>

CToolButton::CToolButton() {}

void CToolButton::setMenu(QMenu *menu) {
  connect(menu, SIGNAL(aboutToHide()), this, SLOT(recover()));
  QToolButton::setMenu(menu);
}

void CToolButton::recover() {
// on clicked , check the cursor position to show menu
#ifdef Q_OS_LINUX
  bool flag = this->rect().contains(this->mapFromGlobal(QCursor::pos()));
  this->setAttribute(Qt::WA_UnderMouse, flag);
  this->update();
#endif
}
