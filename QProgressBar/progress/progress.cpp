#include "progress.h"
#include <QtWidgets>

Progress::Progress(QWidget* pobj) : QWidget(pobj), m_step(0)
{
    m_bar = new QProgressBar;
    m_bar->setRange(0, 5);
    m_bar->setMinimumWidth(200);
    m_bar->setAlignment(Qt::AlignCenter);

    QPushButton* stepBut = new QPushButton("&Step");
    QPushButton* resetBut = new QPushButton("&Reset");

    QObject::connect(stepBut, SIGNAL(clicked()), SLOT(slotStep()));
    QObject::connect(resetBut, SIGNAL(clicked()), SLOT(slotReset()));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_bar);
    layout->addWidget(stepBut);
    layout->addWidget(resetBut);

    setLayout(layout);
}

void Progress::slotStep()
{
    m_bar->setValue(++m_step);
}

void Progress::slotReset()
{
    m_step = 0;
    m_bar->reset();
}
