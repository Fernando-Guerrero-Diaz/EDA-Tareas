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
    printf("Opciones de menu:\n MostrarPorPrecio AgregarJuego FiltrarValoracion EliminarJuego Exit\n");
    gets(Input);
    fflush(stdin);
        if (strcmp(Input, "MostrarPorPrecio")==0){
        printf("De menor a mayor? (s / n): ");
      gets(Input);
      fflush(stdin);
       if (strcmp(Input, "s")==0){
        ShowPrecio(VJprecio,true);
       }
       else{
        ShowPrecio(VJprecio,false);
       }
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
        if (strcmp(Input, "EliminarJuego")==0){
      printf("Ingrese nombre de juego a eliminar: ");
      gets(Input);
      fflush(stdin);
      EliminarVideojuego(VJnombre,VJprecio,VJvaloracion,Input);
      printf("\n");
      continue;
        }
        if (strcmp(Input, "AgregarJuego")==0){
      printf("Ingrese nombre de juego: ");
      char nombre[80];
      gets(nombre);
      fflush(stdin);
      printf("Ingrese fecha de lanzamiento:\n");
      char fecha[30];
      gets(fecha);
      fflush(stdin);
      char valoracion[10];
      printf("Ingrese valoracion del juego:\n");
      gets(valoracion);
      fflush(stdin);
    char precio[20];
      printf("Ingrese precio del juego:\n");
      gets(precio);
      fflush(stdin);
      AgregarVideojuego(VJnombre,VJprecio,VJvaloracion,nombre,fecha,valoracion,precio);
      continue;
      }
    if (strcmp(Input, "Exit")==0){
      break;
    }
    else printf("Opcion invalida (Case Sensitive Input)\n");
  }
  return 0;


}