﻿#ifndef CARD_H
#define CARD_H

#include <QObject>

class Card : public QObject{
    Q_OBJECT
private:
    /**
     * @brief canBeUsed: usato per indicare quali carte possono essere
     *                   utilizzate
     */
    bool canBeUsed;

    /**
     * @brief clone: metodo usato per clonare l'oggetto
     */
    virtual Card& clone() = 0;

public:
    /**
     * @brief Card: costruttore
     */
    explicit Card();

    /**
     * @brief ~Card: distruttore
     */
     ~Card();

    /**
     * @brief get_canBeUsed: indica se la carta può essere o meno usata
     * @return booleano
     */
    virtual bool get_canBeUsed();

    /**
     * @brief setUsage: modifica che permette di indicare se la carta si può o meno usare
     */
    virtual void setUsage(bool);
};

#endif // CARD_H