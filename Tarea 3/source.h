#ifndef Source_h
#define Source_h
#include "treemap.h"

typedef struct Videojuego Videojuego;
Videojuego* CreateVideojuego(char* nombre, char* fecha, int valoracion, int precio);
void LecturaInicial(TreeMap* mapaVideojuegos);
void ShowVideojuego(Videojuego* vg);
#endif