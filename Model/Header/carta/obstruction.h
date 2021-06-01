#ifndef OBSTRUCTION_H
#define OBSTRUCTION_H

#include "card.h"

#include "Enums/obstructiontype.h"

class Obstruction: public Card
{
private:

public:

    Obstruction();

    /**
     * @brief clone: metodo usato per clonare l'oggetto
     */
    virtual Card* clone() const = 0;

    /**
     * @brief getType: metodo per ottenere il tipo di crollo/blocco
     * @return
     */
    virtual ObstructionType getType() const = 0;

    /*~Tunnel();

    / **
     * @brief operator = :operatore di assegnazione, usa metodo clone
     * @param t : carta tunnel passata per riferimento
     * @return : ritorna un riferimento a Tunnel
     */
    //Tunnel& operator =(const Tunnel& t);

};

#endif // OBSTRUCTION_H
