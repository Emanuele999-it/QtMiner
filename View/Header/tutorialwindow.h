#ifndef TUTORIALWINDOW_H
#define TUTORIALWINDOW_H

#include <QTextEdit>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class Tutorialwindow : public QDialog
{
    Q_OBJECT
private:
    QTextEdit *e;
    QVBoxLayout *l;

    QPushButton *avanti;
    QPushButton *indietro;
    QPushButton *menu;
    QLabel *text;

signals:
    //void Deleting();

public:
    Tutorialwindow(QWidget *parent=nullptr);

    void readfile() const ;

private slots:
    void CloseWindow();

};

#endif // TUTORIALWINDOW_H
