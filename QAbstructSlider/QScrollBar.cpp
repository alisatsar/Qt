#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QLCDNumber* indicator = new QLCDNumber(4);
    QScrollBar* scrollBar = new QScrollBar(Qt::Horizontal);

    QObject::connect(scrollBar, SIGNAL(valueChanged(int)), indicator, SLOT(display(int)));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(indicator);
    layout->addWidget(scrollBar);

    wgt.setLayout(layout);

    wgt.show();

    return app.exec();
}
