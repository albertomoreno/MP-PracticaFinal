
#include <iostream>
#include "correlacion.h"

using namespace std;

Signal correlacion(const Signal &imagen, const Signal &filtro) {
  int filas = imagen.getRows();
  int columnas = imagen.getCols();

  Signal Iout(filas, columnas);

  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas; ++j) {
      Iout.set(i, j, 0.0);
    }
  }

  int mitadF = (filtro.getRows()-1)/2;
  int mitadC = (filtro.getCols()-1)/2;

  int fila_inicio = mitadF;
  int fila_fin = filas-mitadF;
  int col_inicio = mitadC;
  int col_fin = columnas-mitadC;

  for (int i = fila_inicio; i < fila_fin; ++i) {
    for (int j = col_inicio; j < col_fin; ++j) {
      double suma = 0.0;
      for (int k = -mitadF; k <= mitadF; ++k) {
        for (int l = -mitadC; l <= mitadC; ++l) {
          suma += imagen.get(i+k, j+l)*filtro.get(k+mitadF, l+mitadC);
        }
      }
      Iout.set(i, j, suma);
    }
  }

  return Iout;
}
