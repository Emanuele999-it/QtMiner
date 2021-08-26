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
     * @brief getLastGame: caricamento e visualizzazione dell'ultima partita
     */
    void getLastGame();

};

#endif // LASTGAMEWINDOW_H
