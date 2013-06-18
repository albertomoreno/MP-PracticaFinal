#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>

using namespace std;

#define Byte unsigned char

class Imagen{
private:
  int rows, cols;
  Byte **image;

  void allocate();
  void free();
  void intercambia(Imagen& a, Imagen& b);

public:
  Imagen();
  Imagen(int f, int c);
  Imagen(const Imagen &other);
  ~Imagen();

  int getRows () const; // Devuelve el número de filas de m
  int getCols () const; // Devuelve el número de columnas de m
  void set (int f, int c, Byte v); // Hace img(i,j)=v
  Byte get (int f, int c) const ; // Devuelve img(i,j)
  bool readImage(const char file[]); // Carga imagen file en img
  bool writeImage(const char file[]) const; //Salva img en file

  Imagen& operator=(Imagen img);

};

#endif

