#ifndef __NodoBinario_H__
#define __NodoBinario_H__


template<class T>
class NodoBinario{
  protected:
    T dato;
    NodoBinario<T>* hijoIzq;
    NodoBinario<T>* hijoDer;
  public:
    NodoBinario();
    NodoBinario(T val);
    ~NodoBinario();
    T obtenerDato();
    void fijarDato(T val);
    NodoBinario<T>* obtenerHijoIzquierdo();
    NodoBinario<T>* obtenerHijoDerecho();
    void fijarHijoIzq(NodoBinario<T>* izq);
    void fijarHijoDer(NodoBinario<T>* der);
    bool esHoja();
    int altura();
    void inOrder();
    void preOrder();
    void posOrder();
    int tamano();
    int height(NodoBinario<T>* node);
};

#include "NodoBinario.hxx"
  
#endif