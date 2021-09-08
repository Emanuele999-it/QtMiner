#ifndef LASTGAMEWINDOW_H
#define LASTGAMEWINDOW_H

#include <QDialog>
#include <QFile>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextStream>
#include <QCloseEvent>
#include <QPixmap>
#include <vector>

class LastGameWindow: public QDialog{
    Q_OBJECT
private:
    QGridLayout *grid;
    QLabel *ultimaP;
    QLabel *vincitore;

    /**
     * @brief closeEvent: evento chiusura finestra
     * @param event
     */
    void closeEvent(QCloseEvent *event);

public:
    /**
     * @brief LastGameWindow: costruttore
     */
    LastGameWindow();

    /**
     * @brief LastGameWindow: costruttore di copia
     */
    LastGameWindow(const LastGameWindow& l);

    /**
     * @brief operator =: operatore di assegnazione
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
