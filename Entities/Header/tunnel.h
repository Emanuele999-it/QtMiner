#ifndef TUNNEL_H
#define TUNNEL_H

#include "card.h"

class Tunnel : public Card
{

private:
    /**
     * @brief arr: array che indica le direzioni del percorso della carta
     */
    bool *arr;

    /**
     * @brief clone: metodo che clona la carta Tunnel
     * @return: oggetto clonato
     */
    virtual Card& clone() override;

public:
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


};

#endif // TUNNEL_H
