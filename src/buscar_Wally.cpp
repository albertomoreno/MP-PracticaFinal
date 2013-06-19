
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

  double valor = 0.0;
  cout << "Sgrande: " << endl;
  for (int i = 0; i < Sgrande.getRows(); ++i) {
    for (int j = 0; j < Sgrande.getCols(); ++j) {
      valor = Sgrande.get(i, j);
      cout << setw(3) << valor << " ";
    }
    cout << endl;
  }

  cout << "Speque: " << endl;
  for (int i = 0; i < Speque.getRows(); ++i) {
    for (int j = 0; j < Speque.getCols(); ++j) {
      valor = Speque.get(i, j);
      cout << setw(3) << valor << " ";
    }
    cout << endl;
  }
  Signal Sout;
  //Sout = correlacion(Sgrande, Speque);

  /*int x=0, y=0;
  double max = -numeric_limits<double>::max();
  double valor = 0.0;
  for (int i = 0; i < Sout.getRows(); ++i) {
    for (int j = 0; j < Sout.getCols(); ++j) {
      valor = Sout.get(i, j);
      cout << setw(3) << valor << " ";
      if(valor > max) {
        x = i;
        y = j;
        max = valor;
      }
    }
    cout << endl;
  }
*/

  Imagen Iout;
  Iout = SignalToImagen(Sout);

  //Iout = resaltar(grande, x, y, peque.getRows(), peque.getCols());

  Iout.writeImage(argv[4]);

}
