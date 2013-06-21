/**
 * @file conversiones.h
 * @brief  Fichero para la transformacion de imagenes y signal
 * 
 */

#ifndef _CONVERSIONES_H_
#define _CONVERSIONES_H_

#include <iostream>
#include "signal.h"
#include "imagen.h"

using namespace std;

/**
 * @brief Transforma una imagen a un signal.
 * @param  im Imagen que se va a transformar.
 * @return    Devuelve el signal transformado.
 */
Signal ImagenToSignal(const Imagen &im);

/**
 * @brief Transforma un signal a una imagen.
 * @param  s Signal que se va a transformar.
 * @return   Devuelve la imagen transformada.
 */
Imagen SignalToImagen(const Signal &s);


#endif

/* Fin Fichero: conversiones.h */
