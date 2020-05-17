#pragma once


#include "arbolB_t.hpp"




template <class T>
class arbolAVL_t : public arbolB_t<T> {

 private:
    

 public:

  void Rotacion_II(nodoB_t<T>* &nodo);
  void Rotacion_DD(nodoB_t<T>* &nodo);
  void Rotacion_ID(nodoB_t<T>* &nodo);
  void Rotacion_DI(nodoB_t<T>* &nodo);

  void Insertar(T claveDada);


  void InsertaBal(nodoB_t<T>* &nodo, nodoB_t<T>* nuevo, bool& crece);
  void InsertReBalIzq(nodoB_t<T>* nodo);
  void InsertReBalDer(nodoB_t<T>* nodo);

  void Eliminar(T clavedada);
  void EliminarRama(nodoB_t<T>* &nodo, T clave, bool& decrece);

  void Sustituye(nodoB_t<T>* &eliminado, nodoB_t<T>* &sust, bool &decrece);

  void EliminarReBalIzq(nodoB_t<T>* &nodo, bool& decrece);
  void EliminarReBalDer(nodoB_t<T>* &nodo, bool& decrece);


    



};


template<class T>
void arbolAVL_t<T>::Rotacion_II(nodoB_t<T>* &nodo) {
  nodoB_t<T>* nodo1 = nodo->left_ptr();
  nodo->left_ptr = nodo1->right_ptr();
  nodo1->right_ptr = nodo;

  if(nodo1->get_bal() == 1) {
    nodo->set_bal(0);
    nodo1->set_bal(0);
  }
  else {
    nodo->set_bal(1);
    nodo1->set_bal(-1);
  }
  nodo = nodo1;
}
