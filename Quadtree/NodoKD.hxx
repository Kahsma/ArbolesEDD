#include "NodoKD.h"

NodoKD::NodoKD() {
    hijoIzq = NULL;
    hijoDer = NULL;
}

NodoKD::NodoKD(punto val) {
    dato = val;
    hijoIzq = NULL;
    hijoDer = NULL;
}

NodoKD::~NodoKD() {
    delete hijoIzq;
    delete hijoDer;
}

bool NodoKD::esHoja() {
    return (hijoIzq == NULL && hijoDer == NULL);
}

punto NodoKD::obtenerDato() {
    return dato;
}

void NodoKD::fijarDato(punto val) {
    dato = val;
}

NodoKD* NodoKD::obtenerHijoIzq() {
    return hijoIzq;
}

NodoKD* NodoKD::obtenerHijoDer() {
    return hijoDer;
}

void NodoKD::fijarHijoIzq(NodoKD* izq) {
    hijoIzq = izq;
}

void NodoKD::fijarHijoDer(NodoKD* der) {
    hijoDer = der;
}