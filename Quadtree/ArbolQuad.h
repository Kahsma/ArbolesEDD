#ifndef _Arbol_Quad_H_
#define _Arbol_Quad_H_
#include "NodoQuad.h"
class ArbolQuad {
    protected:
    NodoQuad* raiz;
    public:
    ArbolQuad();
    ArbolQuad(punto val);
    ~ArbolQuad();
    punto datoRaiz();
    NodoQuad* obtenerRaiz();
    void fijarRaiz(NodoQuad* n_raiz);
    bool esVacio();
    bool insertar(punto val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolQuad.hxx"

#endif