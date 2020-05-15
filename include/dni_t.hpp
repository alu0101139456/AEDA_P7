#pragma once

#include <utility>
#include <iostream>
#include <iomanip>
#include "Contador_t.hpp"
#define MAX 99999999
#define MIN 0 


class dni_t {
 private: 
  uint numeroDni_ = 0;
  
 public:
  dni_t(){ create(); };
  // dni_t(dni_t& copy) { numeroDni_ = copy.numeroDni_; }
  // dni_t(uint numeroDni ) { numeroDni_ = numeroDni_; }
  ~dni_t(){};

//OPERADORES
  inline operator int() { return numeroDni_; }
  inline bool operator==(dni_t& a) { dni_t::contador++; return numeroDni_ == a.numeroDni_;}
  inline unsigned operator % (int modulo) { return numeroDni_ % modulo;}
  inline dni_t operator=(dni_t& aux) { numeroDni_ = aux.numeroDni_; return *this; }
  inline dni_t operator=( int a) { numeroDni_ = a; return *this; }
  inline bool operator<(dni_t& aux) { dni_t::contador++; return numeroDni_ < aux.get_dni();}
  inline bool operator>(dni_t& aux) { dni_t::contador++; return numeroDni_ > aux.get_dni();}
  inline bool operator>=(dni_t& aux) { dni_t::contador++; return numeroDni_ >= aux.get_dni();}
  inline bool operator<=(dni_t& aux) { dni_t::contador++; return numeroDni_ <= aux.get_dni();}
  std::ostream& operator<<(std::ostream& os) { printDni(os); return os; };

  static Contador_t contador;

  inline unsigned int get_dni() { return numeroDni_; }
  void create(void) { numeroDni_ = rand() % (MAX - MIN + 1) - MIN; }
  std::ostream& printDni(std::ostream& os) const;

  
};

std::ostream& dni_t::printDni(std::ostream& os) const {
  // os.fill('0');
  // os.width(8);
  os << numeroDni_ << "";
  return os;



}

Contador_t dni_t::contador = Contador_t();