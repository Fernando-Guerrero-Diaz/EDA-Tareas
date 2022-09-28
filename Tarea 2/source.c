#include <stdio.h>
#include <stdlib.h>
#include "source.h"
#include <string.h>
#include <stdbool.h>
#include "hashmap.h"

#define MAXCHAR 1023

typedef struct Propiedad{
    int id;
    char ciudad[80];
    char direccion[80];
    char tipo[80];
    int capacidad;
    int valor;
    bool favorito;
}Propiedad;

Propiedad* CreatePropiedad(int id, char* ciudad, char* direccion, char* tipo, int capacidad, int valor){
    Propiedad* new = (Propiedad*)malloc(sizeof(Propiedad));
    new->id = id;
    strcpy(new->ciudad,ciudad);
    strcpy(new->direccion,direccion);
    strcpy(new->tipo,tipo);
    new->capacidad=capacidad;
    new->valor=valor;
    new->favorito = false;
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

void ReadPropiedades(List* IdsPropiedades,HashMap* Propiedades){

    FILE *fp = fopen ("propiedades.csv", "r");
    char linea[1024];
    int id;
    char ciudad[80];
    char direccion[80];
    char tipo[80];
    int capacidad;
    int valor;
    char idKey[20];
    char* dato;
  
    dato = fgets(linea, 1023, fp);
    while (fgets(linea, MAXCHAR, fp) != NULL)
    {   
        strcpy(idKey,(char*)get_csv_field(linea,0));
        id = atoi(idKey);
        strcpy(ciudad,(char *)get_csv_field(linea, 1));
        strcpy(direccion, get_csv_field(linea, 2));
        strcpy(tipo, get_csv_field(linea, 3));
        capacidad = atoi(get_csv_field(linea, 4));
        valor = atoi(get_csv_field(linea, 5));
        Propiedad* new = CreatePropiedad(id,ciudad,direccion,tipo,capacidad,valor);
        MostrarPropiedad(new);
        insertMap(Propiedades, idKey, new);
        pushBack(IdsPropiedades,idKey);

    }
}
void AddToMaps(List* Ids, HashMap* Propiedades, HashMap* XCiudad, HashMap* XTipo, HashMap* XCapacidad){
    void* id = firstList(Ids);
    while(id){
        Pair* aux = searchMap(Propiedades,id);
        Propiedad* prop = aux->value;
        char* cityKey = prop->ciudad;
        PushToListInMap(XCiudad,cityKey,prop);
        char* TipoKey = prop->tipo;
        PushToListInMap(XTipo,TipoKey,prop);
        int* CapaKey = &(prop->capacidad);
        PushToListInMap(XCapacidad,CapaKey,prop);
    }
}
void MostrarPropiedad(Propiedad* prop){
    printf("id: %d\n",prop->id);
    printf("Ciudad: %s\n",prop->ciudad);
    printf("Direccion: %s\n", prop->direccion);
    printf("Capacidad: %d\n", prop->capacidad);
    printf("Valor: %d\n", prop->valor);
    printf("\n");
}