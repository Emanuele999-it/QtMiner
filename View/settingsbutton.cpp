#include "Header/settingsbutton.h"

SettingsButton::SettingsButton()
{
    //path immagine standard
    iconStd=(QIcon(":/Img/settings.png"));

    // path immagine hover
    onHover=(QIcon(":/Img/settingsh.png"));

    setIcon(iconStd);
    setIconSize(QSize(40, 40));
    setFixedSize(48,48);
}

void SettingsButton::enterEvent(QEvent *event){
    Q_UNUSED(event)
    setIcon(onHover);
}

void SettingsButton::leaveEvent(QEvent *event){
    Q_UNUSED(event)
    setIcon(iconStd);
}
