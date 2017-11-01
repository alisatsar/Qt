#include "finddialog.h"
#include <QtWidgets>

FindDialog::FindDialog(QWidget* parent) : QDialog(parent)
{
    m_label = new QLabel(tr("Find &what:"));
    m_lineEdit = new QLineEdit;
    m_label->setBuddy(m_lineEdit);

    m_caseCheckBox = new QCheckBox(tr("Match &case"));//первая буква после амперсанда будет
    //указывать на горячую клавишу в поиске
    m_backwardCheckBox = new QCheckBox(tr("Search &backward"));

    m_findButton = new QPushButton(tr("&Find"));
    m_findButton->setDefault(true);//установить клавишу по умолчанию
    m_findButton->setEnabled(false);

    m_closeButton = new QPushButton(tr("&Close"));

    connect(m_lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(EnableFindButton(const QString&)));
    connect(m_findButton, SIGNAL(clicked()), this, SLOT(FindClicked()));
    connect(m_closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout* topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(m_label);
    topLeftLayout->addWidget(m_lineEdit);
    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(m_caseCheckBox);
    leftLayout->addWidget(m_backwardCheckBox);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(m_findButton);
    rightLayout->addWidget(m_closeButton);
    rightLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);

    setWindowTitle("Find");

    setFixedHeight(sizeHint().height());
}

void FindDialog::FindClicked()
{
    QString text = m_lineEdit->text();//введен ли текст в текстовом поле
    Qt::CaseSensitivity cs = m_caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    if (m_caseCheckBox->isChecked())
    {
        emit FindPrevious(text, cs);
    }
    else
    {
        emit FindNext(text, cs);
    }
}

void FindDialog::EnableFindButton(const QString& str)
{
    m_findButton->setEnabled(!str.isEmpty());
}
