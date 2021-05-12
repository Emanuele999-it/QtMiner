#ifndef CLONECARDS_H
#define CLONECARDS_H

#include "card.h"

class CloneCards : public Card
{
public:

    CloneCards();

    /**
     * @brief clone: metodo che clona la carta CloneCards
     * @return: oggetto clonato
     */
    virtual CloneCards* clone() const override;

    /**
     * @brief CloneCards: cost copia
     * @param c
     */
    CloneCards(const CloneCards& c);
};

#endif // CLONECARDS_H
