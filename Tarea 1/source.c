#include <stdio.h>
#include <stdlib.h>
#include "source.h"
#include <string.h>
#include <stdbool.h>
#define MAXCHAR 1023

typedef struct Personaje {
	char nombre[30];
	List* ListaEquipables;
	List* ListaConsumibles;
} Personaje;

typedef struct Item {
	char nombre[30];
	int nivelOcantidad;
} Item;

Item* CreateItem(char* nombre,int nivel_o_cantidad){
  Item* item = (Item *)malloc(sizeof(Item)); 
  strcpy(item->nombre, nombre);
  item->nivelOcantidad = nivel_o_cantidad;
  return item;
}

Personaje* CreatePersonaje(char* nombre){
  Personaje* personaje= (Personaje *)malloc(sizeof(Personaje));
  strcpy(personaje->nombre, nombre);
  personaje->ListaConsumibles = createList();
  personaje->ListaEquipables = createList();
  return personaje;
}

void AgregarItem(char* tipo, char* nombre_item, int nivel_o_cantidad, char* personaje, List* ListaPersonajes){
  //printf("Agregando %s a %s, tipo %s\n",nombre_item,personaje,tipo);
	Personaje* personajeX = firstList(ListaPersonajes);
	while (personajeX){
    //printf("\n");
		if (strcmp(personajeX->nombre,personaje)==0){ 
      break;}
		personajeX =nextList(ListaPersonajes);
    //printf("Next\n");
		}
	if(personajeX){
    //printf("Personaje encontrado\n");
		if (strcmp(tipo, "Consumible") == 0){
			List* ListaC = personajeX->ListaConsumibles;
			Item* itemX =firstList(ListaC);
			while(itemX){
        //printf("%s tiene %s\n", personajeX->nombre, itemX->nombre);
				if (strcmp(itemX->nombre, nombre_item)==0){
					itemX->nivelOcantidad += nivel_o_cantidad;
					break;}
				itemX = nextList(ListaC);
      }
			if (itemX==NULL){
        //printf("%s no tiene %s, creando...\n", personajeX->nombre,nombre_item);
        itemX = CreateItem(nombre_item, nivel_o_cantidad);
			
      	pushBack(ListaC,itemX);
			  }
    }
    
    else if (strcmp(tipo, "Equipable") == 0){
			List* ListaE = personajeX->ListaEquipables;
      Item* itemX =CreateItem(nombre_item, nivel_o_cantidad);
			pushBack(ListaE,itemX);
      //printf("Item equipable agregado.\n");
		}

  
    }
   if (personajeX==NULL){
    //printf("no existe\n");
    
    personajeX= CreatePersonaje(personaje);
   // printf("crea %s\n",personajeX->nombre);
    
    if (strcmp(tipo, "Consumible") == 0){
      Item* itemX = CreateItem(nombre_item, nivel_o_cantidad);
			pushFront(personajeX->ListaConsumibles,itemX);
      }
    else if (strcmp(tipo, "Equipable") == 0){
      Item* itemX = CreateItem(nombre_item, nivel_o_cantidad);
			pushFront(personajeX->ListaEquipables,itemX);
      }
    pushFront(ListaPersonajes, personajeX);
  }
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

void ReadItemList( List* ListaPersonajes){
      // Se abre el archivo de mundos csv en modo lectura "r"
    
    FILE *fp = fopen ("items.csv", "r");
  
    //printf("Open file");
    // Cadena para guardar la linea completa del archivo csv
    char linea[1024];
    char tipo[80];
    char nombre[80];
    int cantidad;
    char personaje[80];
    int i;
    int k = 0;
    char* dato;
  
    dato = fgets(linea, 1023, fp);
    while (fgets(linea, MAXCHAR, fp) != NULL)
    {
        strcpy(tipo,(char *)get_csv_field(linea, 0));
        strcpy(nombre, get_csv_field(linea, 1));
        cantidad = atoi(get_csv_field(linea, 2));
        strcpy(personaje, get_csv_field(linea, 3));
        
        //fgets(linea, MAXCHAR, fp);
        //printf("Linea: %s", linea);

       // dato = strtok(linea, ",");

        //char* Tipo= strtok(linea, ",");
      //printf("Tipo: %s\n",tipo);
        //char* nombre_item = strtok(NULL, ",");
      //printf("Nombre item: %s\n",nombre);
       // int nivel_cantidad= atoi(strtok(NULL, ","));
      //printf("Nivel o cantidad: %d\n",cantidad);
       // char* personaje= strtok(NULL, ",");*/
      //printf("Nombre de Personaje:%s\n", personaje);
      //printf("\n");
      AgregarItem(tipo, nombre, cantidad, personaje, ListaPersonajes);
        /*
        while(dato != NULL)
        {

            //printf("Dato: %s\n", dato);
            printf("%s\n", dato);
            dato = strtok(NULL, ",");
        }
      */

    }
  /*
    while (fgets (linea, 1023, fp) != NULL) { // Se lee la linea
      
      char* Tipo;
      char* nombre_item;
      int nivel_cantidad;
      char* personaje;
      
    
    
      printf("%s",Tipo);

      printf("%s",nombre_item);


      printf("%s",personaje);
    
      //AgregarItem(Tipo, nombre_item, nivel_cantidad, personaje, ListaPersonajes);
        k++; if(k==10) break;
      
    }
  */
}
void MostrarConsumibles(char* personaje, List* ListaPersonajes){

  Personaje* personajeX = firstList(ListaPersonajes);
	while (personajeX){

		int i = strcmp(personajeX->nombre,personaje);

    if (i == 0){ 
      break;
      }
		personajeX =nextList(ListaPersonajes);
		}
	if(personajeX){
    	List* ListaC = personajeX->ListaConsumibles;
			Item* itemX =firstList(ListaC);
      if (itemX==NULL){
        printf("Personaje no tiene items consumibles\n");
      }
			while(itemX){
				printf("%s, %d\n", itemX->nombre, itemX->nivelOcantidad);
				itemX = nextList(ListaC);
        }
  }
  else {
    printf("Personaje no existe\n");
  }
  
}
void MostrarEquipables(char* personaje, List* ListaPersonajes){
  Personaje* personajeX = firstList(ListaPersonajes);
	while (personajeX){
		int i = strcmp(personajeX->nombre,personaje);
    if (i == 0) break;
		personajeX =nextList(ListaPersonajes);
		}
	if(personajeX){
    	List* ListaE = personajeX->ListaEquipables;
			Item* itemX =firstList(ListaE);
      if (itemX==NULL){
        printf("Personaje no tiene items equipables\n");
      }
			while(itemX){
				printf("%s, nivel %d\n", itemX->nombre, itemX->nivelOcantidad);
				itemX = nextList(ListaE);
        }
  }
  else {
    printf("Personaje no existe\n");
  }
  
}
  