#include <QApplication>
#include <QtWidgets>
//при помощи метода setBuddy()
//виджет надписи может быть ассоциирован с другим
//виджетом.
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QLabel* label = new QLabel("&Name:");//ставим амперсанд
    QLineEdit* lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    QLabel* label2 = new QLabel("&Age:");
    QSpinBox* spinbox = new QSpinBox;
    label2->setBuddy(spinbox);

    QVBoxLayout* layoutV = new QVBoxLayout;
    layoutV->addWidget(label);
    layoutV->addWidget(lineEdit);
    layoutV->addWidget(label2);
    layoutV->addWidget(spinbox);

    wgt.setLayout(layoutV);

    wgt.show();

    return app.exec();
}
