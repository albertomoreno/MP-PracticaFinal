
#include <iostream>
#include "imagen.h"
#include "imagenES.h"

using namespace std;

Imagen::Imagen(){
  rows = 0;
  cols = 0;
}

Imagen::Imagen(int f, int c){
  rows = f;
  cols = c;
  allocate();
}

Imagen::Imagen(const Imagen &other) {
  rows = other.rows;
  cols = other.cols;
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < cols ; j++) {
      image[i][j] = other.image[i][j];
    }
  }
}

Imagen::~Imagen(){
  if(rows==0 && cols==0)
    return;

  free();
  rows = 0;
  cols = 0;
  image = 0;
}

void Imagen::allocate(){
  image = new Byte* [rows];
  for (int i = 0 ; i < rows ; i++){
    image[i] = new Byte [cols];
  }
}

void Imagen::free(){
  for(int i = 0 ; i < rows ; i++){
    delete [] image[i];
  }
  delete [] image;
}

int Imagen::getRows () const{
  return rows;
}

int Imagen::getCols () const{
  return cols;
}

void Imagen::set (int f, int c, Byte v){
  image[f][c] = v;
}

Byte Imagen::get (int f, int c) const {
  return image[f][c];
}

bool Imagen::readImage(const char file[]){
  Byte buffer[1080*1920];

  if(!LeerImagenPGM (file, rows, cols, buffer))
    return false;

  allocate();

  for (int i = 0 ; i < rows ; ++i) {
    for (int j = 0; j < cols; ++j) {
      image[i][j] = buffer[i*cols+j];
    }
  }

  return true;
}

bool Imagen::writeImage(const char file[]) const{
  Byte buffer[rows*cols];

  for (int i = 0 ; i < rows ; ++i) {
    for (int j = 0 ; j < cols ; ++j) {
      buffer[i*cols+j] = image[i][j];
    }
  }
  return EscribirImagenPGM (file, buffer, rows, cols);
}

Imagen& Imagen::operator=(Imagen img){
  intercambia(*this, img);
  return *this;
}

void Imagen::intercambia(Imagen& a, Imagen& b){
  Byte** tmp = a.image;
  a.image = b.image;
  b.image = tmp;

  int r = a.rows;
  a.rows = b.rows;
  b.rows = r;

  int c = a.cols;
  a.cols = b.cols;
  b.cols = c;
}

