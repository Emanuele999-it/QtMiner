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
    QGridLayout *grid;
    QLabel *ultimaP;

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
