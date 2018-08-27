#ifndef CPUSHBUTTON_H
#define CPUSHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QWidget>

class CPushButton : public QPushButton {
 public:
  explicit CPushButton(QWidget *parent);

 signals:

 public slots:

 private:
  void initUi();
  void initConnect();
};

#endif  // CPUSHBUTTON_H
