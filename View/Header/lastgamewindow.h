#ifndef LASTGAMEWINDOW_H
#define LASTGAMEWINDOW_H

#include <QDialog>
#include <QFile>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextStream>
#include <QJsonValue>
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonObject>
#include <QCloseEvent>


class LastGameWindow: public QDialog{
    Q_OBJECT
private:
    QGridLayout *grid=nullptr;
    QLabel *ultimaP=nullptr;

    /**
     * @brief closeEvent: evento chiusura finestra
     * @param event
     */
    void closeEvent(QCloseEvent *event);

public:
    /**
    * costruttore
    */
    LastGameWindow();

    /**
    * costruttore di copia
    */
    LastGameWindow(const LastGameWindow& l);

    /**
    * operatore di assegnazione
    */
    LastGameWindow& operator= (const LastGameWindow& l);

    /**
    * distruttore
    */
    ~LastGameWindow() override;

signals:
    /**
     * @brief chiusuraLastGame: segnale chiusura finestra
     */
    void chiusuraLastGame();

public slots:


};

#endif // LASTGAMEWINDOW_H
