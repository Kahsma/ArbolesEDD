#ifndef __ArbolBinarioOrd_H__
#define __ArbolBinarioOrd_H__

#include "NodoBinario.h"

template<class T>
class ArbolBinarioOrd{
  protected:
    NodoBinario<T> *raiz;
  public:
    ArbolBinarioOrd();
    ~ArbolBinarioOrd();
    bool esVacio();
    T DatoRaiz();
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
    int altura();
    int altura(NodoBinario<T>* nodo);
    int tamano();
    int tamanoRecursivo(NodoBinario<T> *nodo) const;
    int tamano(NodoBinario<T>* nodo);
    void preOrden();
    void preOrden(NodoBinario<T>* nodo);
    void posOrden();
    void posOrden(NodoBinario<T>* nodo);
    void nivelOrden();
    void inOrden();
    void inOrden(NodoBinario<T>* nodo);
    NodoBinario<T> encontrarMaximo(NodoBinario<T>* nodo);
};

#include "ArbolBinarioOrd.hxx"
  
#endif