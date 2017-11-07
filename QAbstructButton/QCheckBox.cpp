#include <QtWidgets>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QCheckBox* cbNor = new QCheckBox("&Check box normal");
    cbNor->setChecked(true);

    QCheckBox* cbTristate = new QCheckBox("&Check box tristate");
    cbTristate->setTristate(true);
    cbTristate->setCheckState(Qt::PartiallyChecked);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(cbNor);
    layout->addWidget(cbTristate);

    wgt.setLayout(layout);
    wgt.show();

    return app.exec();
}
