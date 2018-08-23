#ifndef CNAVIGATEWIDGET_H
#define CNAVIGATEWIDGET_H

#include "cnavigatebar.h"

#include <QFrame>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>

class CNavigateWidget : public QFrame
{
public:
    enum NavigateBarPosition{ North, South, East, West };
    enum NavigateBarStyle{ Mid, Right, Left };

    explicit CNavigateWidget(QWidget *parent);


    int addNavigation(QWidget *page, const QString &label);
    int addNavigation(QWidget *page, const QIcon &, const QString &label);

    bool setNavigateBar(CNavigateBar *naviBar);
    CNavigateBar* getNavigateBar();

signals:

public slots:

private:
    void initUi();
    void initConnect();
    void initData();

    CNavigateBar *m_navigateBar;
    QStackedWidget *m_stackWidget;
    QVBoxLayout *m_layout;
};

#endif // CNAVIGATEWIDGET_H
