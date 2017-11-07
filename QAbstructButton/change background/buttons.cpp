#include "buttons.h"

QCheckBox* m_cb;
QRadioButton* m_rbRed;
QRadioButton* m_rbGreen;
QRadioButton* m_rbBlue;

Buttons::Buttons(QWidget* p) : QGroupBox("QGroupBox", p)
{
    resize(100, 150);
    setCheckable(true);
    setChecked(true);

    m_rbRed = new QRadioButton("&Red");
    m_rbGreen = new QRadioButton("&Green");
    m_rbBlue = new QRadioButton("&Blue");

    m_rbGreen->setChecked(true);

    connect(m_rbRed, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_rbGreen, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_rbBlue, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    m_cb = new QCheckBox("&Light");
    m_cb->setChecked(true);
    connect(m_cb, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    QPushButton* but = new QPushButton("&Exit");
    connect(but, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_rbRed);
    layout->addWidget(m_rbGreen);
    layout->addWidget(m_rbBlue);
    layout->addWidget(m_cb);
    layout->addWidget(but);

    setLayout(layout);
    slotButtonClicked();
}

void Buttons::slotButtonClicked()
{
    QPalette pal = palette();
    int nLight = m_cb->isChecked() ? 150 : 80;
    if(m_rbRed->isChecked())
    {
        pal.setColor(backgroundRole(), QColor(Qt::red).light(nLight));
    }
    else if(m_rbGreen->isChecked())
    {
        pal.setColor(backgroundRole(), QColor(Qt::green).light(nLight));
    }
    else
    {
        pal.setColor(backgroundRole(), QColor(Qt::blue).light(nLight));
    }

    setPalette(pal);
}
