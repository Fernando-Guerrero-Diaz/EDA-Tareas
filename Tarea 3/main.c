#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"

int cutdate (void * str){
	char dest[15];
	strcpy(dest, str);
	char delim[] = "/";
	char *ptr = strtok(dest, delim);
	for (int i = 2;i>0;i--){
		ptr = strtok(NULL, delim);
	}
  int date = atoi(ptr);
	return date;
}


int lower_than_int(void* key1, void* key2){
    int k1 = atoi(key1);
    int k2 = atoi(key2);
    return k1<k2;
}

int lower_than_char(void* key1, void* key2){
    char* k1 = (char*)key1;
    char* k2 = (char*)key2;

    int x = 0;
    while (k1[x]==k2[x]) {
      if (k1[x+1] == 0 && k2[x+1]==0) break;
      if (k1[x+1] == 0) return 1;
      if (k2[x+1] == 0) return 0;
      x++;
    }
    return k1[x]<k2[x];
}

int lower_than_fecha(void* key1, void* key2)
{
  
  char* stra = (char*)key1;
  char* strb = (char*)key2;
  int a = cutdate(stra);
  int b = cutdate(strb);
  
return a<b;
}

int main(){


    TreeMap* VJnombre = createTreeMap(lower_than_char);
    TreeMap* VJfecha = createTreeMap(lower_than_fecha);
    TreeMap* VJprecio = createTreeMap(lower_than_int);
    TreeMap* VJvaloracion = createTreeMap(lower_than_int);
    

    char Input[80];
  while (true){
    printf("Opciones de menu:\n LecturaVideojuegos MostrarPorPrecio AgregarJuego FiltrarValoracion ExportarVideojuegos BuscarJuego JuegoDelAnno Exit\n");
    gets(Input);
    fflush(stdin);
        if (strcmp(Input, "LecturaVideojuegos")==0){

        LecturaVideojuegos(VJnombre,VJfecha,VJprecio,VJvaloracion);
      printf("\n");
      continue;
        }

        if (strcmp(Input, "MostrarPorPrecio")==0){

        ShowPrecio(VJprecio);
      printf("\n");
      continue;
        }
      if (strcmp(Input, "FiltrarValoracion")==0){
      FiltrarValoracion(VJvaloracion);
      printf("\n");
      continue;
        }
        if (strcmp(Input, "BuscarJuego")==0){

      BuscarVideojuego(VJnombre,VJfecha,VJprecio,VJvaloracion);
      printf("\n");
      continue;
        }

        if (strcmp(Input, "ExportarVideojuegos")==0){
      ExportarVideojuegos(VJnombre);
      printf("\n");
      continue;
        }
        if (strcmp(Input, "AgregarJuego")==0){

      AgregarVideojuego(VJnombre,VJfecha,VJprecio,VJvaloracion);
      continue;
      }

      if (strcmp(Input, "JuegoDelAnno")==0){

      JuegoDelAnno(VJfecha);
      printf("\n");
      continue;
        }
    if (strcmp(Input, "Exit")==0){
      break;
    }
    else printf("Opcion invalida (Case Sensitive Input)\n");
  }
  return 0;


}