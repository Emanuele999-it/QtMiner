#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
//testing
#include <QDebug>

using nat = unsigned int;

template <class T>
class CVector {

private:

    T* arr;

    /**
     * @brief space: spazio totale= spazio usato + spazio non usato
     */
    nat space;

    /**
     * @brief _size: numero elementi nel vettore
     */
    nat	size;


public:

/*-----------Costruttori-----------*/

    /**
     * @brief CVector: costruttore di def.
     */
    CVector();

    explicit CVector(nat l=7);

    /**
     * @brief CVector: cost. copia
     */
    CVector(const CVector&);

    /**
     * @brief operator =: op. assegnazione
     */
    CVector<T>& operator=(const CVector<T>& a);

    /**
     * @brief ~CVector: distruttore
     */
    ~CVector();



/*-----------Iteratore-----------*/

    class iterator {
        friend class CVector<T>;
        friend class const_iterator;
    private:
        T* ptr;

    public:

        explicit iterator(T* p);
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
        T& operator*() const;
        T* operator->() const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
    };


    iterator begin() const;

    iterator end() const;


/*-----------Iteratore costante-----------*/

    class const_iterator {
    friend class CVector<T>;
    private:
        iterator iter;
    public:
        const_iterator();
        const_iterator(const iterator&);
        const T& operator*() const;
        const T* operator->() const;
        const_iterator& operator++();
        const_iterator& operator--();
        const_iterator& operator++(int);
        const_iterator& operator--(int);
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
    };

    const_iterator cbegin() const;

    const_iterator cend() const;


/*-----------Elementi-----------*/

    /**
     * @brief capacity
     * @return : ritorna space
     */
    nat capacity() const;

    bool empty() const;

    /**
     * @brief size
     * @return _size
     */
    nat get_size() const;

    /**
     * @brief resize: nuova dimensione vettore
     * @param newSize
     */
    void resize(nat newSize);


/*-----------Accesso-----------*/


    /**
     * @brief operator []: op. accesso
     * @param i
     * @return
     */
    T& operator[](nat) const;


/*-----------Inserimento-----------*/

    void push_back(const T &d);


/*-----------Stampa-----------*/

    void display_vector(const CVector&);
};



/*-----------Costruttori-----------*/

template <class T>
CVector<T>::CVector(): arr(0), space(0), size(0) {}

template <class T>
CVector<T>::CVector(nat l): space(l), arr(new T[l]), size(0) {
    for(nat i=0;i<l;i++) arr[i]=T();
}

template <class T>
CVector<T>::CVector(const CVector & a)
    :space(a.space), arr(new T[a.space]), size(0){
    for (unsigned int i = 0; i<a.capacity(); i++) {
        arr[i] = a.arr[i];
    }
    size=a.size;
}

template<class T>
CVector<T>& CVector<T>::operator=(const CVector<T>& a)
{
    if (this == &a) return *this;

    //c'è abbastanza spazio
    if (a.size <= space)
    {
        for (nat index = 0; index < a.size; index++)
        {
            arr[index] = a.arr[index];
        }
        size = a.size;
        return *this;
    }

    T* p = new T[a.size];

    for (nat index = 0; index < a.size; index++)
        p[index] = a.arr[index];

    delete[] arr;
    size = a.size;
    space = a.size;
    arr = p;
    return *this;
}


template<class T>
CVector<T>::~CVector()
{
    delete[] arr;
    arr = new T[0];
    size=0;
}


/*-----------Iteratore-----------*/

template <class T>
CVector<T>::iterator::iterator(T* p):ptr(p){}

template <class T>
bool CVector<T>::iterator::operator==(const iterator& it) const{
    return ptr == it.ptr;
}

template <class T>
bool CVector<T>::iterator::operator!=(const iterator& it) const
{
    return ptr != it.ptr;
}

template <class T>
T& CVector<T>::iterator::operator*() const
{
    return *ptr;
}

template <class T>
T* CVector<T>::iterator::operator->() const
{
    return &(*ptr);
}

template <class T>
typename CVector<T>::iterator& CVector<T>::iterator::operator++()
{
    ++ptr;
    return *this;
}

template <class T>
typename CVector<T>::iterator CVector<T>::iterator::operator++(int)
{
    iterator temp(*this);
    ++*this;
    return temp;
}

template <class T>
typename CVector<T>::iterator& CVector<T>::iterator::operator--()
{
    --ptr;
    return *this;
}

template <class T>
typename CVector<T>::iterator CVector<T>::iterator::operator--(int)
{
    iterator temp(*this);
    --*this;
    return temp;
}

template <class T>
typename CVector<T>::iterator CVector<T>::begin() const
{
    return CVector<T>::iterator(&arr[0]);
}

template <class T>
typename CVector<T>::iterator CVector<T>::end() const
{
    return CVector<T>::iterator(&arr[space]);
}


/*-----------Iteratore costante-----------*/

//costruisce iteratore chiamando classe iterator (non costante)
template <class T>
CVector<T>::const_iterator::const_iterator(){}

template <class T>
CVector<T>::const_iterator::const_iterator(const CVector<T>::iterator& it): iter(it){}

template <class T>
const T& CVector<T>::const_iterator::operator*() const {
    return iter.operator*();
}
template <class T>
const T* CVector<T>::const_iterator::operator->() const {
    return iter.operator->();
}

template <class T>
typename CVector<T>::const_iterator& CVector<T>::const_iterator::operator++() {
    ++iter;
    return *this;
}

template <class T>
typename CVector<T>::const_iterator& CVector<T>::const_iterator::operator--() {
    --iter;
    return *this;
}

template <class T>
typename CVector<T>::const_iterator& CVector<T>::const_iterator::operator++(int) {
    const_iterator temp(*this);
    ++ *this;
    return temp;
}

template <class T>
typename CVector<T>::const_iterator& CVector<T>::const_iterator::operator--(int) {
    iterator temp(*this);
    --*this;
    return temp;
}

template <class T>
bool CVector<T>::const_iterator::operator==(const const_iterator& it) const{
    return iter == it.iter;
}

template <class T>
bool CVector<T>::const_iterator::operator!=(const const_iterator& it) const
{
    return iter != it.iter;
}

template <class T>
typename CVector<T>::const_iterator CVector<T>::cbegin() const{
    return CVector<T>::const_iterator(CVector<T>::iterator(&arr[0]));
}

template <class T>
typename CVector<T>::const_iterator CVector<T>::cend() const{
    return CVector<T>::const_iterator(CVector<T>::iterator(&arr[space]));
}


/*-----------Elementi-----------*/

template <class T>
nat CVector<T>::capacity() const
{
    return space;
}

template <class T>
bool CVector<T>::empty() const{
    return size==0;
}

template <class T>
nat CVector<T>::get_size() const{
    return size;
}

template <class T>
void CVector<T>::resize(nat newSize){

    if (newSize <= space) return;

    T* p = new T[newSize];
    for (unsigned int i = 0; i < size; ++i)
            p[i] = arr[i];

    delete[] arr;
    arr = p;
    space = newSize;
}


/*-----------Accesso-----------*/
template <class T>
T& CVector<T>::operator[](nat i) const {
    return arr[i];
}


/*-----------Inserimento-----------*/

template<class T>
inline void CVector<T>::push_back(const T& d){
    if (space == 0)
        resize(8);
    else if (size == space)
        resize(2 * space);

    arr[size] = d;
    size++;
}


/*-----------Stampa-----------*/

template <class T>
void display_vector(CVector<T>& v)
{
    for (typename CVector<T>::const_iterator ptr = v.begin(); ptr != v.end(); ptr++) {
        std::cout << *ptr << " ";
    }
    std::cout << '\n';
}

#endif
