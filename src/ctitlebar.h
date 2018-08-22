#ifndef CTITLEBAR_H
#define CTITLEBAR_H

#include "signalmanager.h"

#include <QFrame>
#include <QMouseEvent>

class CTitleBar : public QFrame
{
    Q_OBJECT
public:
    explicit CTitleBar(QWidget *parent = 0);

signals:

public slots:
    void onChangeStyleSheet(const QString &s);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    void initUi();
    void initConnect();
    void initData();

    QPoint m_pressPoint;
    QPoint m_relativeDragPoint;
    bool m_moving;
};

#endif // CTITLEBAR_H
