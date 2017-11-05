#include <QApplication>
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QPixmap pix;
    pix.load("://new//prefix1//123.png");

    QLabel lbl;
    lbl.resize(pix.size());
    lbl.setPixmap(pix);
    lbl.show();

    return app.exec();
}
