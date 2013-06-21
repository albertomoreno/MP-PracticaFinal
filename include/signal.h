#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>

using namespace std;

#define FILTRO_TEXT "MP-FILTRO-T"
#define FILTRO_BIN "MP-FILTRO-B"

class Signal{
private:
  int rows, cols;
  double **image;

  void allocate();
  void free();
  void intercambia(Signal& a, Signal& b);

public:
  Signal();
  Signal(int f, int c);
  Signal(const Signal &other);
  ~Signal();

  int getRows () const; // Devuelve el número de filas de m
  int getCols () const; // Devuelve el número de columnas de m
  void set (int f, int c, double v); // Hace img(i,j)=v
  double get (int f, int c) const ; // Devuelve img(i,j)

  Signal& operator=(Signal signal);
  Signal& operator*(int n);

  bool leerFiltro(const char *file);
  bool crearFiltro(const char *file, char* tipo); 

};

#endif

