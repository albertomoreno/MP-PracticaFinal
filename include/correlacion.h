/**
 * @file correlacion.h
 * @brief  Fichero para la correlacion de dos signal.
 * 
 */

#ifndef _CORRELACION_H_
#define _CORRELACION_H_

#include <iostream>
#include "signal.h"
#include "imagen.h"

using namespace std;

/**
 * Realiza la correlacion de dos imagenes tipo signal.
 * @param  imagen Imagen a la que se realiza la correlacion.
 * @param  filtro Filtro que se usa para la correlacion.
 * @return        Devuelve la imagen que se le ha realizado la correlacion.
 */
Signal correlacion(const Signal &imagen, const Signal &filtro);

#endif

/* Fin Fichero: correlacion.h */
