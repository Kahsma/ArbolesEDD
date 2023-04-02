#ifndef _ARBOLBINARIOORD_H___
#define ARBOLBINARIOORD_H___
#include "NodoBinario.h"
template <class T>
class ArbolBinarioOrd
{
protected:
    NodoBinario<T> **raiz;

public:
    ArbolBinarioOrd();
    - ArbolBinario0rd();
    bool esVacio();
    T datoRaiz();
    int altura();
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