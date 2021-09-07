#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QString>
#include <QTextEdit>
#include <QDialog>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextStream>


class WinWindow : public QDialog
{
    Q_OBJECT
private:

    QPushButton *newgame=nullptr;
    QPushButton *checkboard=nullptr;
    QPushButton *menu=nullptr;
    QLabel *text=nullptr;
    QPushButton *image=nullptr;
    QString nome;
    QVBoxLayout *Vl = nullptr;

signals:
    /**
     * @brief newgame manda segnale a mainwindow
     */
    void newgamesignal();


public:
    /**
    *costruttore
    */
    WinWindow(QString);

    /**
    * costruttore di copia
    */
    WinWindow(const WinWindow& t);

    /**
    * operatore di assegnazione
    */
    WinWindow& operator=(const WinWindow& t);

    /**
    *distruttore
    */
    ~WinWindow() override;


signals:
    /**
     * @brief NewMenuRequest: si chiude la finestra e si riapre mainWindow
     */
    void NewMenuRequest();
    /**
     * @brief NewMenuRequest: si chiude la finestra e si riapre mainWindow
     */
    void NewCheckRequestSignal();

    /**
     * @brief chiusuraWinWindow: si torna alla mainwindow
     */
    void chiusuraWinWindow();
private slots:

    /**
     * @brief NewCheckRequest: mandero' un segnale a boardWindow per il controllo del terreno
     */
    void NewCheckRequest();

    /**
     * @brief CloseWindow: chiusura finestra
     */
    //void CloseWindow();
    /**
     * @brief NewBoardRequest: mandero' una segnale a mainwindow per una nuova board
     */
    void NewBoardRequest();

};

#endif // TUTORIALWINDOW_H
