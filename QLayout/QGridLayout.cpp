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

    QGridLayout* layoutGrid = new QGridLayout;

    layoutGrid->setMargin(5);
    layoutGrid->setSpacing(15);
    layoutGrid->addWidget(pcmdA, 0, 1);
    layoutGrid->addWidget(pcmdB, 0, 0);
    layoutGrid->addWidget(pcmdC, 1, 1);
    layoutGrid->addWidget(pcmdD, 1, 0);

    wgt.setLayout(layoutGrid);

    wgt.show();

    return app.exec();
}
