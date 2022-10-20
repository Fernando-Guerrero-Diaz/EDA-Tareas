#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source.h"

int lower_than_int(void* key1, void* key2){
    int k1 = *((int*) (key1));
    int k2 = *((int*) (key2));
    return k1<k2;
}

int main(){
    TreeMap* mapaVideojuegos = createTreeMap(lower_than_int);
    LecturaInicial(mapaVideojuegos);
    Pair* first = firstTreeMap(mapaVideojuegos);
    printf("%s\n",first->key);
    Videojuego* fvg = first->value;
    if (fvg){
        ShowVideojuego(fvg);
    }
    
    Pair* second = nextTreeMap(mapaVideojuegos);
    printf("%s\n",second->key);
    Videojuego* svg = second->value;
    if (svg){
        ShowVideojuego(svg);
    }
    
    printf("testing...\n");
    char Input[40];

    gets(Input);
}