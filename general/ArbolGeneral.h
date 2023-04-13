#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__

#include "NodoGeneral.h"

template <class T> class ArbolGeneral {
protected:
  NodoGeneral<T> *raiz;

public:
  ArbolGeneral();
  ArbolGeneral(T val);
  ~ArbolGeneral();
  bool empty();
  NodoGeneral<T> *getRaiz();
  void setRaiz(NodoGeneral<T> *n_raiz);
  bool insertNodo(T padre, T n);
  bool eliminarNodo(T n);
  bool buscar(T n);
  int altura();
  int altura(NodoGeneral<T>* nodo);
  unsigned int tamano();
  void preOrden();
  void preOrden(NodoGeneral<T> *nodo);
  void posOrden();
  void nivelOrden();
};

#include "ArbolGeneral.hxx"

#endif