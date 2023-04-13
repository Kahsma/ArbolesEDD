#include <iostream>
#include "ArbolGeneral.h"
int main() {
  ArbolGeneral<int>bst;
  bst.insertNodo(10,2);
  bst.insertNodo(2,3);
  bst.insertNodo(2,4);
  bst.insertNodo(2,5);
  bst.insertNodo(2,6);
  bst.insertNodo(3,15);
  bst.eliminarNodo(4);
  bst.preOrden();
  
}