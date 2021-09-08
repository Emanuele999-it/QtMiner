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
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;

    QSlider* slider;
    QLCDNumber* lcd;
    QPushButton* confirm;

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
     * @brief SettingsWindow: costruttore
     * @param i
     */
    SettingsWindow(unsigned int i);

    /**
     * @brief SettingsWindow: costruttore di copia
    */
    SettingsWindow(const SettingsWindow& s);

    /**
     * @brief operator =:operatore di assegnazione
    */
    SettingsWindow& operator=(const SettingsWindow& s);

    /**
    *distruttore
    */
    ~SettingsWindow() override;
};

#endif // MAINSETTINGSWINDOW_H
