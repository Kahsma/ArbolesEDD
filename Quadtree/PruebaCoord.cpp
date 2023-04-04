#include <iostream>
#include "ArbolQuad.h"

int main() {
    ArbolQuad arbol;

    // Insertamos algunos puntos en el árbol
    arbol.insertar({10, 20});
    arbol.insertar({5, 15});
    arbol.insertar({30, 25});
    arbol.insertar({7, 12});
    arbol.insertar({18, 22});

    // Imprimimos el árbol en diferentes órdenes
    std::cout << "Recorrido en preorden: ";
    arbol.preOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en inorden: ";
    arbol.inOrden();
    std::cout << std::endl;

    std::cout << "Recorrido en postorden: ";
    arbol.posOrden();
    std::cout << std::endl;

    std::cout << "Recorrido por niveles: ";
    arbol.nivelOrden();
    std::cout << std::endl;

    return 0;
}