#ifndef CTITLEBAR_H
#define CTITLEBAR_H

#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QDebug>

class CTitleBar : public QFrame
{
    Q_OBJECT
public:
    const int TITLE_HEIGHT = 30;
    const int BUTTON_HEIGHT = TITLE_HEIGHT;

    enum titleFlag{
        MIN_CLOSE = 0,
        MIN_MAX_CLOSE = 1,
        CLOSE = 2
    };

    enum titleHint{
        LEFT = 0,
        RIGHT = 1
    };

    explicit CTitleBar(QWidget *parent = 0);

    void setTitleFlag(titleFlag flag);

    void setTitleContent(const QString &title, int titleFontSize = 9);
    QString getTitleContent();

    void setTitleIcon(const QString &filePath, const QSize iconSize);

    void addButton(QPushButton *btn);

    void setTitleBarHeight(const int h);
    int getTitleBarHeight();

    void setTitleBarWidth(const int w);
    int getTitleBarWidth();

signals:
    void minButtonClicked();
    void maxButtonClicked();
    void restoreButtonClicked();
    void closeButtonClicked();

public slots:
    void onCloseButtonClicked();
    void onMaxButtonClicked();
    void onRestoreButtonClicked();
    void onMinButtonClicked();
    void onSettingsButtonClicked();
    void onSkinButtonClicked();
    void onLogoButtonClicked();

    void onLoadStyleSheet(const QString &sheet);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    void initUi();
    void initConnect();
    void initData();

    QPushButton *m_logoButton;
    QLabel *m_titleLabel;
    QPushButton *m_settingsButton;
    QPushButton *m_skinButton;
    QPushButton *m_minButton;
    QPushButton *m_maxButton;
    QPushButton *m_restoreButton;
    QPushButton *m_closeButton;
    QHBoxLayout *m_layout;

    QPoint m_pressPoint;
    QPoint m_relativeDragPoint;
    bool m_moving;
};

#endif // CTITLEBAR_H
