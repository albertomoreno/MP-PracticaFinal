/**
 * @file signal.h
 * @brief  Guarda los pixeles de una imagen en una matriz con valores entre [0,1]
 * 
 */

#ifndef SIGNAL_H
#define SIGNAL_H

#include <iostream>

using namespace std;

#define FILTRO_TEXT "MP-FILTRO-T"
#define FILTRO_BIN "MP-FILTRO-B"

class Signal{
private:
  /**
   * @brief Numero de filas y columnas que tiene la imagen.
   */
  int rows, cols;
  /**
   * @brief Se almacena la imagen en una matriz de doubles.
   */
  double **image;

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
  void intercambia(Signal& a, Signal& b);

public:
  /**
   * @brief Constructor sin parametros de la clase.
   */
  Signal();

  /**
   * @brief Constructor con parametros de la clase. Crea el espacio suficiente 
   * para almacenar una imagen.
   *
   * @param f Numero de filas que tiene la imagen.
   * @param c Numero de columnas que tiene la imagen.
   */
  Signal(int f, int c);

  /**
   * @brief Constructor de copia de la clase.
   *
   * @param other Signal que se va a copiar.
   */
  Signal(const Signal &other);

  /**
   * @Destructor de la clase. Libera el espacio asignado por el constructor.
   */
  ~Signal();

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
   * @brief Modifica el double [f,c] por un double nuevo.
   * @param f Numero de fila a modificar.
   * @param c Numero de columna a modificar.
   * @param v Nuevo valor del double.
   */
  void set (int f, int c, double v);

  /**
   * @brief Consulta el double [f,c].
   * @param  f Numero de fila a consultar.
   * @param  c Numero de columnas a consultar
   * @return   Devuelve el valor del double consultado.
   */
  double get (int f, int c) const ;

  /**
   * @brief Operador= de la clase. Iguala una imagen a otra.
   * @param signal Signal del cual se va a realizar la igualacion.
   */
  Signal& operator=(Signal signal);

  /**
   * @brief Operador* de la clase. Multiplica un signal por un entero.
   * @param n Entero por el que se va a multiplicar el signal.
   */
  Signal& operator*(int n);

  /**
   * @brief Lee un filtro de un archivo.
   * @param  file Archivo donde se encuentra el filtro.
   * @return      Devuelve si la lectura ha sido satisfactoria.
   */
  bool leerFiltro(const char *file);

  /**
   * @brief Escribe un filtro en un archivo.
   * @param  file Archivo donde se escribe el filtro.
   * @param  tipo Tipo de archivo en el que se va a copiar.
   * @return      Devuelve si la escritura ha sido satisfactoria.
   */
  bool crearFiltro(const char *file, char* tipo); 

};

#endif

/* Fin Fichero: signal.h */
