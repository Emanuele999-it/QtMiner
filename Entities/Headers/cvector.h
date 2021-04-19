#ifndef CVECTOR_H
#define CVECTOR_H


template <class T>
class CVector {
private:
    T* a;
    unsigned int size;
    unsigned int used;

public:

    /**
     * @brief CVector: costruttore del vettore
     * @param s: parametro che indica la grandezza iniziale del vettore
     */
    CVector(unsigned int s =0);

    /**
     * @brief CVector: costruttore di copia
     * @param v: vettore da copiare
     */
    CVector(const CVector& v);


    ~CVector();

/*
    Funzionalità da controllare/aggiungere
*/
    class iterator {
            friend class CVector<T>;
            friend class constIterator;

           private:
            T* _ptr;
            iterator(T* n);

           public:
            iterator();
            T& operator*() const;
            T* operator->() const;
            iterator& operator++();
            iterator& operator--();
            bool operator==(const iterator& x) const;
            bool operator!=(const iterator& x) const;
        };


    class constIterator {
        friend class CVector<T>;

        private:
            T* _array;
            constIterator(T* n);

        public:
            constIterator();
            CVector<T>& operator=(const CVector<T>& vec);
            constIterator& operator++();
            constIterator& operator--();
            bool operator==(const constIterator& x) const;
            bool operator!=(const constIterator& x) const;
            int& operator[](unsigned int i) const;
            const T& operator*() const;
            const T* operator->() const;
        };

    iterator begin() const;
    iterator end() const;

    constIterator cbegin() const;
    constIterator cend() const;
};


template<class T>
CVector<T>::CVector(){
    arr = new T[1];
    capacity = 1;
    current = 0;
}

//non va!
template<class T>
CVector<T>::CVector(const CVector<T>& vec){
    //for (int i = 0; i < vec.current; i++) { push(T(vec[i])); }
}

template<class T>
CVector<T>& CVector<T>::operator=(const CVector<T>& vec){
    if(&vec != this){
        delete[] arr;
        arr = new T[1];
        current=0;
        capacity=1;
        for (int i = 0; i < vec.current; i++) { push(T(vec[i])); }
    }
    return *this;
}

template<class T>
CVector<T>::~CVector(){
    delete[] a;
}

template <class T>
CVector<T>::iterator::iterator() : _ptr(nullptr){}

template <class T>
CVector<T>::iterator::iterator(T*n) : _ptr(n){}

template <class T>
T& CVector<T>::iterator::operator*() const {
    return _ptr->a;
}

template <class T>
T* CVector<T>::iterator::operator*() const {
    return &(_ptr->a);
}

template <class T>
typename CVector<T>::iterator& CVector<T>::iterator::operator++() {
    if (_ptr != nullptr) {
        if (used < size) {
                ptr++;
            }
        }
    return *this;
}

template <class T>
typename CVector<T>::iterator& CVector<T>::iterator::operator--() {
    if (_ptr != nullptr) {
        if (used <= size && used > 0) {
                ptr--;
            }
        }
    return *this;
}

template <class T>
bool CVector<T>::iterator::operator==(const iterator& x) const {
    return _ptr == x._ptr;
}

template <class T>
bool CVector<T>::iterator::operator!=(const iterator& x) const {
    return _ptr != x._ptr;
}

template <class T>
typename CVector<T>::iterator CVector<T>::begin() {
    return a;
}

template <class T>
typename CVector<T>::iterator CVector<T>::end() {
    return a;
}


template <class T>
CVector<T>::constIterator::constIterator(): _array(nullptr) {}
template <class T>
CVector<T>::constIterator::constIterator(const CVector<T>& vec) {}
