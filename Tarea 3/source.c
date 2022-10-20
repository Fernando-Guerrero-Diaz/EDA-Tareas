#include <stdio.h>
#include <stdlib.h>
#include "source.h"
#include <string.h>
#include <stdbool.h>
#define MAXCHAR 1023

typedef struct Videojuego{
    char nombre[80];
    char fecha[15];
    char valoracion[10];
    char precio[20];
}Videojuego;

Videojuego* CreateVideojuego(char* nombre, char* fecha, char* valoracion, char* precio){
    Videojuego* new = (Videojuego *)malloc(sizeof(Videojuego));
    strcpy(new->nombre,nombre);
    strcpy(new->fecha,fecha);
    strcpy(new->valoracion,valoracion);
    strcpy(new->precio,precio);
    return new;
}

const char *get_csv_field (char * tmp, int k) {
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){
        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }
        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }
        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }
        i++;
    }
    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }
    return NULL;
}

void LecturaInicial(TreeMap* VJnombre, TreeMap* VJprecio){

    FILE *fp = fopen("Videojuegos.csv","r");
    char linea[1024];
    char nombre[80];
    char fecha[20];
    char valoracion[10];
    char precio[20];
    char* dato;
    char buffer[80];
    dato = fgets(linea, 1023, fp);
    while (fgets(linea, MAXCHAR, fp) != NULL)
    {
        strcpy(nombre,(char *)get_csv_field(linea, 0));
        strcpy(fecha, get_csv_field(linea, 1));
        strcpy(valoracion, get_csv_field(linea, 2));
        strcpy(precio, get_csv_field(linea, 3));
        
        Videojuego* new = CreateVideojuego(nombre,fecha,valoracion,precio);
        insertTreeMap(VJnombre,new->nombre,new);
        insertTreeMap(VJprecio,new->precio,new);
    }
}

void ShowVideojuego(Videojuego* vg){
    printf("%s\n",vg->nombre);
    printf("%s\n",vg->fecha);
    printf("%s\n",vg->valoracion);
    printf("%s\n",vg->precio);
}

void ShowPrecio(TreeMap* VJprecio, bool MenorAMayor){
    if(MenorAMayor){
    Pair* x = firstTreeMap(VJprecio);
    printf("Mostrando Videojuegos por precio...\n");
    while(x){
        Videojuego* vg = x->value;
        if(vg){
            ShowVideojuego(vg);
            x = nextTreeMap(VJprecio);
        }
        else break;
    }
    }
    else{
        Pair* x = lastTreeMap(VJprecio);
    printf("Mostrando Videojuegos por precio...\n");
    while(x){
        Videojuego* vg = x->value;
        if(vg){
            ShowVideojuego(vg);
            x = prevTreeMap(VJprecio);
            }
        else break;
        }
    }
}

void AgregarVideojuego(TreeMap* VJnombre,TreeMap* VJprecio,char* nombre, char* fecha, char* valoracion, char* precio){
    Videojuego* new = CreateVideojuego(nombre,fecha,valoracion,precio);
    insertTreeMap(VJnombre,new->nombre,new);
    insertTreeMap(VJprecio,new->precio,new);
}