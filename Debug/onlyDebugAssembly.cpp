#include <QtWidgets>

//Для отображение информации только в отладочной версии

void dummyOutput(QtMsgType, const QMessageLogContext&, const QString&)
{
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
#ifndef QT_DEBUG
    qInstallMessageHandler(messageToFile);
#endif
    return app.exec();
}
