#ifndef CTITLEBAR_H
#define CTITLEBAR_H

#include <QFrame>
#include <QLabel>
#include "ctoolbutton.h"

#define DEFAULT_TITLE_HEIGHT 30
#define BUTTONNAME "titleToolButton"

class CTitleBar : public QFrame {
 public:
  explicit CTitleBar(QWidget* parent = nullptr);
  ~CTitleBar();

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
  bool m_nomal_max_flag;
  bool m_lock_flag;

 public:
  QString title;
  static CTitleBar* instance;

  inline bool getLockFlag() { return m_lock_flag; }
  void setSettingMenu(QMenu* menu);

 public:
  void setTitleHeight(const int& height);
  static CTitleBar* getInstance();

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

 private:
  void initUI();
  void initData();
  void initConnects();
};

#endif  // CTITLEBAR_H
