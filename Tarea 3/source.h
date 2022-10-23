#ifndef Source_h
#define Source_h
#include <stdbool.h>
#include "treemap.h"


typedef struct Videojuego Videojuego;
Videojuego* CreateVideojuego(char* nombre, char* fecha, char* valoracion, char* precio);
void LecturaInicial(TreeMap* VJnombre, TreeMap* VJprecio, TreeMap* VJvaloracion);
void ShowVideojuego(Videojuego* vg);
void ShowPrecio(TreeMap* VJprecio, bool MenorAMayor);
void AgregarVideojuego(TreeMap* VJnombre,TreeMap* VJprecio, TreeMap* VJvaloracion,char* nombre, char* fecha, char* valoracion, char* precio);
void FiltrarValoracion(TreeMap* VJvaloracion, char* valoracion);

#endif