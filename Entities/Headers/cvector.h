#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

template <class T>
class CVector {

private:
    T*array;
    unsigned int size;
    T* copy() const ;

public:
    CVector();
    CVector(unsigned int s=0);
    //CVector(const CVector &v){}
    CVector& operator=(const CVector& );
    ~CVector();


    class ConstIterator{
        friend class CVector<T>;
        //da togliere
        //friend std::ostream& operator<<(std::ostream &os, const ConstIterator &c);

      private:
        T* _array;
        ConstIterator(T* a);
    public:
        ConstIterator();
        T* operator++() const ;
        T* operator--() const ;
        T* operator++(int) const ;
        T* operator--(int) const ;
        const T& operator*() ;
        const T* operator->() ;
        bool operator==(const T& a) const ;
        bool operator!=(const T& a) const ;

    };

    ConstIterator begin() const;

    ConstIterator end() const;

    ConstIterator operator[](unsigned int i) const;




};

template <class T>
CVector<T>::CVector() : array(0), size(0){}

template <class T>
CVector<T>::CVector(unsigned int s): array(s>0 ? new T[s]: 0), size(s){}

template <class T>
typename CVector<T>::CVector& CVector<T>::operator=(const CVector& v) {
    if(this != &v){
        delete[] array;
        array = v.copy();
        size = v.size;
        }
    return *this;
    }


template <class T>
CVector<T>::~CVector() { delete[] array;}

template <class T>
T* CVector<T>::copy() const {
    if(array->size == 0) return nullptr;
    T* x = new T[array->size];
    for(unsigned int i=0; i<array->size; ++i) x[i]=array[i];
    return x;
}


template <class T>
CVector<T>::ConstIterator::ConstIterator(T*a): _array(a) {}

template <class T>
CVector<T>::ConstIterator::ConstIterator(): _array(0) {}

template <class T>
T* CVector<T>::ConstIterator::operator++() const {
    ++_array; return *this;
}

template <class T>
T* CVector<T>::ConstIterator::operator--() const {
    _array--; return *this;
}

template <class T>
T* CVector<T>::ConstIterator::operator++(int) const {
    ConstIterator tmp = *this; ++(*this); return tmp;
}

template <class T>
T* CVector<T>::ConstIterator::operator--(int) const {
    ConstIterator tmp = *this; ++(*this); return tmp;
}

template <class T>
const T& CVector<T>::ConstIterator::operator*() {return *_array;}

template <class T>
const T* CVector<T>::ConstIterator::operator->() {return _array;}

template <class T>
bool CVector<T>::ConstIterator::operator==(const T& a) const {return _array==a;}

template <class T>
bool CVector<T>::ConstIterator::operator!=(const T& a) const {return _array!=a;}

template <class T>
typename  CVector<T>::ConstIterator  CVector<T>::begin() const{
    return  ConstIterator(array);
}

template <class T>
typename  CVector<T>::ConstIterator  CVector<T>::end() const{
    return  ConstIterator(array + size);
}

template <class T>
typename  CVector<T>::ConstIterator  CVector<T>::operator[](unsigned int i) const{
    return  ConstIterator(array + i);
}
/*
//da togliere
template <class T>
std::ostream& CVector<T>::ConstIterator::operator<<(std::ostream &os, const ConstIterator &c)
{
    os << c->_array << " : ";
    return os;
}
*/
#endif
