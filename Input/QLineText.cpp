#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QLabel* label = new QLabel;

    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    label->setLineWidth(2);
    label->setFixedHeight(50);

    QLabel* lText = new QLabel("&Text");
    QLineEdit* lineEdit = new QLineEdit;
    lText->setBuddy(lineEdit);

    QObject::connect(lineEdit, SIGNAL(textChanged(const QString&)), label, SLOT(setText(const QString&)));

    QLabel* lPass = new QLabel("&Password");
    QLineEdit* lineEdit2 = new QLineEdit;
    lPass->setBuddy(lineEdit2);
    lineEdit2->setEchoMode(QLineEdit::Password);

    QObject::connect(lineEdit2, SIGNAL(textChanged(const QString&)), label, SLOT(setText(const QString&)));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lText);
    layout->addWidget(lineEdit);
    layout->addWidget(lPass);
    layout->addWidget(lineEdit2);

    wgt.setLayout(layout);

    wgt.resize(200, 200);

    wgt.show();

    return app.exec();
}
