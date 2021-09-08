#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <iostream>

class Card : public QObject{
    Q_OBJECT

private:

public:
    /**
     * @brief clone: metodo usato per clonare l'oggetto
     */
    virtual Card* clone() const = 0;

    /**
     * @brief Card:
     * @param c
     */
    Card(const Card& c)=default;

    /**
     * @brief Card: costruttore
     */
    explicit Card();

    /**
     * @brief ~Card: distruttore
     */
     virtual ~Card()=0;

    /**
     * @brief getName: funzione che ritorna il nome dell'oggetto
     * @return
     */
    virtual std::string getName() const=0;

};

#endif // CARD_H
