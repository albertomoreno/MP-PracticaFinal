#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>

using namespace std;

class Signal{
private:
  int rows, cols;
  double **image;

  void allocate();
  void free();

public:
  Signal();
  Signal(int f, int c);
  ~Signal();

  int getRows () const; // Devuelve el número de filas de m
  int getCols () const; // Devuelve el número de columnas de m
  void set (int f, int c, double v); // Hace img(i,j)=v
  double get (int f, int c) const ; // Devuelve img(i,j)
  bool readSignal(const char file[]); // Carga imagen file en img
  bool writeSignal(const char file[]) const; //Salva img en file

};

#endif

