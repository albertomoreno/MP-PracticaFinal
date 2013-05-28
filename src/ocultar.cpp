
#include <iostream>
#include <string.h>
#include "procesar.h"
#include "imagenES.h"

using namespace std;

const int MAXBUFFER = 1000000;
const int MAXNAME = 100;
const int MAXTEXT = 125000;

int main() {

  //Inicializamos las variables
  char name[MAXNAME];
  char salida[MAXNAME];
  int rows, cols;
  Byte imagen[MAXBUFFER];
  Byte str[MAXTEXT];

  //Se piden los datos
  cout << "Introduzca la imagen de entrada: ";
  cin >> name;
  cout << "Introduzca la imagen de salida: ";
  cin >> salida;
  cout << "Introduzca el mensaje: ";
  cin.ignore();             //Lo usamos para que ignore un salto de linea
  cin.getline((char *)str, MAXTEXT);    //Recogemos el texto en str


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

  //Comprobamos la longitud de la cadena
  int length = size(str, MAXTEXT);

  //Comprobamos si el mensaje es codificable en la imagen
  if(rows*cols < length){
    cout << "Texto demasiado largo para codificar." << endl;
  }


  cout << "Ocultando..." << endl;

  //Se codifica el texto en la imagen
  codify(str, length, imagen);

  //Escribimos la imagen segun su tipo
  if(tipo == IMG_PGM) {
    strcat(salida, ".pgm");
    correct = EscribirImagenPGM(salida, imagen, rows, cols);
  }
  else if(tipo == IMG_PPM) {
    strcat(salida, ".ppm");
    correct = EscribirImagenPPM(salida, imagen, rows, cols);
  }
  else {
    cout << "Error al escribir la imagen " << endl;
    return 1;
  }
  if(!correct) {
    cout << "Error al escribir la imagen" << endl;
    return 1;
  }

  cout << "Codificado" << endl;

  return 0;
}
