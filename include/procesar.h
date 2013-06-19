/**
  * @file procesar.h
  * @brief Fichero cabecera para la codificación de mensajes en imágenes  
  *
  */
 

#ifndef _PROCESAR_H_
#define _PROCESAR_H_

#include <iostream>
#include "imagenES.h"
#include "imagen.h"

#define Byte unsigned char

using namespace std;


void codify(Byte str[], int length, Imagen &img);
void decodify(Byte str[], int length, Imagen &img);
int size(Byte str[], int n);
bool getBit(Byte b, int pos);
void setBit(Byte &b, int pos, bool bit);

Imagen resaltar(Imagen &imagen, int x, int y, int sizeR, int sizeC);

#endif

/* Fin Fichero: codificar.h */
