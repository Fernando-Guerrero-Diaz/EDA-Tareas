#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"

int lower_than_int(void* key1, void* key2){
    int k1 = atoi(key1);
    int k2 = atoi(key2);
    return k1<k2;
}

int lower_than_char(void* key1, void* key2){
    char* k1 = (char*)key1;
    char* k2 = (char*)key2;

    int x = 0;
    while (k1[x+1] != 0 && k1[x]==k2[x]) x++;
    return k1[x]<k2[x];
}


int main(){
    TreeMap* VJnombre = createTreeMap(lower_than_char);
    TreeMap* VJprecio = createTreeMap(lower_than_int);
    TreeMap* VJvaloracion = createTreeMap(lower_than_int);
    LecturaInicial(VJnombre,VJprecio,VJvaloracion);


    char Input[80];
  while (true){
    printf("Opciones de menu:\n MostrarPorPrecio AgregarJuego FiltrarValoracion ExportarVideojuegos BuscarJuego Exit\n");
    gets(Input);
    fflush(stdin);
        if (strcmp(Input, "MostrarPorPrecio")==0){

        ShowPrecio(VJprecio);
      printf("\n");
      continue;
        }
      if (strcmp(Input, "FiltrarValoracion")==0){
      printf("Ingrese valoracion: ");
      gets(Input);
      fflush(stdin);
      FiltrarValoracion(VJvaloracion,Input);
      printf("\n");
      continue;
        }
        if (strcmp(Input, "BuscarJuego")==0){
      printf("Ingrese nombre de juego a buscar: ");
      gets(Input);
      fflush(stdin);
      BuscarVideojuego(VJnombre,VJprecio,VJvaloracion,Input);
      printf("\n");
      continue;
        }

        if (strcmp(Input, "ExportarVideojuegos")==0){
      printf("Ingrese nombre de archivo destino (sin .csv)\n");
      gets(Input);
      fflush(stdin);
      strcat(Input,".csv");
      printf("Exportando a %s...\n",Input);
      ExportarVideojuegos(Input, VJnombre);
      printf("\n");
      continue;
        }
        if (strcmp(Input, "AgregarJuego")==0){

      AgregarVideojuego(VJnombre,VJprecio,VJvaloracion);
      continue;
      }
    if (strcmp(Input, "Exit")==0){
      break;
    }
    else printf("Opcion invalida (Case Sensitive Input)\n");
  }
  return 0;


}