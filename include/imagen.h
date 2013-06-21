/**
 * @file imagen.h
 * @brief  Guarda los pixeles de una imagen en una matriz de bytes.
 * 
 */

#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>

using namespace std;

#define Byte unsigned char

class Imagen{
private:
  /**
   * @brief Numero de filas y columnas que tiene la imagen.
   */
  int rows, cols;

  /**
   * @brief Se almacena la imagen en una matriz de byte.
   */
  Byte **image;

  /**
   * @brief Crea el espacio en la matriz de tamaño rows*cols para almacenar 
   * la imagen.
   */
  void allocate();

  /**
   * @brief Libera el espacio que ocupaba la imagen.
   */
  void free();

  /**
   * @brief Intercambia una imagen por la otra.
   * @param a Una de las imagenes a intercambiar.
   * @param b Una de las imagenes a intercambiar.
   */
  void intercambia(Imagen& a, Imagen& b);

public:
  /**
   * @brief Constructor sin parametros de la clase.
   */
  Imagen();

  /**
   * @brief Constructor con parametros de la clase. Crea el espacio suficiente 
   * para almacenar una imagen.
   *
   * @param f Numero de filas que tiene la imagen.
   * @param c Numero de columnas que tiene la imagen.
   */
  Imagen(int f, int c);

  /**
   * @brief Constructor de copia de la clase.
   *
   * @param other Imagen que se va a copiar.
   */
  Imagen(const Imagen &other);

  /**
   * @Destructor de la clase. Libera el espacio asignado por el constructor.
   */
  ~Imagen();

  /**
   * @brief Consulta el numero de filas de la imagen.
   * @return Devuelve el numero de filas de la imagen.
   */
  int getRows () const; 

  /**
   * @brief Consulta el numero de columnas de la imagen.
   * @return Devuelve el numero de columnas de la imagen.
   */
  int getCols () const; 

  /**
   * @brief Modifica el byte [f,c] por un byte nuevo.
   * @param f Numero de fila a modificar.
   * @param c Numero de columna a modificar.
   * @param v Nuevo valor del Byte.
   */
  void set (int f, int c, Byte v); 

  /**
   * @brief Consulta el byte [f,c].
   * @param  f Numero de fila a consultar.
   * @param  c Numero de columnas a consultar
   * @return   Devuelve el valor del byte consultado.
   */
  Byte get (int f, int c) const ; 

  /**
   * @brief Lee una imagen de un archivo.
   * @param  file Archivo donde se encuentra la imagen.
   * @return      Devuelve si la lectura ha sido satisfactoria.
   */
  bool readImage(const char file[]); 

  /**
   * @brief Escribe una imagen en un archivo.
   * @param  file Archivo donde se escribe la imagen.
   * @return      Devuelve si la escritura ha sido satisfactoria.
   */
  bool writeImage(const char file[]); 

  /**
   * @brief Operador= de la clase. Iguala una imagen a otra.
   * @param img Imagen de la cual se va a realizar la igualacion.
   */
  Imagen& operator=(Imagen img);

};

#endif

/* Fin Fichero: imagen.h */
