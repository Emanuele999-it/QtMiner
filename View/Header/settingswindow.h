#ifndef MAINSETTINGSWINDOW_H
#define MAINSETTINGSWINDOW_H

#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLCDNumber>
#include <QDialog>

class SettingsWindow: public QDialog
{
    Q_OBJECT

private:
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;

    QSlider* slider;
    QLCDNumber* lcd;

private slots:
    /**
     * @brief setValue: imposta valore di lcd
     */
    void setValue(int);

signals:
    /**
     * @brief valueChanged: segnale valore cambiato dello slider
     */
    void valueChanged(int);

public:
    SettingsWindow();
};

#endif // MAINSETTINGSWINDOW_H
