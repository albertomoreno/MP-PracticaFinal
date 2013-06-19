
#include <iostream>
#include <fstream>
#include <string.h>
#include "signal.h"
#include "imagenES.h"

using namespace std;

Signal::Signal(){
  rows = 0;
  cols = 0;
}

Signal::Signal(int f, int c){
  rows = f;
  cols = c;
  allocate();
}

Signal::Signal(const Signal &other) {
  rows = other.rows;
  cols = other.cols;
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < cols ; j++) {
      image[i][j] = other.image[i][j];
    }
  }
}

Signal::~Signal(){
  if(rows==0 && cols==0)
    return;
  free();
  rows = 0;
  cols = 0;
  image = 0;
}

void Signal::allocate(){
  image = new double* [rows];
  for (int i = 0 ; i < rows ; i++){
    image[i] = new double [cols];
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
  ifstream fi(file);
  if(!fi) {
    cerr << "Error al crear el flujo" << endl;
    return false;
  }

  char cad_mag[256];
  fi.getline(cad_mag, 256, '\n');
  if(strcmp(cad_mag, FILTRO_TEXT) == 0) {
    if(fi.peek() == '#') {
      fi.ignore(256, '\n');
    }

    int filas, columnas;
    fi >> filas >> columnas;

    rows = filas;
    cols = columnas;
    allocate();
    double v;
    for(int i = 0 ; i < filas ; i++){
      for(int j = 0 ; j < columnas ; j++) {
        fi >> v;
        set(i, j, v);
      }
    }
  } else if(strcmp(cad_mag, FILTRO_BIN) == 0) {
    if(fi.peek() == '#') {
      fi.ignore(256, '\n');
    }

    int filas, columnas;
    fi >> filas >> columnas;

    rows = filas;
    cols = columnas;
    allocate();
    while (fi.peek() == '\n' || fi.peek() == '\r') { //Ignorar los saltos de línea 
      fi.ignore(); 
    }

    int pos = fi.tellg();
    fi.close();
    fi.open(file, ios::binary);
    fi.seekg(pos);
    double data[rows*cols];
    fi.read(reinterpret_cast<char *> (data), sizeof(double)*rows*cols);
    for(int i = 0 ; i < rows ; i++){
      for(int j = 0 ; j < cols ; j++) {
        image[i][j] = data[i*cols+j];
      }
    }
    fi.close();

  } else {
    cerr << "Cadena Magica no reconocida." << endl;
    fi.close();
    return false;
  }

  fi.close();
  return true;
}

