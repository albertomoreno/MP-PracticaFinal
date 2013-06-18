
#include <iostream>
#include <string.h>
#include "procesar.h"
#include "imagenES.h"
#include "imagen.h"

using namespace std;

const int MAXBUFFER = 1000000;
const int MAXNAME = 100;
const int MAXTEXT = 125000;

int main(int argc, char* argv[]) {
  if(argc != 3){
    cerr << "Error al introducir parametros" << endl;
    return 1;
  }

  char* name = argv[1];
  char* output = argv[2];
  Imagen img;
  Byte str[MAXTEXT];

  cout << "Introduzca el mensaje: ";
  cin.getline((char *)str, MAXTEXT);    //Recogemos el texto en str

  if(!img.readImage(name)) {
    cerr << "Error al leer la imagen." << endl;
    return 1;
  }

  //Comprobamos la longitud de la cadena
  int length = size(str, min(MAXTEXT, img.getRows()*img.getCols()/8));

  //Comprobamos si el mensaje es codificable en la imagen
  if(img.getRows()*img.getCols() < length){
    cout << "Texto demasiado largo para codificar." << endl;
  }


  cout << "Ocultando..." << endl;

  //Se codifica el texto en la imagen
  codify(str, length, img);

  if(!img.writeImage(output)) {
    cerr << "Error al escribir la imagen." << endl;
  }

  cout << "Codificado" << endl;

  return 0;
}
