#pragma once

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel* m_label;
    QLineEdit* m_lineEdit;
    QCheckBox* m_caseCheckBox;
    QCheckBox* m_backwardCheckBox;
    QPushButton* m_findButton;
    QPushButton* m_closeButton;
public:
    FindDialog(QWidget* parent = 0);

signals:
    void FindNext(const QString& str, Qt::CaseSensitivity cs);
    void FindPrevious(const QString& str, Qt::CaseSensitivity cs);

private slots:
    void FindClicked();
    void EnableFindButton(const QString& str);
};
