#ifndef _Nodo_Quad_H_
#define _Nodo_Quad_H_
#include "punto.h"
class NodoQuad {
    protected:
    punto dato;
    NodoQuad* hijoSupIzq;
    NodoQuad* hijoSupDer;
    NodoQuad* hijoInfIzq;
    NodoQuad* hijoInfDer;
    public:
    NodoQuad();
    NodoQuad(punto val);
    ~NodoQuad();
    punto obtenerDato();
    void fijarDato(punto val);
    NodoQuad* obtenerHijoSupIzq();
    NodoQuad* obtenerHijoSupDer();
    NodoQuad* obtenerHijoInfIzq();
    NodoQuad* obtenerHijoInfDer();
    void fijarHijoSupIzq(NodoQuad* sizq);
    void fijarHijoSupDer(NodoQuad* sder);
    void fijarHijoInfIzq(NodoQuad* iizq);
    void fijarHijoInfDer(NodoQuad* ider);
    bool esHoja();
};

#include "NodoQuad.hxx"
#endif