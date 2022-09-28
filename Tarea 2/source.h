#ifndef Source_h
#define Source_h
#include "hashmap.h"
#include "list.h"
typedef struct Propiedad Propiedad;
Propiedad* CreatePropiedad(int id, char* ciudad, char* direccion, char* tipo, int capacidad, int valor);
void ReadPropiedades(List* IdsPropiedades,HashMap* Propiedades);
void AddToMaps(List* Ids, HashMap* Propiedades, HashMap* XCiudad, HashMap* XTipo, HashMap* XCapacidad);
void MostrarPropiedad(Propiedad* prop);








#endif