#pragma once

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT//макрос, с помощь которого
    //MOC внедряет в файл всю необходимую
    //дополнительную информацию
private:
    int m_nValue;
public:
    Counter();
public slots:
    void slotInc();
signals:
    void goodbye();
    void counterChangerd(int);
};
