#include "calculator.h"
#include <QtWidgets>

Calculator::Calculator(QWidget* pwgt) : QWidget(pwgt)
{
    m_indicator = new QLCDNumber(12);//передаем количество сегментов в индикаторе
    m_indicator->setSegmentStyle(QLCDNumber::Flat);
    m_indicator->setMinimumSize(150, 50);

    QChar aButtons[4][4] = { {'7', '8', '9', '/'},
                             {'4', '5', '6', '*'},
                             {'1', '2', '3', '-'},
                             {'0', '.', '=', '+'}
                           };

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(m_indicator, 0, 0, 1, 4);
    ptopLayout->addWidget(createButton("CE"), 1, 3);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            ptopLayout->addWidget(createButton(aButtons[i][j]), i + 2, j);
        }
    }

    setLayout(ptopLayout);
}

QPushButton* Calculator::createButton(const QString& str)
{
    QPushButton* but = new QPushButton(str);

    but->setMinimumSize(40, 40);
    connect(but, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return but;
}

void Calculator::calculate()
{
    double dRightOperand = m_stack.pop().toDouble();
    QString operationStr = m_stack.pop();
    double dLeftOperand = m_stack.pop().toDouble();
    double result = 0;

    if (operationStr == "+")
    {
        result = dLeftOperand + dRightOperand;
    }
    else if(operationStr == "-")
    {
        result = dLeftOperand - dRightOperand;
    }
    else if(operationStr == "*")
    {
        result = dLeftOperand * dRightOperand;
    }
    else if(operationStr == "/")
    {
        result = dLeftOperand / dRightOperand;
    }


    m_indicator->display(result);
}


void Calculator::slotButtonClicked()
{
    QString str = ((QPushButton*)sender())->text();

    if(str == "CE")
    {
        m_stack.clear();
        m_stringDisplay = "";
        m_indicator->display("0");
        return;
    }

    if(str.contains(QRegExp("[0-9]")))
    {
        m_stringDisplay += str;
        m_indicator->display(m_stringDisplay);
    }
    else if(str == ".")
    {
        m_stringDisplay += str;
        m_indicator->display(m_stringDisplay);
    }
    else
    {
        if(m_stack.count() >= 2)
        {
            m_stack.push((QString().setNum(m_indicator->value())));
            calculate();
            m_stack.clear();
            m_stack.push(QString().setNum(m_indicator->value()));
            if(str != "=")
            {
                m_stack.push(str);
            }
        }
        else
        {
            m_stack.push(QString().setNum(m_indicator->value()));
            m_stack.push(str);
            m_stringDisplay = "";
            m_indicator->display("0");
        }
    }
}
