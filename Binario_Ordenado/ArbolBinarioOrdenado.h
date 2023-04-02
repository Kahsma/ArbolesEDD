#ifndef _ARBOLBINARIOORDENADO_H___
#define _ARBOLBINARIOORDENADO_H___
#include "NodoBinario.h"
template <class T>
class ArbolBinarioOrdenado
{
protected:
    NodoBinario<T> *raiz;

public:
    ArbolBinarioOrdenado();
    ~ArbolBinarioOrdenado();
    bool esVacio();
    T datoRaiz();
    int altura();
    int altura(NodoBinario<T> *nodo);
    int tamano();
    bool insertar(T val);
    bool eliminar(T val);
    bool buscar(T val);
    void preorden();
    void inOrden();
    void posOrden();
    void nivelorden();
};
#include "ArbolBinarioOrdenado.hxx"
#endif