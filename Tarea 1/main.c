//uwu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"

int main() {
  //printf("main start\n");
  List* ListaPersonajes = createList();
  //printf("List created\n");
  ReadItemList(ListaPersonajes);
  /*
  printf("Items consumibles de Personaje 1\n");
  MostrarConsumibles("Personaje 1", ListaPersonajes);
  
  printf("\n");
  printf("Items equipables de Personaje 1\n");
  MostrarEquipables("Personaje 1", ListaPersonajes);
 */
  
  char Input[30];
  while (true){
    printf("Opciones de menu:\n MostrarConsumibles MostrarEquipables MostrarPersonajes EliminarDePersonaje EliminarDeTodos MostrarTodoItem Exit\n");
    gets(Input);
    fflush(stdin);
    if (strcmp(Input, "MostrarConsumibles")==0){
      printf("Ingrese numero de personaje: ");
      gets(Input);
      fflush(stdin);
      char name[30];
      strcpy(name,"Personaje ");
      strcat(name,Input);
      printf("%s\n",name);
      MostrarConsumibles(name, ListaPersonajes);
      printf("\n");
      continue;
    }
        if (strcmp(Input, "MostrarEquipables")==0){
      printf("Ingrese numero de personaje: ");
      gets(Input);
      fflush(stdin);
      char name[30];
      strcpy(name,"Personaje ");
      strcat(name,Input);
      printf("%s\n",name);
      MostrarEquipables(name, ListaPersonajes);
      printf("\n");
      continue;
    }
      if (strcmp(Input, "EliminarDePersonaje")==0){
      printf("Ingrese numero de personaje: ");
      gets(Input);
      fflush(stdin);
      char name[30];
      strcpy(name,"Personaje ");
      strcat(name,Input);
      printf("Ingrese Item a eliminar de %s\n",name);
      char item[30];
      gets(item);
      fflush(stdin);
      printf("Ingrese cantidad a eliminar\n");
      gets(Input);
      fflush(stdin);
      int cantidad = atoi(Input);
      EliminarDePersonaje(name,item,cantidad,ListaPersonajes);
      printf("\n");
      continue;
      }
      if (strcmp(Input, "EliminarDeTodos")==0){
      printf("Ingrese Item a eliminar de todos\n");
      char item[30];
      gets(item);
      fflush(stdin);
      EliminarDeTodos(item,ListaPersonajes);
      printf("\n");
      continue;
      }
    if (strcmp(Input, "MostrarPersonajes")==0){
      MostrarPersonajes(ListaPersonajes);
      continue;
    }
    if (strcmp(Input, "MostrarTodoItem")==0){
      MostrarTodoItem(ListaPersonajes);
      continue;
    }
    if (strcmp(Input, "Exit")==0){
      break;
    }
    else printf("Opcion invalida (Case Sensitive Input)\n");
  }
  return 0;
}