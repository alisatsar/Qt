#pragma once

#include <QWidget>
#include <QStack>

class QLCDNumber;
class QPushButton;

class Calculator : public QWidget
{
    Q_OBJECT
private:
    QLCDNumber* m_indicator;//электронный индикатор
    QStack<QString> m_stack;//стек для проведения операций вычисления
    QString m_stringDisplay;//строка для записи кнопок нажатых пользователем
public:
    Calculator(QWidget* pwgt = 0);
    QPushButton* createButton(const QString& str);
    void calculate();

public slots:
    void slotButtonClicked();
};
