#ifndef CLONECARDS_H
#define CLONECARDS_H

#include "card.h"

class CloneCards : public Card
{
private:

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

    /**
     * @brief getName: funzione che ritorna il nome dell'oggetto
     * @return
     */
    std::string getName() const;
};

#endif // CLONECARDS_H
