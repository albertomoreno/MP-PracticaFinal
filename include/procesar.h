/**
  * @file procesar.h
  * @brief Fichero para procesar imagenes  
  *
  */
 

#ifndef _PROCESAR_H_
#define _PROCESAR_H_

#include <iostream>
#include "imagenES.h"
#include "imagen.h"

#define Byte unsigned char

using namespace std;

/**
 * @brief Oculta un texto en una imagen.
 *
 * @param str Cadena que se va a ocultar en la imagen.
 * @param length Longitud de la cadena a ocultar.
 * @param img Imagen en la que se codifica el mensaje.
 */
void codify(Byte str[], int length, Imagen &img);

/**
 * @brief Obtiene un mensaje oculto en una imagen.
 * 
 * @param str Parámetro de salida en el que se almacena el mensaje obtenido.
 * @param length Longitud máxima de la cadena que se va a obtener.
 * @param img Imagen en la que esta el mensaje oculto.
 */
void decodify(Byte str[], int length, Imagen &img);

/**
 * @brief Obtiene el tamaño de una cadena.
 * 
 * @param str Cadena de la que se va a obtener el tamaño.
 * @param n Tamaño máximo que puede tener la cadena.
 * 
 * @return Devuelve el tamaño de la cadena.
 */
int size(Byte str[], int n);

/**
 * @brief Consulta un determinado bit dentro de un Byte.
 * @param b Byte del que se va a consultar un bit.
 * @param pos Posición del bit que se va a consultar.
 * 
 * @return Devuelve el bit consultado.
 */
bool getBit(Byte b, int pos);

/**
 * @brief Modifica un determinado bit dentro de un Byte.
 * 
 * @param b Parámetro de salida que contiene el Byte modificado.
 * @param pos Posición del bit que se va a modificar.
 * @param bit Valor con el que se va a modificar el bit elegido.
 */
void setBit(Byte &b, int pos, bool bit);

/**
 * @brief Resalta un trozo de imagen oscureciendo el resto.
 * @param  imagen Imagen que se va a resaltar.
 * @param  x      Coordenada X del centro del trozo a resaltar.
 * @param  y      Coordenada Y del centro del trozo a resaltar.
 * @param  sizeR  Radio en X de la parte a resaltar.
 * @param  sizeC  Radio en Y de la parte a resaltar.
 * @return        Devuelve la imagen resaltada.
 */
Imagen resaltar(Imagen &imagen, int x, int y, int sizeR, int sizeC);

#endif

/* Fin Fichero: codificar.h */
