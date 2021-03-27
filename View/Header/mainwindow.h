#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>

class MainWindow: public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief MainWindow: costruttore default
     * @param parent: parent di MainWindow
     */
    MainWindow(QWidget *parent=nullptr);

private:

    /**
     * @brief startGame: bottone inizio gioco
     */
    QPushButton* startGame;
    /**
     * @brief Settings: bottone impostazioni
     */
    QPushButton* settings;

public slots:
    /**
    * @brief OpenSettings
    */
    void OpenSettings() const;

};

#endif // MAINWINDOW_H
