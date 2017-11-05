#include <QApplication>
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QSplitter spl(Qt::Vertical);
    QTextEdit* tEdit1 = new QTextEdit;
    QTextEdit* tEdit2 = new QTextEdit;

    spl.addWidget(tEdit1);
    spl.addWidget(tEdit2);

    tEdit1->setPlainText("Line1\n"
                         "Line2\n"
                         "Line3\n"
                         "Line4\n"
                         "Line5\n"
                         );

    tEdit2->setPlainText(tEdit1->toPlainText());

    spl.resize(300, 300);
    spl.show();

    return app.exec();
}
