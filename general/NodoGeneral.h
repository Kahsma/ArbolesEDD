#ifndef __NodoGeneral_H__
#define __NodoGeneral_H__

#include <list>

template<class T>
class NodoGeneral{
  protected:
    T dato;
    
  public:
    std::list< NodoGeneral<T>* > desc;
    NodoGeneral();
    ~NodoGeneral();
    T& getDato();
    void setDato(T& val);
    void clearList();
    void adicionarDesc(T& nval);
    bool eliminarDesc(T& val);
    bool esHoja();
};

#include "NodoGeneral.hxx"
  
#endif