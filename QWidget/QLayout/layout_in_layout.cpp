#include <QWidget>
#include <QApplication>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");
    QPushButton* pcmdD = new QPushButton("D");

    QHBoxLayout* layoutH = new QHBoxLayout;
    QVBoxLayout* layoutV = new QVBoxLayout;

    layoutH->setMargin(5);
    layoutH->setSpacing(15);
    layoutH->addWidget(pcmdC);
    layoutH->addWidget(pcmdD);

    layoutV->setMargin(5);
    layoutV->setSpacing(15);
    layoutV->addWidget(pcmdA);
    layoutV->addWidget(pcmdB);

    layoutV->addLayout(layoutH);

    wgt.setLayout(layoutV);

    wgt.show();

    return app.exec();
}
