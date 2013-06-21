 
#include <iostream>
#include "imagenES.h"
#include "imagen.h"
#include "procesar.h"

using namespace std;

void codify(Byte str[], int length, Imagen &img) {
  int cols = img.getCols();
  int pos = 0;     //Se usa para indicar la posicion del buffer

  for(int i = 0 ; i < length ; i++) {
    for (int j = 0; j < 8; ++j) {
      int f = pos/cols;
      int c = pos%cols;

      Byte b = img.get(f, c);
      setBit(b, 0, getBit(str[i], j));
      img.set(f, c, b);

      pos++;
    }
  }
}

void decodify(Byte str[], int length, Imagen &img) {
  int cols = img.getCols();
  int pos = 0;     //Se usa para indicar la posicion del buffer

  for(int i = 0 ; i < length ; i++) {
    for (int j = 0; j < 8; ++j) {
      int f = pos/cols;
      int c = pos%cols;
      setBit(str[i], j, getBit(img.get(f, c), 0));
      pos++;
    }
  }
}

int size(Byte str[], int n){
  int length = 0;
  while(str[length] != '\0' && length < n){
    length++;
  }
  str[length] = '\0';
  length++;

  return length;
}

bool getBit(Byte b, int pos) {
  if(b & (1 << pos)) {
    return true;
  } else {
    return false;
  }
}

void setBit(Byte &b, int pos, bool bit) {
  if(bit)
    b = b | (1<<pos);
  else
    b = b & ~(1<<pos);
}

Imagen resaltar(Imagen &imagen, int x, int y, int sizeR, int sizeC) { 
  int f = imagen.getRows();
  int c = imagen.getCols();
  Imagen img(f, c);

  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      if(i < (x+sizeR) && i > (x-sizeR) && j < (y+sizeC) && j > (y-sizeC)) {
        img.set(i, j, imagen.get(i,j));
      } else {
        img.set(i, j, imagen.get(i,j)*0.5);
      }
    }
  }

  return img;
}

