#pragma once


#include "arbolB_t.hpp"
#include "nodos.hpp"



template<class T>
class arbolBB_t : public arbolB_t<T> {

 public:

  inline nodoB_t<T>* Buscar(T dato) { BuscarRama( this->getRaiz(), dato); }
  inline void Insertar(T dato) { InsertarRama( this->getRaiz(), dato); }
  inline void Eliminar( T dato) { EliminarRama( this->getRaiz(), dato); }
  
 private:
  nodoB_t<T>* BuscarRama(nodoB_t<T>* nodo, T dato);
  void InsertarRama( nodoB_t<T>* &nodo, T dato);
  void EliminarRama( nodoB_t<T>* &nodo, T dato);
  void Sustituye(nodoB_t<T>* &eliminado, nodoB_t<T>* &sustituto);
  
};




template<class T>
nodoB_t<T>* arbolBB_t<T>::BuscarRama( nodoB_t<T>* nodo, T dato) {
  if(!nodo) return nullptr;
  if(dato == nodo->get_data()) return nodo;
  if(dato < nodo->get_data()) return BuscarRama(nodo->left_ptr(), dato);
  return BuscarRama(nodo->right_ptr(), dato);
}

template<class T>
void arbolBB_t<T>::InsertarRama( nodoB_t<T>*& nodo, T dato) {
  if(!nodo) {
    nodo = new nodoB_t<T>(dato);
    if(!this->getRaiz()) arbolB_t<T>::setRaiz(nodo);
    
  }
  else if( dato < nodo->get_data()){ 
    InsertarRama(nodo->left_ptr(), dato);
  } else {
    InsertarRama(nodo->right_ptr(), dato);
  }
}


template<class T>
void arbolBB_t<T>::EliminarRama(nodoB_t<T>* &nodo, T dato) {
  if(!nodo) return;
  if( dato < nodo->get_data() ){
    EliminarRama(nodo->left_ptr(), dato);
  }
  else if( dato > nodo->get_data() ) {
    EliminarRama(nodo->right_ptr(), dato);
  } else {
    nodoB_t<T>* eliminado = nodo;
    if(!nodo->right_ptr()){
      nodo = nodo->left_ptr();
    }
    else if(!nodo->left_ptr()) {
      nodo = nodo->right_ptr();
    }
    else {
      Sustituye(eliminado, nodo->left_ptr());
    }
    delete eliminado;
  }
}


template<class T>
void arbolBB_t<T>::Sustituye( nodoB_t<T>* &eliminado, nodoB_t<T>* &sustituto) {
  if (!sustituto->right_ptr()) {
    Sustituye(eliminado, sustituto->right_ptr());
  }
  else {
    eliminado->set_data(sustituto);
    eliminado = sustituto;
    sustituto = sustituto->left_ptr();
  }
}



