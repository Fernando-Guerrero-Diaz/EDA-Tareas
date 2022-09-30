#ifndef Source_h
#define Source_h
#include "hashmap.h"
#include "list.h"
#include <stdbool.h>

typedef struct Propiedad Propiedad;
struct Propiedad{
    char id[20];
    char ciudad[80];
    char direccion[80];
    char tipo[80];
    char capacidad[20];
    char valor[20];
    bool favorito;
};
Propiedad* CreatePropiedad(char* id, char* ciudad, char* direccion, char* tipo, char* capacidad, char* valor);
void ReadPropiedades(List* IdsPropiedades,HashMap* Propiedades);
void AddToMaps(List* Ids, HashMap* Propiedades, HashMap* XCiudad, HashMap* XTipo, HashMap* XCapacidad);
void MostrarPropiedad(Propiedad* prop);








#endif