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


