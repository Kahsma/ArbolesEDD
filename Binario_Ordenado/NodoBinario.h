#ifndef _NODOBINARIO_H_
#define _NODOBINARIO_H_
template <class T>
class NodoBinario
{
protected:
    T data;
    NodoBinario<T> hijoIzq;
    NodoBinario<T> hijoDer;

public:
    NodoBinario();
    NodoBinario(T Val);
    ~NodoBinario();
    T getDato();
    void setDato(T val);
    NodoBinario<T> *getHijoIzq();
    NodoBinario<T> *getHijoDer();
    void setHijoIzq(NodoBinario<T> *izq);
    void setHijoDer(NodoBinario<T> *der);
    bool esHoja();
    int altura();
};
#include "NodoBinario.hxx"

#endif