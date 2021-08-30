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



public:
    /**
    *costruttore
    */
    SettingsWindow(unsigned int i);

    /**
    *distruttore
    */
    ~SettingsWindow() override;
};

#endif // MAINSETTINGSWINDOW_H
