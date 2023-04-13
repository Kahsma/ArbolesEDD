#include "ArbolKD.h"
#include <iostream>
using namespace std;

int main() {
    // Creamos un árbol KD y lo inicializamos con un punto
    ArbolKD arbol(punto{5, 2});

    // Insertamos más puntos en el árbol
    arbol.insertar(punto{3, 1});
    arbol.insertar(punto{7, 3});
    arbol.insertar(punto{2, 8});
    arbol.insertar(punto{6, 4});
    arbol.insertar(punto{1, 9});

    // Imprimimos el recorrido en preorden
    cout << "Recorrido en preorden:" << endl;
    arbol.preOrden();

    // Imprimimos el recorrido en inorden
    cout << "\nRecorrido en inorden:" << endl;
    arbol.inOrden();

    // Imprimimos el recorrido en posorden
    cout << "\nRecorrido en posorden:" << endl;
    arbol.posOrden();

    // Imprimimos el recorrido por niveles
    cout << "\nRecorrido por niveles:" << endl;
    arbol.nivelOrden();

    return 0;
}
