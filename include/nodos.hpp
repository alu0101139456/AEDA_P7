#pragma once

#include <iostream>

template<class T>
class nodoB_t {
 private:
  T dato_;
  nodoB_t<T>* izq_ = nullptr;
  nodoB_t<T>* der_ = nullptr;
  int bal_ = 0;

 public:
  nodoB_t(){};

  nodoB_t(const T dato, nodoB_t<T>* izq, nodoB_t<T>* der):
    dato_(dato), izq_(izq), der_(der) {}

  nodoB_t(const T dato):
    dato_(dato) {}

  ~nodoB_t() = default;

  virtual inline nodoB_t<T>*& left_ptr() { return izq_; }
  virtual inline nodoB_t<T>*& right_ptr() { return der_; }
  virtual inline T& get_data() { return dato_; }

  virtual inline bool isLeaf() { return (!izq_ && !der_);}

  virtual inline void set_bal(int newbal) { bal_ = newbal; }
  virtual inline int get_bal() { return bal_; }





  virtual void operator=(nodoB_t<T> nodo) {
    dato_ = nodo.dato_;
    izq_ = nodo.izq_;
    der_ = nodo.der_;
  }

  inline void set_data(nodoB_t<T>* nodo) { dato_ = nodo->get_data(); }
  
};


template<class T>
class nodoBB_t : public nodoB_t<T> {


};







