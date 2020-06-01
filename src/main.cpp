#include <iostream>

#include "nodos.hpp"
#include "arbolB_t.hpp"
#include "arbolAVL_t.hpp"
#include "dni_t.hpp"
#include "Contador_t.hpp"
#include <vector>

void printResults(int p);

void printdemo1(void) {
  std::cout << "Traza AVL. Ángel Julián Bolaño Campos\n";
  std::cout << "\n¿Qué desea hacer?\n";
  std::cout << " 1 - Insertar clave.\n";
  std::cout << " 2 - Eliminar clave.\n";
  std::cout << " 3 - Comprobrar si es equilibrado.\n";
  std::cout << " 4 - Mostrar arbol.\n";
  std::cout << " 0 - Salir.\n";
}

void cleanAndWait() {
  std::cin.ignore();
  std::cout << "<< Presione una tecla para volver al menu principal >>";
  std::cin.ignore();
  system("clear");
}



int main() {


arbolAVL_t<dni_t> arbol;

  
#ifdef DEMO
  dni_t aux; //Usaremos aux para valores pequeños de demo
  int demo_int;
  bool bucle = true;
  int op = -1;
  int temp;
  system("clear");
            

  while (bucle)
  {
    printdemo1();
    std::cin >> op;
    switch (op)
    {
      case 0:
        bucle = false;
        break;
      case 1:
        std::cout << "\nInsertar: ";
        std::cin >> temp;
        aux = temp;
        arbol.Insertar(aux);
        system("clear");
        arbol.writeRecorrido(4);
        break;
      case 2:
        std::cout << "\nEliminar: ";
        std::cin >> temp;
        aux = temp;
        arbol.Eliminar(aux);
        arbol.writeRecorrido(4);
        
        break;
      case 3:
        system("clear");
        if (arbol.Equilibrado()) {
          std::cout << "El arbol es equilibrado, como maximo hay un nodo de diferencia entre los subarboles. \n";
        }
        else {
          std::cout << "El arbol NO es equilibrado, hay mas de un nodo de diferencia entre subarboles. \n";
        }
        arbol.writeRecorrido(4); 
        cleanAndWait();       

        break;
      case 4:
        system("clear");
        std::cout << "\n¿Qué recorrido desea?: \n";
        std::cout << " 1 - Preorden.\n";
        std::cout << " 2 - Inorden.\n";
        std::cout << " 3 - Postorden.\n";
        std::cout << " 4 - Por niveles.\n";
        std::cin >> temp;
        arbol.writeRecorrido(temp);
        cleanAndWait();

        break;

      default:
        std::cout << "Opción no valida. \n";
        break;
    }
  }
#endif

#ifdef ESTA
using std::get;
  int N;
  int nPruebas;

  std::vector<dni_t> banco;
  srand(time(NULL));

  std::cout << "Introduzca tamaño del arbol: ";
  std::cin >> N;
  std::cout << "Introduzca número de pruebas: ";
  std::cin >> nPruebas;
  banco.resize(2*N);
  for (int i = 0; i < N; i++) {
    arbol.Insertar(banco[i]);
  }
  auto& contador = dni_t::contador;
  

  dni_t::contador.reset();
  for (int  i = 0; i < nPruebas; i++)
  {
    int index = rand() % N;
    arbol.Buscar(banco[index]);
    dni_t::contador.endCount(); 

  }
  std::cout << "\nBusquedas";
  printResults(nPruebas);


  int dn = 2*N;
  dni_t::contador.reset();
  for (int i = 0; i < 100; i++)
  {
    int index = rand() % (dn - N + 1) + N; 
    arbol.Insertar(banco[index]);
    dni_t::contador.endCount();
  }
  std::cout << "\nInserción";
  printResults(nPruebas);
  

 #endif

 

}

void printResults(int p){
    using std::get;
    auto searchResults = dni_t::contador.getResults();
    std::cout << "\nNúmero de comparaciones";
    std::cout << "\nMínimo\tMedio\tMáximo" << std::endl;
    std::cout << get<2>(searchResults) << '\t' << get<3>(searchResults)/p << '\t' << get<1>(searchResults) <<std::endl;
}

    
    
