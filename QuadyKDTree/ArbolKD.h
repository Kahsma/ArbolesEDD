#ifndef _Arbol_KD_H_
#define _Arbol_KD_H_
#include "NodoKD.h"
class ArbolKD {
    protected:
        NodoKD* raiz;
    public:
        ArbolKD();
        ArbolKD(punto val);
        ~ArbolKD();
        punto datoRaiz();
        NodoKD* obtenerRaiz();
        void fijarRaiz(NodoKD* n_raiz);
        bool esVacio();
        bool insertar(punto val);
        void preOrden();
        void inOrden();
        void posOrden();
        void nivelOrden();
};
#include "ArbolKD.hxx"
#endif
