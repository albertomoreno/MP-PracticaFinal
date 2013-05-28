
#include <iostream>
#include "signal.h"
#include "imagenES.h"

using namespace std;

Signal::Signal(){
  rows = 0;
  cols = 0;
  allocate();
}

Signal::Signal(int f, int c){
  rows = f;
  cols = c;
  allocate();
}

Signal::~Signal(){
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

