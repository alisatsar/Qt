#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget* window = new QWidget;

    QLCDNumber* indicator = new QLCDNumber;
    QSpinBox* spinBox = new QSpinBox;

    indicator->setSegmentStyle(QLCDNumber::Filled);
    indicator->setMode(QLCDNumber::Hex);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), indicator, SLOT(display(int)));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(indicator);
    layout->addWidget(spinBox);

    window->setLayout(layout);
    window->resize(250, 150);
    window->show();

    return a.exec();
}
