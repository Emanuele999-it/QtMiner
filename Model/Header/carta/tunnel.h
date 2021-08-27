#ifndef TUNNEL_H
#define TUNNEL_H

#include "card.h"

class Tunnel : public Card
{

private:
public:
    /**
     * @brief arr: array che indica le direzioni del percorso della carta
     */
    bool* arr;

    /**
     * @brief copia: metodo che permette di copiare array
     */
    void copia(const bool *);

public:
    /**
     * @brief clone: metodo che clona la carta Tunnel
     * @return: oggetto clonato
     */
    virtual Tunnel* clone() const override;

    /**
     * @brief Tunnel: costruttore
     */
    Tunnel(bool North=true, bool East=true, bool South=true, bool West=true);

    /**
     * @brief Tunnel: costruttore di copia, usa clone
     * @param t: carta tunnel passata per riferimento
     */
    Tunnel(const Tunnel& t);

    /**
     * @brief ~Tunnel: distruttore
     */
    ~Tunnel();

    /**
     * @brief operator = :operatore di assegnazione, usa metodo clone
     * @param t : carta tunnel passata per riferimento
     * @return : ritorna un riferimento a Tunnel
     */
    Tunnel& operator =(const Tunnel& t);

    /**
     * @brief getArr: metodo che restituisce l'array di bool
     * @return
     */
    bool* getArr();


    /**
     * @brief getName: funzione che ritorna il nome dell'oggetto
     * @return
     */
    std::string getName() const;
};

#endif // TUNNEL_H
