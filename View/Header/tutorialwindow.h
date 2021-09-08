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
    QVBoxLayout *l;

    QPushButton *avanti;
    QPushButton *indietro;
    QPushButton *menu;
    QLabel *text;
    QLabel *icon;

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
     * @brief Tutorialwindow: costruttore
     */
    Tutorialwindow();

    /**
     * @brief Tutorialwindow: costruttore di copia
     * @param t
     */
    Tutorialwindow(const Tutorialwindow& t);

    /**
     * @brief operator =: operatore di assegnazione
     */
    Tutorialwindow& operator=(const Tutorialwindow& t);

    /**
    *distruttore
    */
    ~Tutorialwindow() override;

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
