#include <QtWidgets>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QSet<QString> set1;
    QSet<QString> set2;
    QSet<QString> setResult;

    set1 << "Therion" << "Nightwish" << "Xandria";
    set2 << "Mantus" << "Hagard" << "Therion";

    setResult = set1;
    setResult.unite(set2);//объединение

    qDebug() << "unite" << setResult.toList();

    setResult = set1;
    setResult.intersect(set2);//пересечение

    qDebug() << "intersect" << setResult.toList();

    setResult = set1;
    setResult.subtract(set2);//разность

    qDebug() << "subtract set1 between set2" << setResult.toList();

    return app.exec();
}
