#ifndef LASTGAMEWINDOW_H
#define LASTGAMEWINDOW_H

#include <QDialog>
#include <QFile>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextStream>


class LastGameWindow: public QDialog{
    Q_OBJECT
private:
    QGridLayout *grid;
    QLabel *ultimaP;

public:

    LastGameWindow(QDialog *parent = nullptr);

signals:


public slots:
    /**
     * @brief setGame: salvatggio su file dell'ultimo gioco
     */
    void saveLastGame();

    /**
     * @brief getLastGame: caricamento e visualizzazione dell'ultima partita
     */
    void getLastGame();

};

#endif // LASTGAMEWINDOW_H
