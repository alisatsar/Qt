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

    QBoxLayout* layout = new QBoxLayout(QBoxLayout::LeftToRight);
    layout->addWidget(pcmdA);
    layout->addWidget(pcmdB);
    layout->addWidget(pcmdC);
    layout->addWidget(pcmdD);

    layout->addStretch(3);

    layout->setMargin(10);
    layout->setSpacing(50);

    wgt.setLayout(layout);

    wgt.show();

    return app.exec();
}
