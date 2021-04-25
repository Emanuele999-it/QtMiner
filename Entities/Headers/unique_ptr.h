#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H


template <class T>
class unique_ptr{
private:
    /**
     * @brief ptr: puntatore all'oggetto
     */
    T* ptr;

    void swap(T*);

public:

/*----------Costruttori----------*/

    unique_ptr();

    unique_ptr(T* );

    unique_ptr(const unique_ptr<T>& );

    ~unique_ptr();


/*----------Operator----------*/

    T& operator*() const;
    T* operator->() const;

    // if(obj)-> true se esiste, false altrimenti
    explicit operator bool() const;

    //clonazione oggetto di un ptr ad un altro
    unique_ptr<T>& operator=(const unique_ptr<T>& );


/*----------Funzionalità----------*/

    /**
     * @brief release: pone ptr a nullptr
     * @return :ritorna l'oggetto puntato
     */
    T* release();

    /**
     * @brief swap: scambio oggetti ptr
     */
    void swap_ptr(unique_ptr&);

    /**
     * @brief get
     * @return ritorna oggetto puntato
     */
    T* get() const;

    /**
     * @brief reset: rimuove oggetto punatato
     */
    void reset();
};

#endif // UNIQUE_PTR_H
