#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QPushButton menuButton("Menu");

    QMenu* menu = new QMenu(&menuButton);

    menu->addAction("Item1");
    menu->addAction("Item2");
    menu->addAction("&Quit", &app, SLOT(quit()));

    menuButton.setMenu(menu);

    menuButton.show();

    return app.exec();
}
