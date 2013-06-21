
#include <iostream>
#include <limits>
#include "procesar.h"
#include "imagen.h"
#include "signal.h"
#include "conversiones.h"
#include "correlacion.h"
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 5){
    cerr << "Error al introducir parametros" << endl;
    return 1;
  }

  Imagen grande;
  Imagen peque;
  Signal filtro;

  grande.readImage(argv[1]);
  peque.readImage(argv[2]);
  filtro.leerFiltro(argv[3]);

  Signal Sgrande;
  Sgrande = ImagenToSignal(grande);
  Signal Speque;
  Speque = ImagenToSignal(peque);

  Sgrande = correlacion(Sgrande, filtro);
  Speque = correlacion(Speque, filtro);

  Signal Sout;
  Sout = correlacion(Sgrande, Speque);

  double valor = 0.0;
  int x=0, y=0;
  double max = -numeric_limits<double>::max();
  for (int i = 0; i < Sout.getRows(); ++i) {
    for (int j = 0; j < Sout.getCols(); ++j) {
      valor = Sout.get(i, j);
      if(valor > max) {
        x = i;
        y = j;
        max = valor;
      }
    }
  }

  cout << "(x,y): (" << x << "," << y << ")" << endl;

  Imagen Iout;
  Iout = resaltar(grande, x, y, peque.getRows(), peque.getCols());

  Iout.writeImage(argv[4]);

  return 0;
}
