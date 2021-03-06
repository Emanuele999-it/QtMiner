#ifndef BOARD
#define BOARD

#include <QGraphicsItem>
#include "Model/Header/modelBoard.h"
#include "View/Header/screens/gameScreen/Board/casella.h"
#include <QGridLayout>
#include <QVector>

namespace view {

class Board : public QWidget{
    Q_OBJECT

private:
    /**
     * @brief posizione: cella selezionata
     */
    nat posizioneBoard;

    /**
     * @brief vettoreCaselleBoard: vettore contenente le caselle
     */
    QVector<Casella*> vettoreCaselleBoard;

    /**
     * @brief spaceL: spazio a sinistra della griglia
     */
    QSpacerItem *spaceL;
    /**
     * @brief spaceR: spazio a destra della griglia
     */
    QSpacerItem *spaceR;

    /**
     * @brief grid: griglia di caselle
     */
    QGridLayout* grid;

public:
    /**
     * @brief Board: costruttore
     */
    Board(const nat&);

    /**
     * @brief Board: costruttore di copia
     */
    Board(const Board& b);

    /**
     * @brief operator =: operatore di assegnazione
     */
    Board& operator=(const Board& b);

    /**
    * distruttore
    */
    ~Board() override;

    /**
     * @brief getCasella: funzione che restituisce la casella in una determinata posizione
     */
    Casella* getCasella(nat);

    /**
     * @brief getPosizione: funzione che permette di far sapere quale posizione è stata
     *                      selezionata nella board
     */
    nat getPosizione() const;

    /**
     * @brief addelVec: funzione che permette di istanziare aggiungere elementi al vettore
     */
    void addelVec(nat celle);

    /**
     * @brief addElGrid: metodo che permette di inserire le caselle nella griglia
     * @param celle: numero di celle della griglia
     */
    void addElGrid(nat celle);

    /**
     * @brief setStart rende la casella di partenza gialla
     */
    void setStart(nat nCelle);

    /**
     * @brief setWin rende la casella di vittoria colorata
     */
    void setWin(nat nCelle);

public slots:
    /**
     * @brief selectCardBoard: slot che permette di salvare la posizione della carta cliccata
     *                         e la emette al model tramite numCasellaCliccata(nat)
     */
    void selectCardBoard(nat);

    /**
     * @brief addCard: slot che permette di aggiornare la vista (board) con la carta posizionata
     *                 dalla mano
     */
    void addCardBoard(nat, QString);

    /**
     * @brief removeStylesheetButton: rimuove colorazione selezione bottone
     */
    void removeStylesheetButton();

    /**
     * @brief getImage: ottiene immagine standard di Casella
     * @return
     */
    QString getImage(nat p) const;

signals:
    /**
     * @brief numCasellaCliccata: invio segnale a model posizione casella cliccata
     */
    void numCasellaCliccataBoard(nat);


};


class Mano: public Board{
    Q_OBJECT
private:
public:
    Mano(const nat& i=7);
};

}
#endif

