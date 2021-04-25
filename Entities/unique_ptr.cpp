#include "Entities/Headers/unique_ptr.h"

/*------Swap-----*/
template<class T>
void unique_ptr<T>::swap(T* up){
    //todo
}


/*----------Costruttori----------*/

template<class T>
unique_ptr<T>::unique_ptr() : ptr(nullptr) {}

template<class T>
unique_ptr<T>::unique_ptr(T* p) : ptr(p) {}

template<class T>
unique_ptr<T>::~unique_ptr(){
    delete ptr;
}

//to do
template<class T>
unique_ptr<T>::unique_ptr(const unique_ptr<T>& up){
    //to do
}


/*----------Operator----------*/


template<class T>
T& unique_ptr<T>::operator*() const{
    return *ptr;
}

template<class T>
T* unique_ptr<T>::operator->() const{
    return ptr;
}

template<class T>
unique_ptr<T>::operator bool() const{
    return *ptr;
}

//to do
template<class T>
unique_ptr<T>& unique_ptr<T>::operator=(const unique_ptr<T>& up){
    //to do
}




/*----------Funzionalità----------*/

template<class T>
T* unique_ptr<T>::release(){
    T* res = nullptr;
    swap(res);
    return res;
}

//to do
template<class T>
void unique_ptr<T>::swap_ptr(unique_ptr& p){
    swap(p.ptr);
}

template<class T>
T* unique_ptr<T>::get() const {
    return ptr;
}

template<class T>
void unique_ptr<T>::reset() {
    T* temp=release();
    delete temp;

}
