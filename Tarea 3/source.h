#ifndef Source_h
#define Source_h
#include <stdbool.h>
#include "treemap.h"


typedef struct Videojuego Videojuego;
Videojuego* CreateVideojuego(char* nombre, char* fecha, char* valoracion, char* precio);
void LecturaInicial(TreeMap* VJnombre, TreeMap* VJprecio, TreeMap* VJvaloracion);
void ShowVideojuego(Videojuego* vg);
void ShowPrecio(TreeMap* VJprecio);
void AgregarVideojuego(TreeMap* VJnombre,TreeMap* VJprecio, TreeMap* VJvaloracion);
void FiltrarValoracion(TreeMap* VJvaloracion);
bool VideojuegoCorrecto(Pair* par1, Pair* par2);
void EliminarVideojuego(TreeMap* VJnombre,TreeMap* VJprecio, TreeMap* VJvaloracion, char* nombre);
void ExportarVideojuegos(char* filename, TreeMap* VJnombre);
void JuegoDelAnno(TreeMap* VJfecha, char* anno);
void BuscarVideojuego(TreeMap* VJnombre, TreeMap* VJprecio, TreeMap* VJvaloracion, char* nombre);

#endif