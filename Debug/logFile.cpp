#include <QtWidgets>

//программа для записывания в файл protocol.log 
//сообщения qDebug(), qWarning(), qFatal()

void messageToFile(QtMsgType type,
                   const QMessageLogContext& context,
                   const QString& msg)
{
    QFile file("protocol.log");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    QTextStream out(&file);

    switch (type)
    {
    case QtDebugMsg:
        out << "Debug: " << msg << ", " << context.file << endl;
        break;
    case QtWarningMsg:
        out << "Warning: " << msg << ", " << context.file << endl;
        break;
    case QtCriticalMsg:
        out << "Critical: " << msg << ", " << context.file << endl;
        break;
    case QtFatalMsg:
        out << "Fatal: " << msg << ", " << context.file << endl;
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    qInstallMessageHandler(messageToFile);

    return app.exec();
}
