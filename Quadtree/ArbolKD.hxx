#include "ArbolKD.h"
#include <queue>
#include <iostream>

ArbolKD::ArbolKD() {
    raiz = nullptr;
}

ArbolKD::ArbolKD(punto val) {
    raiz = new NodoKD(val);
}

ArbolKD::~ArbolKD() {
    delete raiz;
}

punto ArbolKD::datoRaiz() {
    return raiz->obtenerDato();
}

NodoKD* ArbolKD::obtenerRaiz() {
    return raiz;
}

void ArbolKD::fijarRaiz(NodoKD* n_raiz) {
    raiz = n_raiz;
}

bool ArbolKD::esVacio() {
    return raiz == nullptr;
}

bool ArbolKD::insertar(punto val) {
    if (raiz == nullptr) {
        raiz = new NodoKD(val);
        return true;
    } else {
        NodoKD* padre = nullptr;
        NodoKD* actual = raiz;
        bool enIzq = true;
        while (actual != nullptr) {
            if (actual->obtenerDato() == val) {
                return false;
            }
            padre = actual;
            if (enIzq) {
                if (val.x < actual->obtenerDato().x) {
                    actual = actual->obtenerHijoIzq();
                } else {
                    actual = actual->obtenerHijoDer();
                    enIzq = false;
                }
            } else {
                if (val.y < actual->obtenerDato().y) {
                    actual = actual->obtenerHijoIzq();
                } else {
                    actual = actual->obtenerHijoDer();
                    enIzq = true;
                }
            }
        }
        NodoKD* nuevoNodo = new NodoKD(val);
        if (enIzq) {
            padre->fijarHijoIzq(nuevoNodo);
        } else {
            padre->fijarHijoDer(nuevoNodo);
        }
        return true;
    }
}

void preOrdenAux(NodoKD* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->obtenerDato() << " ";
        preOrdenAux(nodo->obtenerHijoIzq());
        preOrdenAux(nodo->obtenerHijoDer());
    }
}

void ArbolKD::preOrden() {
    preOrdenAux(raiz);
}

void inOrdenAux(NodoKD* nodo) {
    if (nodo != nullptr) {
        inOrdenAux(nodo->obtenerHijoIzq());
        std::cout << nodo->obtenerDato() << " ";
        inOrdenAux(nodo->obtenerHijoDer());
    }
}

void ArbolKD::inOrden() {
    inOrdenAux(raiz);
}

void posOrdenAux(NodoKD* nodo) {
    if (nodo != nullptr) {
        posOrdenAux(nodo->obtenerHijoIzq());
        posOrdenAux(nodo->obtenerHijoDer());
        std::cout << nodo->obtenerDato() << " ";
    }
}

void ArbolKD::posOrden() {
    posOrdenAux(raiz);
}
/**
 * Recorre el árbol en orden por niveles
 */
void nivelOrdenAux(NodoKD* nodo) {
    if (!nodo) {
        return;
    }
    std::queue<NodoKD*> cola;
    cola.push(nodo);
    while (!cola.empty()) {
        NodoKD* nodoActual = cola.front();
        std::cout << nodoActual->obtenerDato() << " ";
        cola.pop();
        if (nodoActual->obtenerHijoIzq()) {
            cola.push(nodoActual->obtenerHijoIzq());
        }
        if (nodoActual->obtenerHijoDer()) {
            cola.push(nodoActual->obtenerHijoDer());
        }
    }
}

/**
 * Recorre el árbol en orden por niveles
 */
void ArbolKD::nivelOrden() {
    nivelOrdenAux(raiz);
}