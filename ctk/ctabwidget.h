#ifndef CTABWIDGET_H
#define CTABWIDGET_H

#include "ctabbar.h"

#include <QFrame>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>

class CTabWidget : public QFrame
{
public:
    enum TabBarPosition{ North, South, East, West };
    enum TabBarStyle{ Mid, Right, Left };

    explicit CTabWidget(QWidget *parent);

    int addPage(QWidget *page, const QString &label);
    int addPage(QWidget *page, const QIcon &, const QString &label);

    bool setTabBar(CTabBar *naviBar);
    CTabBar* getTabBar();

signals:

public slots:

private:
    void initUi();
    void initConnect();
    void initData();

    CTabBar *m_tabBar;
    QStackedWidget *m_stackWidget;
    QVBoxLayout *m_layout;
};

#endif // CTABWIDGET_H
