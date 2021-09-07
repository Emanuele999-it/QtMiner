#ifndef MAINSETTINGSWINDOW_H
#define MAINSETTINGSWINDOW_H

#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLCDNumber>
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>


class SettingsWindow: public QDialog
{
    Q_OBJECT

private:
    QVBoxLayout *vLayout=nullptr;
    QHBoxLayout *hLayout=nullptr;

    QSlider* slider=nullptr;
    QLCDNumber* lcd=nullptr;
    QPushButton* confirm=nullptr;

    int valore;

    /**
     * @brief closeEvent: evento chiusura finestra
     * @param event
     */
    void closeEvent(QCloseEvent *event);

public slots:
    /**
     * @brief setDisplayNumber: l'invio del numero di caselle scelte per la partita
     *
     */
    void setDisplayNumber(int);

    /**
     * @brief emitBoardDimension: emissione segnale cambio dimensioni board
     */
    void emitBoardDimension();

signals:
    /**
     * @brief newBoardDimension: segnale diretto alla mainWindow
     */
    void newBoardDimension(unsigned int);

    /**
     * @brief closeSett: segnale chiusura impostazioni
     */
    void closeSett();

public:
    /**
    *costruttore
    */
    SettingsWindow(unsigned int i);

    /**
    * costruttore di copia
    */
    SettingsWindow(const SettingsWindow& s);

    /**
    * operatore di assegnazione
    */
    SettingsWindow& operator=(const SettingsWindow& s);

    /**
    *distruttore
    */
    ~SettingsWindow() override;
};

#endif // MAINSETTINGSWINDOW_H
