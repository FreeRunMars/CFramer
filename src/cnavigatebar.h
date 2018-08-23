#ifndef CNAVIGATEBAR_H
#define CNAVIGATEBAR_H

#include <QFrame>
#include <QPushButton>

class CNavigateBar : public QFrame
{
    Q_OBJECT
public:
    explicit CNavigateBar(QWidget *parent);

signals:

public slots:

private:
    void initUi();
    void initConnect();
};

#endif // CNAVIGATEBAR_H
