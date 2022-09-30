#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"

struct IdData{
  char id[20];
};

int main(){
    HashMap* Propiedades = createMap(40);
    List* Ids= createList();
    ReadPropiedades(Ids,Propiedades);
    
    HashMap* PropiedadesXCiudad = createMap(20);
    HashMap* PropiedadesXTipo = createMap(20);
    HashMap* PropiedadesXCapacidad = createMap(20);
    //AddToMaps(Ids,Propiedades,PropiedadesXCiudad,PropiedadesXTipo,PropiedadesXCapacidad);

    IdData* aux = firstList(Ids);
    printf("%s\n",aux->id);
    aux= nextList(Ids);
    printf("%s\n",aux->id);
    
    Pair* pair = searchMap(Propiedades,aux->id);
    if (pair){
    printf("searchMap works\n");
    Propiedad* prop = pair->value;
    MostrarPropiedad(prop);
    }
    else printf("searchMap returned NULL\n");

    pair = firstMap(Propiedades);
    pair = nextMap(Propiedades);
    if (pair){
        printf("firstMap works\n");
    Propiedad* prop = (Propiedad*) pair->value;
    printf("%s%s",aux->id,  ((char*) prop->id));
    MostrarPropiedad(prop);
    }
    else printf("firstMap returned NULL\n");

    Pair* pairXCiudad = firstMap(PropiedadesXCiudad);
    List* XCiudadAux = pair->value;
    Propiedad* prop2 = firstList(XCiudadAux);
    /*
    if (prop2){
    MostrarPropiedad(prop2);
    }
    */
    
   printf("testing...");
    char Input[40];

    gets(Input);
}