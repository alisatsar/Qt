#include <QtWidgets>
#include "counter.h"

int main(int argc, char **argv)
{

    QApplication app(argc, argv);//объект объявляется единожды

    QLabel lbl("0");//создаем текст с 0
    QPushButton button("ADD");
    Counter counter;

    lbl.show();
    button.show();

    QObject::connect(&button, SIGNAL(clicked()), &counter, SLOT(slotInc()));
    //агрументы:
    //указатель на объект, отправляющий сигнал
    //синрал с которым осуществляется соединение и метод сигнала как аргумент
    //указатель на объект, который имеет слот для обработки сигнала
    //слот, который вызывается при получении сигнала

    QObject::connect(&counter, SIGNAL(counterChangerd(int)), &lbl, SLOT(setNum(int)));

    QObject::connect(&counter, SIGNAL(goodbye()), &app, SLOT(quit()));

    return app.exec();
}
