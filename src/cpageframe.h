#ifndef CPAGEFRAME_H
#define CPAGEFRAME_H

#include <QFrame>

class CPageFrame : public QFrame
{
public:
    explicit CPageFrame(QWidget *parent);

signals:

public slots:

private:
    void initUi();
    void initConnect();
};

#endif // CPAGEFRAME_H
