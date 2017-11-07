#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton* pBut = new QPushButton("&Normal Button");
    QPushButton* tBut = new QPushButton("&Toggle Button");
    tBut->setCheckable(true);
    tBut->setChecked(true);

    QPushButton* flatBut = new QPushButton("&Flat Button");
    flatBut->setFlat(true);

    QPixmap pix("://button//but.png");

    QPushButton* pixBut = new QPushButton;

    pixBut->setIcon(pix);
    pixBut->setIconSize(pix.size());

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(pBut);
    layout->addWidget(tBut);
    layout->addWidget(flatBut);
    layout->addWidget(pixBut);

    wgt.setLayout(layout);

    wgt.show();

    return app.exec();
}
