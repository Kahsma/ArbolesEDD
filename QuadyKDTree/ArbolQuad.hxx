#include "ArbolQuad.h"
#include <iostream>
#include <queue>

using namespace std;

ArbolQuad::ArbolQuad() {
    raiz = NULL;
}

ArbolQuad::ArbolQuad(punto val) {
    raiz = new NodoQuad(val);
}

ArbolQuad::~ArbolQuad() {}

punto ArbolQuad::datoRaiz() {
    return raiz->obtenerDato();
}

NodoQuad* ArbolQuad::obtenerRaiz() {
    return raiz;
}

void ArbolQuad::fijarRaiz(NodoQuad* n_raiz) {
    raiz = n_raiz;
}

bool ArbolQuad::esVacio() {
    return raiz == NULL;
}

bool ArbolQuad::insertar(punto val) {
    NodoQuad* nuevo = new NodoQuad(val);

    if (esVacio()) {
        fijarRaiz(nuevo);
        return true;
    }

    NodoQuad* padre = NULL;
    NodoQuad* actual = raiz;

    while (actual != NULL) {
        if (actual->obtenerDato() == val) {
            // El valor ya existe en el árbol
            delete nuevo;
            return false;
        }

        padre = actual;

        if (val.x < actual->obtenerDato().x) {
            if (val.y < actual->obtenerDato().y) {
                actual = actual->obtenerHijoInfIzq();
            } else {
                actual = actual->obtenerHijoSupIzq();
            }
        } else {
            if (val.y < actual->obtenerDato().y) {
                actual = actual->obtenerHijoInfDer();
            } else {
                actual = actual->obtenerHijoSupDer();
            }
        }
    }

    if (val.x < padre->obtenerDato().x) {
        if (val.y < padre->obtenerDato().y) {
            padre->fijarHijoInfIzq(nuevo);
        } else {
            padre->fijarHijoSupIzq(nuevo);
        }
    } else {
        if (val.y < padre->obtenerDato().y) {
            padre->fijarHijoInfDer(nuevo);
        } else {
            padre->fijarHijoSupDer(nuevo);
        }
    }

    return true;
}


void preOrdenAux(NodoQuad* nodo) {
    if (nodo == NULL) {
        return;
    }

    cout << nodo->obtenerDato() << " ";
    preOrdenAux(nodo->obtenerHijoInfIzq());
    preOrdenAux(nodo->obtenerHijoInfDer());
    preOrdenAux(nodo->obtenerHijoSupIzq());
    preOrdenAux(nodo->obtenerHijoSupDer());
}

void inOrdenAux(NodoQuad* nodo) {
    if (nodo == NULL) {
        return;
    }

    inOrdenAux(nodo->obtenerHijoInfIzq());
    cout << nodo->obtenerDato() << " ";
    inOrdenAux(nodo->obtenerHijoInfDer());
    inOrdenAux(nodo->obtenerHijoSupIzq());
    inOrdenAux(nodo->obtenerHijoSupDer());
}

void posOrdenAux(NodoQuad* nodo) {
    if (nodo != NULL) {
        posOrdenAux(nodo->obtenerHijoSupIzq());
        posOrdenAux(nodo->obtenerHijoSupDer());
        posOrdenAux(nodo->obtenerHijoInfIzq());
        posOrdenAux(nodo->obtenerHijoInfDer());
        std::cout << nodo->obtenerDato() << " ";
    }
}

void ArbolQuad::nivelOrden() {
    if (raiz == NULL) {
        return;
    }
    std::queue<NodoQuad*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        NodoQuad* actual = cola.front();
        std::cout << actual->obtenerDato() << " ";
        cola.pop();
        if (actual->obtenerHijoSupIzq() != NULL) {
            cola.push(actual->obtenerHijoSupIzq());
        }
        if (actual->obtenerHijoSupDer() != NULL) {
            cola.push(actual->obtenerHijoSupDer());
        }
        if (actual->obtenerHijoInfIzq() != NULL) {
            cola.push(actual->obtenerHijoInfIzq());
        }
        if (actual->obtenerHijoInfDer() != NULL) {
            cola.push(actual->obtenerHijoInfDer());
        }
    }
}

NodoQuad* buscarAux(punto val, NodoQuad* nodo) {
    if (nodo == NULL) {
        return NULL;
    }
    if (nodo->obtenerDato() == val) {
        return nodo;
    }
    if (val.x < nodo->obtenerDato().x) {
        if (val.y < nodo->obtenerDato().y) {
            return buscarAux(val, nodo->obtenerHijoSupIzq());
        } else {
            return buscarAux(val, nodo->obtenerHijoInfIzq());
        }
    } else {
        if (val.y < nodo->obtenerDato().y) {
            return buscarAux(val, nodo->obtenerHijoSupDer());
        } else {
            return buscarAux(val, nodo->obtenerHijoInfDer());
        }
    }
}


inline void ArbolQuad::preOrden()
{
    preOrdenAux(raiz);
}

inline void ArbolQuad::inOrden()
{
    posOrdenAux(raiz);
}

inline void ArbolQuad::posOrden()
{
    posOrdenAux(raiz);
}

