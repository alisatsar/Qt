#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget* window = new QWidget;//создаем окно
    window->setWindowTitle("Program slider");//присваивает название окну

    QSpinBox* spinBox = new QSpinBox;
    QSlider* sliderHor = new QSlider(Qt::Horizontal);
    QSlider* sliderVer = new QSlider(Qt::Vertical);
    QPushButton* button = new QPushButton("Quit");

    //Указываем дипозон значений
    //через метод setRange()
    spinBox->setRange(0, 150);
    sliderHor->setRange(0, 150);
    sliderVer->setRange(0, 150);

    //соединение горизонтального слайдера со спинбоксом
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), sliderHor, SLOT(setValue(int)));
    QObject::connect(sliderHor, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    //соединение вертикального слайдера со спинбоксом
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), sliderVer, SLOT(setValue(int)));
    QObject::connect(sliderVer, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    //соединение кнопки действия
    QObject::connect(button, SIGNAL(clicked(bool)), &app, SLOT(quit()));
    spinBox->setValue(50);

    //создаем объект в котором будут скомпанованы все наши виджеты
    //размещает виджеты по горизонтали слева направо
    QHBoxLayout* layuot = new QHBoxLayout;
    layuot->addWidget(spinBox);
    layuot->addWidget(sliderHor);
    layuot->addWidget(sliderVer);
    layuot->addWidget(button);

    window->setLayout(layuot);//привязываем к окну наш layout
    window->show();

    return app.exec();
}
