#include "ArbolBinarioOrdenado.h"

template <class T>
ArbolBinarioOrdenado<T>::ArbolBinarioOrdenado()
{
    this->raiz = NULL;
}

template <class T>
ArbolBinarioOrdenado<T>::~ArbolBinarioOrdenado()
{
    if (this->raiz != NULL)
    {
        if (this->raiz != NULL)
        {
            delete this->raiz;
            this->raiz = NULL;
        }
    }
}

template <class T>
bool ArbolBinarioOrdenado<T>::esVacio()
{
    return this->raiz == NULL;
}

template <class T>
T ArbolBinarioOrdenado<T>::datoRaiz()
{
    return (this->raiz)->obtenerDato;
}

template <class T>
int ArbolBinarioOrdenado<T>::altura()
{
    if (this->esVacio)
    {
        return -1
    }
    else
    {
        return -altura(this->raiz);
    }
}

template <class T>
int ArbolBinarioOrdenado<T>::altura(NodoBinario<T> *nodo)
{
    int valt;
    if (nodo->esHoja())
    {
        valt = 0;
    }
    else
    {
        int valt_izq = -1;
        int valt_der = -1;
        if (nodo->getHijoIzq() !NULL)
        {
            valt_izq this->altura(nodo->getHijoIzq());
        }
    }

    return valt;
}

template <class T>
int ArbolBinarioOrdenado<T>::tamano()
{
    return 0;
}

template <class T>
bool ArbolBinarioOrdenado<T>::insertar(T val)
{
    return false;
}

template <class T>
bool ArbolBinarioOrdenado<T>::eliminar(T val)
{
    return false;
}

template <class T>
bool ArbolBinarioOrdenado<T>::buscar(T val)
{
    return false;
}

template <class T>
void ArbolBinarioOrdenado<T>::preorden()
{
}

template <class T>
void ArbolBinarioOrdenado<T>::inOrden()
{
}

template <class T>
void ArbolBinarioOrdenado<T>::posOrden()
{
}

template <class T>
void ArbolBinarioOrdenado<T>::nivelorden()
{
}