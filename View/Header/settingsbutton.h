#ifndef SETTINGSBUTTON_H
#define SETTINGSBUTTON_H

#include <QPushButton>
#include <QIcon>

class SettingsButton: public QPushButton
{
public:
    SettingsButton();
private:
    QIcon iconStd;
    QIcon onHover;
protected:
    /**
     * @brief enterEvent: Metodo chiamato quando il mouse entra dentro il widget
     * @param event: Evento generato
     */
    virtual void enterEvent(QEvent *event);

    /**
     * @brief leaveEvent: Metodo chiamato quando il mouse esce dal widget
     * @param event: Evento generato
     */
    virtual void leaveEvent(QEvent *event);
};

#endif // SETTINGSBUTTON_H
