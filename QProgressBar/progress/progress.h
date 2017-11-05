#pragma once

#include <QWidget>

class QProgressBar;

class Progress : public QWidget
{
    Q_OBJECT
private:
    QProgressBar* m_bar;
    int m_step;
public:
    Progress(QWidget* pobj = 0);
public slots:
    void slotStep();
    void slotReset();
};
