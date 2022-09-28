#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"

int main(){
    HashMap* Propiedades = createMap(40,0);
    List* Ids= createList();
    ReadPropiedades(Ids,Propiedades);
    
    HashMap* PropiedadesXCiudad = createMap(20,0);
    HashMap* PropiedadesXTipo = createMap(20,0);
    HashMap* PropiedadesXCapacidad = createMap(20,0);
    //AddToMaps(Ids,Propiedades,PropiedadesXCiudad,PropiedadesXTipo,PropiedadesXCapacidad);

    int* aux = firstList(Ids);
    printf("%d\n",*aux);
    /*
    Pair* pair = searchMap(Propiedades,aux);
    Propiedad* prop = pair->value;
    MostrarPropiedad(prop);
    /*
    aux = nextList(Ids);
    pair = searchMap(Propiedades,(char*)aux);
    prop = pair->value;
    MostrarPropiedad(prop);
    */
   printf("testing...");
    char Input[40];

    gets(Input);
}