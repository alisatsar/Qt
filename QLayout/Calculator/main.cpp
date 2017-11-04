#include <QApplication>
#include "calculator.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Calculator calculator;

    calculator.setWindowTitle("Calculator");
    calculator.resize(200, 300);

    calculator.show();

    return app.exec();
}
