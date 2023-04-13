#include "ArbolGeneral.h"
#include <queue>
template<class T>
ArbolGeneral<T>::ArbolGeneral(){
  this->raiz =NULL;
}

template<class T>
ArbolGeneral<T>::ArbolGeneral(T val){
  NodoGeneral<T>* nodo = new NodoGeneral<T>;
  nodo->setDato(val);
  this->raiz = nodo;
}
template<class T>
ArbolGeneral<T>::~ArbolGeneral(){
  delete this->raiz;
  this->raiz = NULL;
}

template<class T>
bool ArbolGeneral<T>::empty(){
  return this->raiz == NULL;
}

template<class T>
NodoGeneral<T>* ArbolGeneral<T>::getRaiz(){
  return this->raiz;
}

template<class T>
void ArbolGeneral<T>::setRaiz(NodoGeneral<T>* n_raiz){
  this->raiz = n_raiz;
}

template<class T>
bool ArbolGeneral<T>::insertNodo(T padre, T n){
  if (this->empty()) {
    // if the tree is empty, create a new root node with the given value
    NodoGeneral<T>* nodo = new NodoGeneral<T>;
    nodo->setDato(n);
    this->raiz = nodo;
    return true;
  }

  // find the node with the given value
  std::queue<NodoGeneral<T>*> q;
  q.push(this->raiz);
  while (!q.empty()) {
    NodoGeneral<T>* nodo = q.front();
    q.pop();
    if (nodo->getDato() == padre) {
      // if we found the parent node, insert the new node as its child
      NodoGeneral<T>* hijo = new NodoGeneral<T>;
      hijo->setDato(n);
      nodo->desc.push_back(hijo);
      return true;
    }
    for (typename std::list<NodoGeneral<T>*>::iterator it = nodo->desc.begin(); it != nodo->desc.end(); it++) {
      q.push(*it);
    }
  }

  // if the parent node wasn't found, return false
  return false;
}



template<class T>
bool ArbolGeneral<T>::eliminarNodo(T n){
  if (this->empty()) {
    return false;
  }

  // special case: the root node has the given value
  if (this->raiz->getDato() == n) {
    delete this->raiz;
    this->raiz = NULL;
    return true;
  }

  // find the parent node of the node to be deleted
  std::queue<NodoGeneral<T>*> q;
  q.push(this->raiz);
  while (!q.empty()) {
    NodoGeneral<T>* padre = q.front();
    q.pop();
    for (typename std::list<NodoGeneral<T>*>::iterator it = padre->desc.begin(); it != padre->desc.end(); it++) {
      NodoGeneral<T>* hijo = *it;
      if (hijo->getDato() == n) {
        // delete the child node and remove it from the parent's list of children
        delete hijo;
        padre->desc.erase(it);
        return true;
      }
      q.push(hijo);
    }
  }

  // if the node to be deleted wasn't found, return false
  return false;
}


template<class T>
bool ArbolGeneral<T>::buscar(T n){
  if (this->empty()) {
    return false;
  }
  std::queue<NodoGeneral<T>*> q;
  q.push(this->raiz);
  while (!q.empty()) {
    NodoGeneral<T>* nodo = q.front();
    q.pop();
    if (nodo->getDato() == n) {
      return true;
    }
    for (typename std::list<NodoGeneral<T>*>::iterator it = nodo->desc.begin(); it != nodo->desc.end(); it++) {
      q.push(*it);
    }
  }
  return false;
}




template<class T>
int ArbolGeneral<T>::altura(){
  if(this->empty()){
    return -1;
  }else{
    return this->altura(this->raiz);
  }
}

template<class T>
int ArbolGeneral<T>::altura(NodoGeneral<T>* nodo){
  int alt=-1;
  if(nodo->esHoja()){
    alt = 0;
  }else{
    int alth;
    typename std::list< NodoGeneral<T>* >::iterator it;
    for(it=nodo->desc.begin();it!= nodo->desc.end();it++){
      alth = this->altura(*it);
      if(alt < alth+1)
        alt = alth+1;
    }
  }
  return alt ;
}

template<class T>
unsigned int ArbolGeneral<T>::tamano(NodoGeneral<T>* nodo){
  if (nodo == NULL) {
    return 0;
  }
  unsigned int count = 1;
  typename std::list< NodoGeneral<T>* >::iterator it;
  for(it = nodo->desc.begin(); it != nodo->desc.end(); it++){
    count += tamano(*it);
  }
  return count;
}

template<class T>
void ArbolGeneral<T>::preOrden(){

  if(!this->empty()){

    this->preOrden(this->raiz);
    
  }
}

template<class T>
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo){

  std::cout << nodo->getDato()  <<" ";
  typename std::list< NodoGeneral<T>* >::iterator it;
  for(it= nodo->desc.begin() ; it!= nodo->desc.end();it++){

    preOrden(*it);
    
  }
  
}

template<class T>
void ArbolGeneral<T>::posOrden(){
  
}

template<class T>
void ArbolGeneral<T>::nivelOrden(){
  
}
