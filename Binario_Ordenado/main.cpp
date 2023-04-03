#include <iostream>
#include "ArbolBinarioOrd.h"
int main() {
  ArbolBinarioOrd<int> bst;
  
  

  bst.insertar(10);

  bst.insertar(5);

  bst.insertar(15);

  bst.insertar(3);

  bst.insertar(7);

  //std::cout << "Maximum value in subtree rooted at 10: " << bst.buscar(10) << std::endl;
bst.inOrden();
  std::cout  << std::endl;
bst.preOrden();
  std::cout  << std::endl;
bst.nivelOrden();
  std::cout  << std::endl;
std::cout<< '\n' + bst.tamano()<<std::endl;
}