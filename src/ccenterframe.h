#ifndef CCENTERFRAME_H
#define CCENTERFRAME_H

#include "cnavigatebar.h"
#include "cpageframe.h"

#include <QFrame>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <>
#include <QPushButton>

class CCenterFrame : public QFrame
{
public:
    explicit CCenterFrame(QWidget *parent);

    bool addPage(QString pageName, QWidget *page);
    QWidget* findPage();
    bool remove(QString pageName);

signals:

public slots:

private:
    CNavigateBar *m_navigateBar;
    CPageFrame *m_pageFrame;
    QVBoxLayout *m_layout;
    QPushButton *m_homePageButton;
    QPushButton *m_aboutPageButton;

    void initUi();
    void initConnect();
    void initData();
};

#endif // CCENTERFRAME_H
