#include "NodoGeneral.h"


template<class T>
NodoGeneral<T>::NodoGeneral(){
  this->desc.clear();
}

template<class T>
NodoGeneral<T>::~NodoGeneral(){
  for(auto d : desc ){
    delete d;
  }
  this->desc.clear();
}

template<class T>
T& NodoGeneral<T>::getDato(){
  return this->dato;
}

template<class T>
void NodoGeneral<T>::setDato(T& val){
  this->dato = val;
}

template<class T>
void NodoGeneral<T>::clearList(){
  this->desc.clear();
}

template<class T>
void NodoGeneral<T>::adicionarDesc(T& nval){
  NodoGeneral<T> *nodo = new NodoGeneral<T>;
  nodo->setDato( nval );
  this-> desc.push_back(nodo);
}


template<class T>
bool NodoGeneral<T>::eliminarDesc(T& val){
  
  typename std::list< NodoGeneral<T>* >::iterator it;
  NodoGeneral<T> *aux;
  bool eliminado = false;
  for( it = this->desc.begin(); it!= this->desc.end() ;it++ ){
    aux = *it;
    if(aux->getDato() == val){
      break;
    }
  }
  if(it != this->desc.end()){
    delete *it;
    this->desc.erase(it);
    eliminado = true;
  }
  return eliminado;
}

template<class T>
bool NodoGeneral<T>::esHoja(){
  return this->desc.size() == 0;
}


