#ifndef CQTITLEBAR_H
#define CQTITLEBAR_H

#include <QFrame>
#include <QLabel>
#include "ctoolbutton.h"

#define DEFAULT_TITLE_HEIGHT 30
#define BUTTONNAME "titleToolButton"

class CQTitleBar : public QFrame {
  Q_OBJECT
 public:
  explicit CQTitleBar(QWidget* parent = nullptr);
  virtual ~CQTitleBar();

 private:
  QIcon* m_maxIcon;
  QIcon* m_normalIcon;
  QLabel* m_titleBarLabel;
  CToolButton* m_logoButton;
  CToolButton* m_settingButton;
  CToolButton* m_skinButton;
  CToolButton* m_lockButton;
  CToolButton* m_minButton;
  CToolButton* m_maxButton;
  CToolButton* m_closeButton;
  bool m_normal_max_flag;
  bool m_lock_flag;

 public:
  QString title;
  static CQTitleBar* instance;

  inline bool getLockFlag() { return m_lock_flag; }
  void setSettingMenu(QMenu* menu);

 private:
  void initUI();
  void initData();
  void initConnects();

 public:
  void setTitleHeight(const int& height);
  static CQTitleBar* getInstance();

  void setLogoButton(const char* str, const char* objectName = nullptr);
  CToolButton* getLogoButton();
  void setLogoButtonVisible(bool visible);
  bool isLogoButtonVisible();

  void setTitleLabel(QString str, const char* objectName = nullptr);
  QLabel* getTitleLabel();
  void setTitleLabelVisible(bool visible);
  bool isTitleLabelVisible();

  void setSettingButton(const char* str, const char* objectName = nullptr);
  CToolButton* getSettingButton();
  void setSettingButtonVisible(bool visible);
  bool isSettingButtonVisible();

  void setSkinButton(const char* str, const char* objectName = nullptr);
  CToolButton* getSkinButton();
  void setSkinButtonVisible(bool visible);
  bool isSkinButtonVisible();

  void setLockButton(const char* str, const char* objectName = nullptr);
  CToolButton* getLockButton();
  void setLockButtonVisible(bool visible);
  bool isLockButtonVisible();

  void setMinButton(const char* str, const char* objectName = nullptr);
  CToolButton* getMinButton();
  void setMinButtonVisible(bool visible);
  bool isMinButtonVisible();

  void setMaxButton(const char* str, const char* objectName = nullptr);
  CToolButton* getMaxButton();
  void setMaxButtonVisible(bool visible);
  bool isMaxButtonVisible();

  void setCloseButton(const char* str, const char* objectName = nullptr);
  CToolButton* getCloseButton();
  void setCloseButtonVisible(bool visible);
  bool isCloseButtonVisible();

 signals:
  void closed();
  void maximuned();
  void minimuned();

 public slots:
  void switchMaxMin();
  void clearChecked();
  void changeLock();
};

#endif  // CQTITLEBAR_H
