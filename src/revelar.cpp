
#include <iostream>
#include "procesar.h"
#include "imagen.h"

using namespace std;

const int MAXBUFFER = 1000000;
const int MAXNAME = 100;
const int MAXTEXT = 125000;

int main(int argc, char* argv[]) {
  if(argc != 2){
    cerr << "Error al introducir parametros" << endl;
    return 1;
  }

  char* name = argv[1];
  Imagen img;
  Byte str[MAXTEXT];

  
  if(!img.readImage(name)) {
    cerr << "Error al leer la imagen." << endl;
    return 1;
  }

  cout << "Revelando..." << endl;

  decodify(str, min(MAXTEXT, img.getRows()*img.getCols()/8), img);

  cout << "El mensaje obtenido es: " << str << endl;


  return 0;
}
