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
  
  printf("Items consumibles de Personaje 1\n");
  MostrarConsumibles("Personaje 1", ListaPersonajes);
  
  printf("\n");
  printf("Items equipables de Personaje 1\n");
  MostrarEquipables("Personaje 1", ListaPersonajes);
  printf("\n");
    printf("Items consumibles de Personaje 2\n");
  MostrarConsumibles("Personaje 2", ListaPersonajes);
  
  printf("\n");
  printf("Items equipables de Personaje 2\n");
  MostrarEquipables("Personaje 2", ListaPersonajes);
  printf("\n");
    printf("Items consumibles de Personaje 3\n");
  MostrarConsumibles("Personaje 3", ListaPersonajes);
  
  printf("\n");
  printf("Items equipables de Personaje 3\n");
  MostrarEquipables("Personaje 3", ListaPersonajes);
  printf("\n");
    printf("Items consumibles de Personaje 4\n");
  MostrarConsumibles("Personaje 4", ListaPersonajes);
  
  printf("\n");
  printf("Items equipables de Personaje 4\n");
  MostrarEquipables("Personaje 4", ListaPersonajes);
  
  char Input[30];
  while (true){
    printf("Opciones de menu: MostrarConsumibles MostrarEquipables Exit\n");
    gets(Input);
    fflush(stdin);
    if (strcmp(Input, "MostrarConsumibles")==0){
      printf("Ingrese número de personaje: ");
      gets(Input);
      fflush(stdin);
      char name[30];
      strcpy(name,"Personaje ");
      strcat(name,Input);
      printf("%s\n",name);
      MostrarConsumibles(name, ListaPersonajes);
      printf("\n");
    }
        if (strcmp(Input, "MostrarEquipables")==0){
      printf("Ingrese número de personaje: ");
      gets(Input);
      fflush(stdin);
      char name[30];
      strcpy(name,"Personaje ");
      strcat(name,Input);
      printf("%s\n",name);
      MostrarEquipables(name, ListaPersonajes);
      printf("\n");
    }
    if (strcmp(Input, "Exit")==0){
      break;
    }
  }
  return 0;
}