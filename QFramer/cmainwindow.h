#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "cqtitlebar.h"

#define STATUSBARMINHEIGHT 30

class QStatusBar;

class CMainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit CMainWindow(QWidget *parent = nullptr);

  void setStatusBarHeight(const int &height);

 private:
  CQTitleBar *m_titleBar;
  QStatusBar *m_statusBar;

 private:
  void initData();
  void initUI();
  void initConnects();
 signals:

 public slots:
};

#endif  // CMAINWINDOW_H
