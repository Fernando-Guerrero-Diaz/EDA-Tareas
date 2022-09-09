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
void MostrarPersonajes(List* ListaPersonajes);
int ContarEquipables(Personaje* personaje);
int ContarConsumibles(Personaje* personaje);
void EliminarDePersonaje(char* personaje, char* nombreItem, int cantidad, List* ListaPersonajes);
void EliminarDeTodos(char* nombreItem, List* ListaPersonajes);
void MostrarTodoItem(List* ListaPersonajes);
void ExportarItems(char* filename,List* ListaPersonajes);
#endif