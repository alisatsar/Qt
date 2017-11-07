#pragma once
#include <QtWidgets>
#include <QWidget>
#include <QGroupBox>

class QCheckBox;
class QRadioButton;

class Buttons : public QGroupBox
{
   Q_OBJECT
private:
   QCheckBox* m_cb;
   QRadioButton* m_rbRed;
   QRadioButton* m_rbGreen;
   QRadioButton* m_rbBlue;
public:
   Buttons(QWidget* p = 0);
public slots:
   void slotButtonClicked();
};
