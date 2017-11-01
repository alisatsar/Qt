#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QObject* ob1 = new QObject();
    QObject* ob2 = new QObject(ob1);
    QObject* ob3 = new QObject(ob2);
    QObject* ob4 = new QObject(ob1);

    ob1->setObjectName("Parent");
    ob2->setObjectName("The object 2");
    ob3->setObjectName("The object 3");
    ob4->setObjectName("The object 3");

    QList<QObject*> list = ob1->findChildren<QObject*>();//вернет список детей

    ob1->dumpObjectTree();//покажет дерево наследования

    //МЕТАОБЪЕКТНАЯ ИНФОРМАЦИЯ
    //c помощью класса QMetaObject узнаем информацию о объектк
    //выводим информацию в дебаге
    qDebug() << ob1->metaObject()->className();

    return app.exec();
}
