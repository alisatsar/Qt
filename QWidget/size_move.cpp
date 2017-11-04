#include <QApplication>
#include <QWidget>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget* window = new QWidget;

    window->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);

    window->resize(1000, 100);
    window->move(100, 200);

    window->setGeometry(100, 100, 200, 1000);

    window->setAutoFillBackground(true);

    window->show();

    return app.exec();
}
