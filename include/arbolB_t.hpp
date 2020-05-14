#pragma once

#include <iostream>
#include <deque>
#include "nodos.hpp"
#include "dni_t.hpp"


typedef std::deque<std::pair<nodoB_t<dni_t>*, int>> cola_t;
typedef std::pair<nodoB_t<dni_t>*, int> pair_t;

template<class T>
class arbolB_t {
 
 private:
  nodoB_t<T>* raiz_ = nullptr;

 public:
  arbolB_t() = default;
  ~arbolB_t();

  inline const int Tam() { return TamRama(getRaiz()); }  
  inline const int Altura(nodoB_t<T>* nodo) { return AlturaNodo(getRaiz()); }  
  void RecorreNiveles(nodoB_t<T>* nodo);
  inline bool EsHoja(nodoB_t<T>* nodo) { return nodo->isLeaf(); }
  inline bool EsVacio(nodoB_t<T>* nodo) { return !nodo; }
  //Recorridos
  void writeRecorrido(int);
  void PreOrden(nodoB_t<T>* nodo);
  void InOrden(nodoB_t<T>* nodo);
  void PostOrden(nodoB_t<T>* nodo);
  void Muestra(nodoB_t<T>* nodo);  

  //Modoficación:  
  inline const bool Equilibrado() { return EquilibrioRama( this->getRaiz() ); }

 protected:
  const bool EquilibrioRama( nodoB_t<T>* nodo);
  inline nodoB_t<T>* &getRaiz() { return raiz_; }
  void setRaiz( nodoB_t<T>* nodo) { raiz_ = nodo; }
  void Podar(nodoB_t<T>* &nodo);
  const int TamRama(nodoB_t<T>* nodo);
  const int AlturaNodo(nodoB_t<T>* nodo);  

};



template<class T>
const bool arbolB_t<T>::EquilibrioRama( nodoB_t<T>* nodo ) {
  if(!nodo) return true;
  int eq = TamRama (nodo->left_ptr()) - TamRama(nodo->right_ptr());

  switch (eq) {
    case -1: 
    case 0:
    case 1:
    return EquilibrioRama(nodo->left_ptr()) && EquilibrioRama(nodo->right_ptr());
    default: return false;
    break;
    }
  }

template<class T>
arbolB_t<T>::~arbolB_t() {
  Podar( raiz_);
}

template<class T>
void arbolB_t<T>::Podar(nodoB_t<T>* &nodo) {
  if(!nodo)  { return; }
  Podar(nodo->left_ptr());
  Podar(nodo->right_ptr());
  delete nodo;
  nodo = nullptr;
}

template<class T>
const int arbolB_t<T>::TamRama(nodoB_t<T>* nodo) {
  if(!nodo) return 0;
  return (1+TamRama(nodo->left_ptr()) + TamRama(nodo->right_ptr()));
}

template<class T>
const int arbolB_t<T>::AlturaNodo(nodoB_t<T>* nodo) {
  if(!nodo) return 0;
  int AlturaIzquierda = AlturaNodo(nodo->left_ptr());
  int AlturaDerecha = AlturaNodo(nodo->right_ptr()); 

  if(AlturaDerecha > AlturaIzquierda)
    return AlturaDerecha++;
  else
    return AlturaIzquierda++;
}

template<class T>
void arbolB_t<T>::RecorreNiveles(nodoB_t<T>* nodo) {
  cola_t Q;

  nodoB_t<T> *aux;
  int nivel = 0, nivel_actual = 0;
  
  Q.push_back(std::move(pair_t(nodo, 0)));
  std::cout << "\nNivel 0: ";

  while(!Q.empty()) {
    aux = Q.front().first;
    nivel = Q.front().second;
    Q.pop_front();
    if (nivel > nivel_actual) {
      nivel_actual = nivel;
      std::cout << "\nNivel " << nivel_actual << ":";
    }
    Muestra(aux);
    if(aux) {
      Q.push_back(pair_t(aux->left_ptr(), nivel + 1));
      Q.push_back(pair_t(aux->right_ptr(), nivel + 1));
    }
  }
}




template<class T>
void arbolB_t<T>::writeRecorrido(int opt) {
  
  switch (opt) {
    case 1:
      PreOrden(getRaiz()); break;
    case 2:
      InOrden(getRaiz()); break;
    case 3:
      PostOrden(getRaiz()); break;
    case 4:
      RecorreNiveles( getRaiz() ); break;
    default:
      RecorreNiveles( getRaiz() ); break;
  }
  std::cout << "\n\n";
}

//Especialización de tipo de dato para clave dni_t
/////////////////////////////////////////////////////////////////////
template<class T>
void arbolB_t<T>::PreOrden(nodoB_t<T>* nodo) {
  if(!nodo) return;
  
  std::cout << "[";
  std::cout << nodo->get_data();
  std::cout << "]";
  PreOrden(nodo->left_ptr());
  PreOrden(nodo->right_ptr());
}
template<>
void arbolB_t<dni_t>::PreOrden(nodoB_t<dni_t>* nodo) {
  if(!nodo) return;

  std::cout << "[";
  nodo->get_data().printDni(std::cout);
  std::cout << "]";
  PreOrden(nodo->left_ptr());
  PreOrden(nodo->right_ptr());
}
/////////////////////////////////////////////////////////////////////
template<class T>
void arbolB_t<T>::InOrden(nodoB_t<T>* nodo) {
  if(!nodo) return;
  InOrden(nodo->left_ptr());
  std::cout << "[";
  std::cout << nodo->get_data();
  std::cout << "]";
  InOrden(nodo->right_ptr());  
}
template<>
void arbolB_t<dni_t>::InOrden(nodoB_t<dni_t>* nodo) {
  if(!nodo) return;
  InOrden(nodo->left_ptr());
  std::cout << "[";
  nodo->get_data().printDni(std::cout);
  std::cout << "]";
  InOrden(nodo->right_ptr());  
}
/////////////////////////////////////////////////////////////////////
template<class T>
void arbolB_t<T>::PostOrden(nodoB_t<T>* nodo) {
  if(!nodo) return;
  PostOrden(nodo->left_ptr());
  PostOrden(nodo->right_ptr());
  std::cout << "[";
  std::cout << nodo->get_data();
  std::cout << "]";  

}
template<>
void arbolB_t<dni_t>::PostOrden(nodoB_t<dni_t>* nodo) {
  if(!nodo) return;
  PostOrden(nodo->left_ptr());
  PostOrden(nodo->right_ptr());
  std::cout << "[";
  nodo->get_data().printDni(std::cout);
  std::cout << "]";  
}

///////////////////////////////////////////////////////////////////////
template<class T>
void arbolB_t<T>::Muestra(nodoB_t<T>* nodo){
  if(!nodo) std::cout << "[.]";
  else {
    std::cout << "[";
    std::cout << nodo->get_data();
    std::cout << "]";
  }
}

template<>
void arbolB_t<dni_t>::Muestra(nodoB_t<dni_t>* nodo){
  if(!nodo) std::cout << "[.]";
  else {
    std::cout << "[";
    nodo->get_data().printDni(std::cout);
    std::cout << "]";
  }
}