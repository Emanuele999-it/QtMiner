#ifndef CASELLA_H_
#define CASELLA_H_

#include <QGraphicsItem>
#include "Entities/Header/unique_ptr.h"
#include "Entities/Header/cvector.h"
#include "Model/Header/carta/card.h"
#include <QPushButton>
using std::vector;

namespace view {


class Casella : public QPushButton {
    Q_OBJECT

private:
    nat pos;
    QIcon onHover;
    QIcon iconStd;
    QString def;

protected:
    /**
     * @brief enterEvent: Metodo chiamato quando il mouse entra dentro il widget
     * @param event: Evento generato
     */
    virtual void enterEvent(QEvent *event);

    /**
     * @brief leaveEvent: Metodo chiamato quando il mouse esce dal widget
     * @param event: Evento generato
     */
    virtual void leaveEvent(QEvent *event);

public:
    /**
    * costruttore
    */
    Casella(nat p=0, QString s="blank", QPushButton*pushbutton = new QPushButton());

    /**
    * costruttore di copia
    */
    Casella(const Casella& c);

    /**
    * operatore di assegnazione
    */
    Casella& operator=(const Casella& c);

    /**
    * distruttore
    */
    ~Casella() override;

    /**
     * @brief cambiaImmagine: funzione che permette di cambiare immagine alla casella
     * @param i: nome file immagine
     */
    void cambiaImmagine(QString i);

    /**
     * @brief getDefautImage: funzione che permette di ritornare l'immagine di defult di casella
     * @return: qstring immagine default
     */
    QString getDefautImage() const;

signals:
    /**
     * @brief casellaCliccata: invio segnale casella cliccata
     * @param p: id casella cliccata (quindi la sua posizione)
     */
    void casellaCliccata(nat p);




private slots:
    /**
     * @brief supportoCasellaCliccata: slot supporto per emissione segnale casellaCliccata
     */
    void supportCasellaCliccata();

};

}
#endif

