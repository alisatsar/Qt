#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QSlider* slider = new QSlider(Qt::Horizontal);
    QLabel* label = new QLabel("3");

    slider->setRange(0, 9);
    slider->setPageStep(2);
    slider->setValue(3);
    slider->setTickInterval(2);
    slider->setTickPosition(QSlider::TicksBelow);

    QObject::connect(slider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(label);

    wgt.setLayout(layout);

    wgt.show();

    return app.exec();
}
