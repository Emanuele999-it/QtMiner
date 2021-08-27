#ifndef CROLLO_H
#define CROLLO_H

#include "obstruction.h"

class Crollo : public Obstruction
{
private:
    /**
     * @brief type: distinzione blocco/crollo
     */
    ObstructionType type;

public:
    Crollo();

    /**
     * @brief clone: metodo che clona la carta Crollo
     * @return: oggetto clonato
     */
    virtual Crollo* clone() const override;

    /**
     * @brief getType: metodo per ottenere il tipo di crollo/blocco
     * @return
     */
    virtual ObstructionType getType() const override;

    /**
     * @brief Crollo: costruttore di copia, usa clone
     * @param t: carta Crollo passata per riferimento
     */
    Crollo(const Crollo& c);

    /**
     * @brief ~Crollo: distruttore
     */
    ~Crollo();

    /**
     * @brief operator = :operatore di assegnazione, usa metodo clone
     * @param t : carta Crollo passata per riferimento
     * @return : ritorna un riferimento a Crollo
     */
    Crollo& operator =(const Crollo& c);

    /**
     * @brief getName: funzione che ritorna il nome dell'oggetto
     * @return
     */
    std::string getName() const;
};

#endif // CROLLO_H
