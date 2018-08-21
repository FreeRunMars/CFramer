#ifndef CNAVIGATEBAR_H
#define CNAVIGATEBAR_H

#include <QObject>
#include <QFrame>

class CNavigateBar : public QFrame
{
    Q_OBJECT
public:
    explicit CNavigateBar(QWidget *parent = 0);

signals:

public slots:

private:
    void initUi();
    void initConnect();
};

#endif // CNAVIGATEBAR_H
