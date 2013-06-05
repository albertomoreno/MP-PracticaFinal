
#include <iostream>
#include <fstream>
#include <string.h>
#include "signal.h"
#include "imagenES.h"

using namespace std;

Signal::Signal(){
  rows = 0;
  cols = 0;
  allocate(rows, cols);
}

Signal::Signal(int f, int c){
  rows = f;
  cols = c;
  allocate(f, c);
}

Signal::~Signal(){
  free();
  rows = 0;
  cols = 0;
  image = 0;
}

void Signal::allocate(int f, int c){
  image = new double* [f];
  for (int i = 0 ; i < f ; i++){
    image[i] = new double [c];
  }
}

void Signal::free(){
  for(int i = 0 ; i < rows ; i++){
    delete [] image[i];
  }
  delete [] image;
}

int Signal::getRows () const{
  return rows;
}

int Signal::getCols () const{
  return cols;
}

void Signal::set (int f, int c, double v){
  image[f][c] = v;
}

double Signal::get (int f, int c) const {
  return image[f][c];
}

bool Signal::readSignal(const char file[]){
  return true;
}

bool Signal::writeSignal(const char file[]) const{
  return true;
}

Signal& Signal::operator=(Signal s){
  intercambia(*this, s);
  return *this;
}

void Signal::intercambia(Signal& a, Signal& b){
  double** tmp = a.image;
  a.image = b.image;
  b.image = tmp;

  int r = a.rows;
  a.rows = b.rows;
  b.rows = r;

  int c = a.cols;
  a.cols = b.cols;
  b.cols = c;
}

Signal& Signal::operator*(int n) {
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < cols ; j++) {
      image[i][j] *= n;
    }
  }
  return *this;
}

bool Signal::leerFiltro(const char *file) {
  ifstream fi(file, ios::in);
  if(!fi) {
    cerr << "Error al crear el flujo" << endl;
    return false;
  }

  char *cad_mag = new char[256];
  fi.getline(cad_mag, 256, '\n');
  if(strcmp(cad_mag, FILTRO_TEXT) == 0) {
    if(fi.peek() == '#') {
      fi.ignore(256, '\n');
    }

    int filas, columnas;
    fi >> filas >> columnas;

    this->allocate(filas, columnas);
    double v;
    for(int i = 0 ; i < filas ; i++){
      for(int j = 0 ; j < columnas ; j++) {
        fi >> v;
        this->set(i, j, v);
      }
    }
  } else if(strcmp(cad_mag, FILTRO_BIN) == 0) {
    
  } else {
    cerr << "Cadena Magica no reconocida." << endl;
    fi.close();
    return false;
  }

  fi.close();
  return true;
}

