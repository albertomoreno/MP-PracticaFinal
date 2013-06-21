
#include <iostream>
#include <stdlib.h>
#include "signal.h"

using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 5){
    cerr << "Error al introducir parametros" << endl;
    return 1;
  }

  char* tipo = argv[1];
  int filas = atoi(argv[2]);
  int columnas = atoi(argv[3]);
  char* fout = argv[4];

  Signal s(filas, columnas);

  cout << "Introduce los valores del filtro" << endl;

  double valor;
  for(int i = 0 ; i < filas ; i++){
    for(int j = 0 ; j < columnas ; j++) {
      cin >> valor;
      s.set(i, j, valor);
    }
  }

  if(!s.crearFiltro(fout, tipo)) {
    cerr << "Error al crear el filtro." << endl;
    return 1;
  }

  return 0;
}
