#include <QWidget>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget* window = new QWidget;

    QWidget* winChild = new QWidget(window);
    QPalette* pall = new QPalette;

    pall->setColor(winChild->backgroundRole(), Qt::blue);
    winChild->setPalette(*pall);
    winChild->resize(100, 100);
    winChild->move(25, 25);
    winChild->setAutoFillBackground(true);

    QWidget* winChild2 = new QWidget;
    QPalette* pall2;
    pall2->setBrush(winChild2->backgroundRole(), QBrush(QPixmap(":/stone.jpg")));

    winChild2->setPalette(*pall2);
    winChild2->resize(100, 140);
    winChild2->move(50, 50);
    winChild2->setAutoFillBackground(true);

    window->resize(200, 200);

    window->show();

    return app.exec();
}
