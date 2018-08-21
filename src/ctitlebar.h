#ifndef CTITLEBAR_H
#define CTITLEBAR_H

#include "Logger.h"
#include "logmanager.h"

#include <QObject>
#include <QFrame>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QApplication>

class CTitleBar : public QFrame
{
    Q_OBJECT
public:
    explicit CTitleBar(QWidget *parent = 0);

signals:

public slots:

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    void initUi();
    void initConnect();
    void initData();

    QPoint m_pressedPoint;
    QPoint m_lastMousePos;
    bool m_moving;
};

#endif // CTITLEBAR_H
