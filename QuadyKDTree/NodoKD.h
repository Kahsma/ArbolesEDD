#ifndef _Nodo_KD_H_
#define _Nodo_KD_H_
#include "punto.h"
class NodoKD {
    protected:
        punto dato;
        NodoKD* hijoIzq;
        NodoKD* hijoDer;
    public:
        NodoKD();
        NodoKD(punto val);
        ~NodoKD();
        bool esHoja();
        punto obtenerDato();
        void fijarDato(punto val);
        NodoKD* obtenerHijoIzq();
        NodoKD* obtenerHijoDer();
        void fijarHijoIzq(NodoKD* izq);
        void fijarHijoDer(NodoKD* der);
};

#include "NodoKD.hxx"
#endif