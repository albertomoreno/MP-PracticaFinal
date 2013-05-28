
#include <iostream>
#include "procesar.h"
#include "imagenES.h"

using namespace std;

const int MAXBUFFER = 1000000;
const int MAXNAME = 100;
const int MAXTEXT = 125000;

int main() {

  //Inicializamos las variables
  char name[MAXNAME];
  int rows, cols;
  Byte imagen[MAXBUFFER];
  Byte str[MAXTEXT];
  
  //Inicializamos el vector donde se almacenará la imagen
  for (int i = 0; i < MAXBUFFER; ++i) {
    imagen[i] ='\0';
  }

  //Se piden los datos
  cout << "Introduzca la imagen de entrada: ";
  cin >> name;

  //Vemos el tipo de imagen para usar una funcion de lectura de imagen correcta
  TipoImagen tipo = LeerTipoImagen(name, rows, cols);
  bool correct;

  if(tipo == IMG_PGM) {
    correct = LeerImagenPGM(name, rows, cols, imagen);
  }
  else if(tipo == IMG_PPM) {
    correct = LeerImagenPPM(name, rows, cols, imagen);
  }
  else {
    cout << "Error al leer la imagen " << endl;
    return 1;
  }
  if(!correct) {
    cout << "Error al leer la imagen" << endl;
    return 1;
  }

  cout << "Revelando..." << endl;

  //Se obtiene el texto integrado en la imagen
  decodify(str, MAXTEXT, imagen);

  cout << "El mensaje obtenido es: " << str << endl;


  return 0;
}
