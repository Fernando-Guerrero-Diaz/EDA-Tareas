#ifndef Source_h
#define Source_h
#include "list.h"

typedef struct Personaje Personaje;
typedef struct Item Item;
Item* CreateItem(char* nombre,int nivel_o_cantidad);
Personaje* CreatePersonaje(char* numero);
void AgregarItem(char* tipo, char*nombre_item, int nivel_o_cantidad, char* personaje,    List* ListaPersonajes);
void ReadItemList( List* ListaPersonajes);
void MostrarConsumibles(char* personaje, List* ListaPersonajes);
void MostrarEquipables(char* personaje, List* ListaPersonajes);

#endif