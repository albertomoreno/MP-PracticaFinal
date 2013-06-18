
#include <iostream>
#include "conversiones.h"

using namespace std;


Imagen SignalToImagen(const Signal &s) {
  int filas = s.getRows();
  int columnas = s.getCols();
  Imagen im(filas, columnas);

  for(int i = 0 ; i < filas ; i++) {
    for (int j = 0; j < columnas; ++j) {
      im.set(i, j, s.get(i, j)*255.0);
    }
  }

  return im;
}

Signal ImagenToSignal(const Imagen &im) {
  int filas = im.getRows();
  int columnas = im.getCols();
  Signal s(filas, columnas);

  for(int i = 0 ; i < filas ; i++) {
    for (int j = 0; j < columnas; ++j) {
      s.set(i, j, im.get(i, j)/255.0);
    }
  }

  return s;
}
