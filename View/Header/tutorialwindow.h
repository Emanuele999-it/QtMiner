#ifndef TUTORIALWINDOW_H
#define TUTORIALWINDOW_H

#include <QTextEdit>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QHBoxLayout>
#include <QTextStream>
#include <QFileDialog>
#include <QTextStream>

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

    int page;
    int TotLine;

    void displayTxt(int page);

signals:
    //void Deleting();

public:
    /**
    *costruttore
    */
    Tutorialwindow();

    /**
    *distruttore
    */
    ~Tutorialwindow() override;

    void readfile() const ;

private slots:
    /**
     * @brief CloseWindow: chiusura finestra
     */
    void CloseWindow();

    /**
     * @brief ContinueTutorial: permette di andare avanti con le pagine del tutorial
     */
    void ContinueTutorial();

    /**
     * @brief GoBackTutorial: premette di andare indietro con le pagine del tutorial
     */
    void GoBackTutorial();

};

#endif // TUTORIALWINDOW_H
