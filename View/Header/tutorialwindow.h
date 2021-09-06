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
#include <QPixmap>
#include <QImage>

class Tutorialwindow : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *l=nullptr;

    QPushButton *avanti=nullptr;
    QPushButton *indietro=nullptr;
    QPushButton *menu=nullptr;
    QLabel *text=nullptr;
    QLabel *icon=nullptr;

    int page;
    int TotLine;

    void displayTxt(int page);

    /**
     * @brief closeEvent: evento chiusura finestra
     * @param event
     */
    void closeEvent(QCloseEvent *event);

signals:
    /**
     * @brief closeTut: seganle chiusura finestra tutorial
     */
    void closeTut();

public:
    /**
    *costruttore
    */
    Tutorialwindow();

    /**
    * costruttore di copia
    */
    Tutorialwindow(const Tutorialwindow& t);

    /**
    * operatore di assegnazione
    */
    Tutorialwindow& operator=(const Tutorialwindow& t);

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
