#pragma once


#include "arbolB_t.hpp"




template <class T>
class arbolAVL_t : public arbolB_t<T> {

 public:

  void Rotacion_II(nodoB_t<T>* &nodo);
  void Rotacion_DD(nodoB_t<T>* &nodo);
  void Rotacion_ID(nodoB_t<T>* &nodo);
  void Rotacion_DI(nodoB_t<T>* &nodo);

  void Insertar(T claveDada);


  inline nodoB_t<T>* Buscar(T dato) { BuscarRama( this->getRaiz(), dato); }

  void InsertaBal(nodoB_t<T>* &nodo, nodoB_t<T>* nuevo, bool &crece);
  void InsertReBalIzq(nodoB_t<T>* &nodo, bool &crece);
  void InsertReBalDer(nodoB_t<T>* &nodo, bool &crece);

  void Eliminar(T clavedada);
  void EliminarRama(nodoB_t<T>* &nodo, T dato, bool &decrece);


  void Sustituye(nodoB_t<T>* &eliminado, nodoB_t<T>* &sust, bool &decrece);

  void EliminarReBalIzq(nodoB_t<T>* &nodo, bool &decrece);
  void EliminarReBalDer(nodoB_t<T>* &nodo, bool &decrece);

 private:
  nodoB_t<T>* BuscarRama( nodoB_t<T> *nodo, T dato);
    



};

template<class T>
nodoB_t<T>* arbolAVL_t<T>::BuscarRama( nodoB_t<T>* nodo, T dato) {
  if(!nodo) return nullptr;
  if(dato == nodo->get_data()) return nodo;
  if(dato < nodo->get_data()) return BuscarRama(nodo->left_ptr(), dato);
  return BuscarRama(nodo->right_ptr(), dato);
}


template<class T>
void arbolAVL_t<T>::Rotacion_II(nodoB_t<T>* &nodo) {
  nodoB_t<T>* aux = nodo->left_ptr();
  nodo->left_ptr = aux->right_ptr();
  aux->right_ptr = nodo;

  if(aux->get_bal() == 1) {
    nodo->set_bal(0);
    aux->set_bal(0);
  }
  else {
    nodo->set_bal(1);
    aux->set_bal(-1);
  }
  nodo = aux;
}

template<class T>
void arbolAVL_t<T>::Rotacion_DD(nodoB_t<T>* &nodo) {
  nodoB_t<T>* aux = nodo->right_ptr();
  nodo->right_ptr() = aux->left_ptr();
  aux->left_ptr() = nodo;

  if( aux->get_bal() == -1) {
    nodo->set_bal(0);
    aux->set_bal(0);
  }
  else {
    nodo->set_bal(-1);
    aux->set_bal(1);
  }
  nodo = aux;
}

template <class T>
void arbolAVL_t<T>::Rotacion_ID(nodoB_t<T>* &nodo) {
  nodoB_t<T> *nodo1 = nodo->left_ptr();
  nodoB_t<T> *nodo2 = nodo1->right_ptr();
  nodo->left_ptr() = nodo2->right_ptr();
  nodo2->right_ptr() = nodo;
  nodo1->right_ptr() = nodo2->left_ptr();
  nodo2->left_ptr() = nodo1;
  
  if(nodo2->get_bal() == -1) 
    nodo1->set_bal(1);  
  else 
    nodo1->set_bal(0);

  if(nodo2->get_bal() == 1) 
    nodo->set_bal(-1);
  else 
    nodo->set_bal(0);

  nodo2->set_bal(0);
  nodo = nodo2;
}


template <class T>
void arbolAVL_t<T>::Rotacion_DI(nodoB_t<T>* &nodo) {
  nodoB_t<T> *nodo1 = nodo->right_ptr();
  nodoB_t<T> *nodo2 = nodo1->left_ptr();
  nodo->right_ptr() = nodo2->left_ptr();
  nodo2->left_ptr() = nodo;
  nodo1->left_ptr() = nodo2->right_ptr();
  nodo2->right_ptr() = nodo1;

  if(nodo2->get_bal() == 1) 
    nodo1->set_bal(-1);
  else
    nodo1->set_bal(0);
  
  if(nodo2->get_bal() == -1) 
    nodo->set_bal(1);
  else
    nodo->set_bal(0);

  nodo2->set_bal(0);
  nodo = nodo2;
}

template<class T>
void arbolAVL_t<T>::Insertar(T claveDada) {
  if (Buscar(claveDada)) return;
  nodoB_t<T>* aux = new nodoB_t<T>(claveDada);
  bool crece = false;
  InsertaBal( this->getRaiz(), aux, crece);
}

template<class T>
void arbolAVL_t<T>::InsertaBal(nodoB_t<T>* &nodo, nodoB_t<T> *nuevo, bool &crece) {
  if( !nodo) {
    nodo = nuevo;
    crece = true;
  }
  else if ( nuevo->get_data() < nodo->get_data()) {
    InsertaBal(nodo->left_ptr(), nuevo, crece);
    if(crece)
      InsertReBalIzq(nodo, crece);
    }
    else {
      InsertaBal(nodo->right_ptr(), nuevo, crece);
      if(crece)
        InsertReBalDer(nodo, crece);
    }
}


template<class T>
void arbolAVL_t<T>::InsertReBalIzq(nodoB_t<T>* &nodo, bool &crece) {
  nodoB_t<T>* aux;
  switch ( nodo->get_bal()) {
    case -1:
        nodo->set_bal(0);
        crece = false;
      break;
    case 0:
        nodo->set_bal(1);
      break;
    case 1:
        aux = nodo->left_ptr();
        if(aux->get_bal() == 1)
          Rotacion_II(nodo);
        else
          Rotacion_ID(nodo);
        crece = false;
      break;
  }
}

template<class T>
void arbolAVL_t<T>::InsertReBalDer(nodoB_t<T>* &nodo, bool &crece) {
  nodoB_t<T>* aux;
  switch ( nodo->get_bal()) {
    case 1:
        nodo->set_bal(0);
        crece = false;
      break;
    case 0:
        nodo->set_bal(-1);
      break;
    case -1:
        aux = nodo->right_ptr();
        if(aux->get_bal() == -1)
          Rotacion_DD(nodo);
        else
          Rotacion_DI(nodo);
        crece = false;
      break;
  }
}


template<class T>
void arbolAVL_t<T>::Eliminar(T dato) {
  bool decrece = false;
  EliminarRama(this->getRaiz(), dato, decrece);
}


template<class T>
void arbolAVL_t<T>::EliminarRama(nodoB_t<T>* &nodo, T dato, bool &decrece) {
  if(!nodo) return;
  if(dato < nodo->get_data()) {
    EliminarRama(nodo->left_ptr(), dato, decrece);
    if(decrece)
      EliminarReBalIzq(nodo, decrece);
  }
  else if (dato > nodo->get_data()) {
    eliminar rama(nodo->right_ptr(), dato, decrece);
    if(decrece)
      EliminarReBalDer(nodo, decrece);
  else {
    nodoB_t<T>* eliminado = nodo;
    if(!nodo->left_ptr()) {
      nodo = nodo->right_ptr();
      decrece = true;
    }
    else if (nodo->right_ptr()) {
      nodo = nodo->left_ptr();
      decrece = true;
    }
    else {
      Sustituye(eliminado, nodo->left_ptr(), decrece);
      if(decrece) 
        EliminarReBalIzq(nodo, decrece);
    }
    delete eliminado;
  }
  
}