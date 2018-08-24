#ifndef CTABBAR_H
#define CTABBAR_H

#include <QFrame>
#include <QPushButton>

class CTabBar : public QFrame
{
    Q_OBJECT
public:
    explicit CTabBar(QWidget *parent);

signals:

public slots:

private:
    void initUi();
    void initConnect();
};

#endif // CTABBAR_H
