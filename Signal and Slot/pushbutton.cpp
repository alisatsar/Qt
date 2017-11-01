#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);//осуществление контроля над приложением
    QPushButton *button = new QPushButton("завершить работу программы");
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
    button->show();

    return a.exec();
}
