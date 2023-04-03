#include "ArbolBinarioOrd.h"

#include <queue>

template<class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
  this->raiz = NULL;
}

template<class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
  if (this->raiz != NULL){
    delete this->raiz;
    this->raiz = NULL;
  }
  
}

template<class T>
bool ArbolBinarioOrd<T>::esVacio(){
  return this->raiz == NULL;
}

template<class T>
T ArbolBinarioOrd<T>::DatoRaiz(){
  return (this->raiz)->obtenerDato();
}



template<class T>
bool ArbolBinarioOrd<T>::insertar(T val){
  NodoBinario<T>* nodo = this->raiz;
  NodoBinario<T>* padre = this->raiz;
  bool insertado = false;
  bool duplicado = false;
  if(this->esVacio()){
    NodoBinario<T>* nuevo = new NodoBinario<T>(val);
    this->raiz = nuevo;
    return insertado = true;
  }
  while(nodo != NULL ){
    padre = nodo;
    if(val < nodo->obtenerDato()){
      nodo = nodo->obtenerHijoIzquierdo();
    }else if(val > nodo->obtenerDato()){
      nodo = nodo->obtenerHijoDerecho();
    }else{
      duplicado = true;
      break;
    }
  }
  if(!duplicado){
    NodoBinario<T>* nuevo = new NodoBinario<T>(val);
      if(nuevo != NULL){
        if(val < padre->obtenerDato()){
          padre->fijarHijoIzq(nuevo);
        }else{
          padre->fijarHijoDer(nuevo);
        }
      }
    insertado = true;
  }
  return insertado;
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val)
{
    NodoBinario<T> *nodo = this->raiz;
    NodoBinario<T> *padre = NULL;
    bool encontrado = false;

    while (nodo != NULL && !encontrado)
    {
        if (val < nodo->getDato())
        {
            padre = nodo;
            nodo = nodo->getHijoIzq();
        }
        else if (val > nodo->getDato())
        {
            padre = nodo;
            nodo = nodo->getHijoDer();
        }
        else
        {
            encontrado = true;
        }
    }

    if (encontrado)
    {
        // Check if the node to be deleted has at most one child
        if (nodo->getHijoIzq() == NULL || nodo->getHijoDer() == NULL)
        {
            NodoBinario<T> *hijo = NULL;
            if (nodo->getHijoIzq() != NULL)
            {
                hijo = nodo->getHijoIzq();
            }
            else
            {
                hijo = nodo->getHijoDer();
            }

            if (padre == NULL)
            {
                this->raiz = hijo;
            }
            else if (padre->getHijoIzq() == nodo)
            {
                padre->setHijoIzq(hijo);
            }
            else
            {
                padre->setHijoDer(hijo);
            }

            delete nodo;
            nodo = NULL;
        }
        else // Node to be deleted has two children
        {
            NodoBinario<T> *sucesor = nodo->getHijoDer();
            padre = NULL;
            while (sucesor->getHijoIzq() != NULL)
            {
                padre = sucesor;
                sucesor = sucesor->getHijoIzq();
            }

            nodo->setDato(sucesor->getDato());

            if (padre != NULL)
            {
                padre->setHijoIzq(sucesor->getHijoDer());
            }
            else
            {
                nodo->setHijoDer(sucesor->getHijoDer());
            }

            delete sucesor;
            sucesor = NULL;
        }

        return true;
    }

    return false;
}

template<class T>
bool ArbolBinarioOrd<T>::buscar(T val){
  NodoBinario<T>* nodo = this->raiz;
  bool encontrado = false;

  while(nodo != NULL && !encontrado){
    if(val < nodo->obtenerDato()){
      nodo = nodo->obtenerHijoIzquierdo();
    }else if(val > nodo->obtenerDato()){
      nodo = nodo->obtenerHijoDerecho();
    }else{
      encontrado = true;
    }
  }
  return encontrado;
}

template<class T>
int ArbolBinarioOrd<T>::altura(){
  if(this->esVacio()){
    return -1;
  }else{
    return this->altura(this->raiz);
  }
}

template<class T>
int ArbolBinarioOrd<T>::altura(NodoBinario<T>* nodo){
  int alt=-1;
  if(nodo->esHoja()){
    alt = 0;
  }else{
    int alt_izq =-1;
    int alt_der =-1;
    if (nodo->obtenerHijoIzquierdo()!=NULL)
      alt_izq = this->altura(nodo->obtenerHijoIzquierdo());
    if (nodo->obtenerHijoDerecho()!=NULL)
      alt_der = this->altura(nodo->obtenerHijoDerecho());
    if(alt_izq > alt_der){
      alt = alt_izq +1;
    }else{
      alt = alt_der +1;
    }
  }
  return alt ;
}

template<class T>
int ArbolBinarioOrd<T>::tamano(){
  return 0;
}

// template<class T>
// void ArbolBinarioOrd<T>::preOrden(){

//   if(!this->esVacio())
//     this->preOrden(this->raiz);
// }

// template<class T>
// void ArbolBinarioOrd<T>::preOrden(NodoBinario<T>* nodo){
  
//   if(nodo!=NULL){
//     std::cout<< nodo->obtenerDato() <<" ";
//     this->preOrden(nodo->obtenerHijoIzquierdo());
    
//     this->preOrden(nodo->obtenerHijoDerecho());
//   }
  
// }

// template<class T>
// void ArbolBinarioOrd<T>::posOrden(){
//   if(!this->esVacio())
//     this->posOrden(this->raiz);
// }

// template<class T>
// void ArbolBinarioOrd<T>::posOrden(NodoBinario<T>* nodo){
//   if(nodo!=NULL){
    
//     this->posOrden(nodo->obtenerHijoIzquierdo());
//     this->posOrden(nodo->obtenerHijoDerecho());
//     std::cout<< nodo->obtenerDato() <<" ";
//   }
// }

template <class T>
void ArbolBinarioOrd<T>::preOrden()
{
    if (!this->esVacio())
    {
        this->raiz->preOrder();
    }
}

template <class T>
void ArbolBinarioOrd<T>::inOrden()
{
    if (!this->esVacio())
    {
        this->raiz->inOrder();
    }
}

template <class T>
void ArbolBinarioOrd<T>::posOrden()
{
    {
        if (!this->esVacio())
        {
            this->raiz->posOrder();
        }
    }
}

template<class T>
void ArbolBinarioOrd<T>::nivelOrden(){
  if(!this->esVacio()){
    std::queue< NodoBinario<T>* > cola;
    cola.push(this->raiz);
    NodoBinario<T>* nodo;
    while(!cola.empty()){
      nodo = cola.front();
      cola.pop();
      std::cout<< nodo->obtenerDato() <<" ";
      if(nodo->obtenerHijoIzquierdo() != NULL)
        cola.push(nodo->obtenerHijoIzquierdo());
      
      if(nodo->obtenerHijoDerecho() != NULL)
        cola.push(nodo->obtenerHijoDerecho());
      
    }
  }
    
}

// template<class T>
// void ArbolBinarioOrd<T>::inOrden(){
//   if(!this->esVacio())
//     this->inOrden(this->raiz);
// }

// template<class T>
// void ArbolBinarioOrd<T>::inOrden(NodoBinario<T>* nodo){
//   if(nodo!=NULL){
//     this->inOrden(nodo->obtenerHijoIzquierdo());
//     std::cout<< nodo->obtenerDato() <<" ";
//     this->inOrden(nodo->obtenerHijoDerecho());
//   }
// }

template<class T>
NodoBinario<T> ArbolBinarioOrd<T>::encontrarMaximo(NodoBinario<T>* nodo) {
  if (nodo == NULL) {
    return T(); 
  }
  while (nodo->obtenerHijoDerecho() != NULL) {
    nodo = nodo->obtenerHijoDerecho();
  }
  return nodo;

}
