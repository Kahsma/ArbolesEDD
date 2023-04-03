#include "NodoBinario.h"

template<class T>
NodoBinario<T>::NodoBinario(){
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
}

template<class T>
NodoBinario<T>::NodoBinario(T val){
  this->hijoIzq = NULL;
  this->hijoDer = NULL;
  this->dato = val;
}

template<class T>
NodoBinario<T>::~NodoBinario(){
  if(hijoIzq != NULL){
    delete hijoIzq;
    this->hijoIzq = NULL;
  }
  if(hijoDer != NULL){
    delete hijoDer;
    this->hijoDer = NULL;
  }
  
  
}
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzquierdo(){
  return this->hijoIzq;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDerecho(){
  return this->hijoDer;
}

template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq){
  this->hijoIzq = izq;
}

template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der){
  this->hijoDer = der;
}

template<class T>
T NodoBinario<T>::obtenerDato(){
  return this->dato;
}

template<class T>
void NodoBinario<T>::fijarDato(T val){
  this->dato = val;
}

template<class T>
bool NodoBinario<T>::esHoja(){
  return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

template <class T>
int NodoBinario<T>::altura()
{
    int valt;
    if (this->esHoja())
    {
        valt = 0;
    }
    else
    {
        int valt_izq = -1;
        int valt_der = -1;
        if (this->hijoIzq != NULL)
        {
            valt_izq = this->hijoIzq->altura();
        }
        if (this->hijoDer != NULL)
        {
            valt_der = (this->hijoDer)->altura();
        }
        if (valt_izq > valt_der)
        {
            valt = valt_izq + 1;
        }
        else
        {
            valt = valt_der + 1;
        }
    }
    return valt;
}


template <class T>
void NodoBinario<T>::inOrder()
{
    if (hijoIzq != NULL)
    {
        this->hijoIzq->inOrder();
    }
    std::cout << this->dato << " ";
    if (hijoDer != NULL)
    {
        this->hijoDer->inOrder();
    }
}

template <class T>
void NodoBinario<T>::preOrder()
{
    std::cout << this->dato << " ";
    if (hijoIzq != NULL)
    {
        this->hijoIzq->inOrder();
    }
    if (hijoDer != NULL)
    {
        this->hijoDer->inOrder();
    }
}



template <class T>
void NodoBinario<T>::posOrder()
{
    if (hijoIzq != NULL)
    {
        this->hijoIzq->inOrder();
    }
    if (hijoDer != NULL)
    {
        this->hijoDer->inOrder();
    }
    std::cout << this->dato << " ";
}

// template<class T>
// int NodoBinario<T>::tamano() {
//     if (node == NULL) {
//         return 0;
//     } else {
//         int left_height = height(node->obtenerHijoIzquierdo());
//         int right_height = height(node->obtenerHijoDerecho());
//         return 1 + std::max(left_height, right_height);
//     }
// }
template <class T>
int height(NodoBinario<T>* node)
{
    if (node == NULL) {
        return 0;
    } else {
        int left_height = height(node->obtenerHijoIzquierdo());
        int right_height = height(node->obtenerHijoDerecho());
        return 1 + std::max(left_height, right_height);
    }
}



