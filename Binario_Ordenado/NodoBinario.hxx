#include "NodoBinario.h"

template <class T>
NodoBinario<T>::NodoBinario()
{
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}
template <class T>
NodoBinario<T>::NodoBinario(T val)
{
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->data = val;
}

template <class T>
NodoBinario<T>::~NodoBinario()
{
    if (this->hijoIzq != NULL)
    {
        delete this->hijoIzq;
        this->hijoIzq = NULL;
    }
    if (this->hijoDer != NULL)
    {

        delete this->hijoDer;
        this->hijoDer = NULL;
    }
}

template <class T>
T NodoBinario<T>::getDato()
{
    return this->data;
}

template <class T>
void NodoBinario<T>::setDato(T val)
{
    this->data = val;
}

template <class T>
NodoBinario<T> *NodoBinario<T>::getHijoIzq()
{
    return this->hijoIzq;
}

template <class T>
NodoBinario<T> *NodoBinario<T>::getHijoDer()
{
    return this->hijoDer;
}

template <class T>
void NodoBinario<T>::setHijoIzq(NodoBinario<T> *izq)
{
    this->hijoIzq = izq;
}

template <class T>
void NodoBinario<T>::setHijoDer(NodoBinario<T> *der)
{
    this->hijoDer = der;
}
template <class T>
bool NodoBinario<T>::esHoja()
{
    return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

template <class T>
int NodoBinario<T>::altura()
{
    int valt if (this->esHoja())
    {
        valt = 0;
    }
    else
    {
        int vlat_izq = -1;
        int vlat_der = -1;
        if (this->hijoIzq ! = NULL)
        {
            valt_izq = (this->hijoIzq)->altura();
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
