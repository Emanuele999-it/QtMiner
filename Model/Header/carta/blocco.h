#ifndef BLOCCO_H
#define BLOCCO_H

#include "obstruction.h"

class Blocco : public Obstruction
{
private:
    /**
     * @brief type: distinzione blocco/crollo
     */
    ObstructionType type;

public:

    /**
     * @brief Blocco: costruttore
     */
    Blocco();

    /**
     * @brief clone: metodo che clona la carta Blocco
     * @return: oggetto clonato
     */
    virtual Blocco* clone() const override;

    /**
     * @brief getType: metodo per ottenere il tipo di crollo/blocco
     * @return
     */
    virtual ObstructionType getType() const override;

    /**
     * @brief Blocco: costruttore di copia, usa clone
     * @param t: carta Blocco passata per riferimento
     */
    Blocco(const Blocco& b);

    /**
     * @brief ~Blocco: distruttore
     */
    ~Blocco() override;

    /**
     * @brief operator = :operatore di assegnazione, usa metodo clone
     * @param t : carta Blocco passata per riferimento
     * @return : ritorna un riferimento a Blocco
     */
    Blocco& operator =(const Blocco& b);

    /**
     * @brief getName: funzione che ritorna il nome dell'oggetto
     * @return
     */
    std::string getName() const;
};

#endif // BLOCCO_H
