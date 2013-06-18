
#include <iostream>
#include "imagen.h"
#include "signal.h"
#include "conversiones.h"
#include "correlacion.h"

using namespace std;

Imagen filtrar(Imagen &imagen, Signal &filtro) {
  Signal img;
  img = ImagenToSignal(imagen);

  Signal out;
  out = correlacion(img, filtro);

  Imagen Iout;
  Iout = SignalToImagen(out);

  return Iout;
}

int main(int argc, char* argv[]) {
  if(argc != 4){
    cerr << "Error al introducir parametros" << endl;
    return 1;
  }

  Imagen img;
  Signal filtro;

  img.readImage(argv[1]);
  filtro.leerFiltro(argv[2]);

  img = filtrar(img, filtro);

  img.writeImage(argv[3]);

}
