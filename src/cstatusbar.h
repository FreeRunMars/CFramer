#ifndef CSTATUSBAR_H
#define CSTATUSBAR_H

#include <QObject>
#include <QFrame>

class CStatusBar : public QFrame
{
    Q_OBJECT
public:
    explicit CStatusBar(QWidget *parent = 0);

signals:

public slots:

private:
    void initUi();
    void initConnect();
};

#endif // CSTATUSBAR_H
