#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QRadioButton* rbRed = new QRadioButton("&Red");
    QRadioButton* rbGreen = new QRadioButton("&Green");
    QRadioButton* rbBlue = new QRadioButton("&Blue");

    rbRed->setChecked(true);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(rbRed);
    layout->addWidget(rbGreen);
    layout->addWidget(rbBlue);

    wgt.setLayout(layout);
    wgt.show();

    return app.exec();
}
