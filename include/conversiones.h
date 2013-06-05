#ifndef _CONVERSIONES_H_
#define _CONVERSIONES_H_

#include <iostream>
#include "signal.h"
#include "imagen.h"

using namespace std;

Signal& ImagenToSignal(const Imagen &im);
Imagen& SignalToImagen(const Signal &s);


#endif
