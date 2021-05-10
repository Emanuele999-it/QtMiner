﻿#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <ostream>

template <class T>
class unique_ptr{
private:
public:
    /**
     * @brief ptr: puntatore all'oggetto
     */
    T* ptr;

    void swap(T*);

public:

/*----------Costruttori----------*/

    unique_ptr(T *obj=nullptr);

    explicit unique_ptr(const unique_ptr<T>&);

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
    T* get();

    const T*get_const() const;

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


/*----------Costruttori----------*/

template<class T>
unique_ptr<T>::unique_ptr(T* obj) : ptr(obj) {}

template<class T>
unique_ptr<T>::~unique_ptr(){
    delete ptr;
    ptr=nullptr;
}

template<class T>
unique_ptr<T>::unique_ptr(const unique_ptr<T>& up): ptr(up.ptr){}


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
    return *ptr;
}

template<class T>
const T* unique_ptr<T>::operator->() const{
    return ptr;
}

template<class T>
unique_ptr<T>::operator bool() const{
    return (ptr != nullptr) ? true : false;
}

template<class T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>& up){
    if(this != &up)
        *ptr=*(up.ptr);
    return *this;
}


/*----------Funzionalità----------*/

template<class T>
T* unique_ptr<T>::release(){
    T* res = nullptr;
    swap(res);
    return res;
}

template<class T>
void unique_ptr<T>::swap_ptr(unique_ptr<T>& p){
    swap(p.ptr);
}

template<class T>
T* unique_ptr<T>::get(){
    return (ptr != nullptr) ? ptr : nullptr;
}

template<class T>
const T* unique_ptr<T>::get_const() const {
    return (ptr != nullptr) ? ptr : nullptr;
}

template<class T>
void unique_ptr<T>::reset() {
    T* temp=release();
    delete temp;
}


#endif // UNIQUE_PTR_H
