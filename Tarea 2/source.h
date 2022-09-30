#ifndef Source_h
#define Source_h
#include "hashmap.h"
#include "list.h"
typedef struct Propiedad Propiedad;
Propiedad* CreatePropiedad(char* id, char* ciudad, char* direccion, char* tipo, char* capacidad, char* valor);
void ReadPropiedades(List* IdsPropiedades,HashMap* Propiedades);
void AddToMaps(List* Ids, HashMap* Propiedades, HashMap* XCiudad, HashMap* XTipo, HashMap* XCapacidad);
void MostrarPropiedad(Propiedad* prop);








#endif