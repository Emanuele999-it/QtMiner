#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <ostream>

//testing
#include <QDebug>

template <class T>
class unique_ptr{
private:
    /**
     * @brief ptr: puntatore all'oggetto
     */
    T* ptr=nullptr;

    void swap(T*);



public:

/*----------Costruttori----------*/

    unique_ptr(T *obj=nullptr);

    //explicit unique_ptr(const unique_ptr<T>&);

    ~unique_ptr();


/*----------Operator----------*/

    T& operator*();
    T* operator->();

    const T& operator*() const;
    const T* operator->() const;

    // if(obj)-> true se esiste, false altrimenti
    explicit operator bool() const;

    //clonazione oggetto di un ptr ad un altro
    unique_ptr<T>& operator=(unique_ptr<T>& );

/*----------Metodi----------*/

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
    T* get();

    const T*get_const() const;

    /**
     * @brief reset: rimuove oggetto punatato e lo sostituisce con p
     */
    void reset(T*p);

    /**
     * @brief reset: rimuove oggetto punatato
     */
    void reset();
};





/*------Swap-----*/
template<class T>
void unique_ptr<T>::swap(T* up){
    T* temp=up;

    up=ptr;
    ptr=temp;
}


/*----------Costruttore/Distruttore----------*/

template<class T>
unique_ptr<T>::unique_ptr(T* obj) : ptr(obj) {}

template<class T>
unique_ptr<T>::~unique_ptr(){
    if(ptr != nullptr){
        delete ptr;
        ptr=nullptr;
    }
}


/*----------Operator----------*/


template<class T>
T& unique_ptr<T>::operator*(){
    return *ptr;
}

template<class T>
T* unique_ptr<T>::operator->(){
    return ptr;
}

template<class T>
const T& unique_ptr<T>::operator*() const{
    return &(*ptr);
}

template<class T>
const T* unique_ptr<T>::operator->() const{
    return &(*ptr);
}

template<class T>
unique_ptr<T>::operator bool() const{
    return ptr != nullptr;
}

template<class T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>& up){
    if(this != &up)
        swap(up.ptr);
    return *this;
}


/*----------Metodi----------*/

template<class T>
T* unique_ptr<T>::release(){
    T* res = ptr;
    ptr=nullptr;
    return res;
}

template<class T>
void unique_ptr<T>::swap_ptr(unique_ptr<T>& p){
    swap(p.ptr);
}

template<class T>
T* unique_ptr<T>::get(){
    return  ptr;
}

template<class T>
const T* unique_ptr<T>::get_const() const {
    return ptr;
}

template<class T>
void unique_ptr<T>::reset(T *p) {
    if(ptr)
        delete ptr;
    ptr=p;
}

template<class T>
void unique_ptr<T>::reset(){
    if(ptr)
        delete ptr;
}


#endif // UNIQUE_PTR_H
