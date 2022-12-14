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

void LecturaVideojuegos(TreeMap* VJnombre, TreeMap* VJfecha, TreeMap* VJprecio, TreeMap* VJvaloracion){
    char Input[80];
    printf("Ingrese nombre de archivo origen (sin .csv)\n");
    gets(Input);
    fflush(stdin);
    strcat(Input,".csv");
    printf("Importando de %s...\n",Input);

    FILE *fp = fopen(Input,"r");
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
        insertTreeMap(VJfecha,new->fecha,new);
        insertTreeMap(VJprecio,new->precio,new);
        insertTreeMap(VJvaloracion,new->valoracion,new);
    }
}

void ShowVideojuego(Videojuego* vg){
    printf("%s\n",vg->nombre);
    printf("%s\n",vg->fecha);
    printf("%s\n",vg->valoracion);
    printf("%s\n",vg->precio);
}

void ShowPrecio(TreeMap* VJprecio){
    bool MenorAMayor = true;
    char Input[10];
    printf("De menor a mayor? (s / n): ");
    gets(Input);
    fflush(stdin);
    if (strcmp(Input, "n")==0){
        MenorAMayor = false;
    }
    

    if(MenorAMayor){
    Pair* x = firstTreeMap(VJprecio);
    printf("Mostrando Videojuegos de menor a mayor precio...\n");
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
    printf("Mostrando Videojuegos de mayor a menor precio...\n");
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

void AgregarVideojuego(TreeMap* VJnombre,TreeMap* VJfecha, TreeMap* VJprecio, TreeMap* VJvaloracion){
      printf("Ingrese nombre de juego: \n");
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
    Videojuego* new = CreateVideojuego(nombre,fecha,valoracion,precio);
    insertTreeMap(VJnombre,new->nombre,new);
    insertTreeMap(VJfecha,new->fecha,new);
    insertTreeMap(VJprecio,new->precio,new);
    insertTreeMap(VJprecio,new->valoracion,new);
}

void FiltrarValoracion(TreeMap* VJvaloracion){
    char valoracion[10];
    printf("Ingrese valoracion: ");
    gets(valoracion);
    fflush(stdin);
    Pair* x = upperBound(VJvaloracion,valoracion);
    while(x){
        Videojuego* vg = x->value;
        if(vg){
            ShowVideojuego(vg);
            x = nextTreeMap(VJvaloracion);
        }
        else break;
    }

}

bool VideojuegoCorrecto(Pair* par1, Pair* par2){
    Videojuego* vg1 = par1->value;
    Videojuego* vg2 = par2->value;
    if (vg1 && vg2){
        if (strcmp(vg1->nombre,vg2->nombre)== 0){
            return true;
        }
    }
    return false;
}

void EliminarVideojuego(TreeMap* VJnombre,TreeMap* VJfecha,TreeMap* VJprecio, TreeMap* VJvaloracion, char* nombre){
    Pair* target = searchTreeMap(VJnombre,nombre);
    if(target==NULL){
        //printf("Videojuego no encontrado.\n");
         return;}
    Videojuego* vg = target->value;
    eraseTreeMapTarget(VJfecha,vg->fecha,target);
    eraseTreeMapTarget(VJprecio,vg->precio,target);
    eraseTreeMapTarget(VJvaloracion,vg->valoracion,target);
    eraseTreeMap(VJnombre,nombre);
    //printf("%s eliminado.\n", nombre);
}

void ExportarVideojuegos(TreeMap* VJnombre){
    char Input[80];
    printf("Ingrese nombre de archivo destino (sin .csv)\n");
    gets(Input);
    fflush(stdin);
    strcat(Input,".csv");
    printf("Exportando a %s...\n",Input);
    FILE *fpt; fpt = fopen(Input, "w+");
    fprintf(fpt,"Nombre,a??o de salida,valoracion,precio\n");
    Pair* par = firstTreeMap(VJnombre);
    while(par){
        Videojuego* vg = par->value;
        fprintf(fpt,"%s,%s,%s,%s\n",vg->nombre,vg->fecha,vg->valoracion,vg->precio);
        par = nextTreeMap(VJnombre);
    }
    fclose(fpt);
}

void JuegoDelAnno(TreeMap* VJfecha){
    char anno[10];
    printf("Ingrese anno: ");
    gets(anno);
    fflush(stdin);
    char start[15] = "01/01/";
    char end[15] = "32/12/";
    strcat(start,anno);
    strcat(end,anno); 
    Videojuego* goty = NULL;
    Videojuego* aux;
    Pair* par = upperBound(VJfecha,start);
    while (par && InBounds(VJfecha,par->key,end)){
        if (goty==NULL){
            goty = par->value;
        }
        else{
            aux = par->value;
            if (atoi(aux->valoracion) >atoi(goty->valoracion)){
                goty = aux;
            }
        }
        par = nextTreeMap(VJfecha);
    }
    if (goty){
        printf("Juego del anno %s:\n", anno);
        ShowVideojuego(goty);
    }
    else printf("No se ha encontrado un juego del anno\n");

}

void BuscarVideojuego(TreeMap* VJnombre, TreeMap* VJfecha,TreeMap* VJprecio, TreeMap* VJvaloracion){
    char nombre[80];
    printf("Ingrese nombre de juego a buscar: ");
    gets(nombre);
    fflush(stdin);
    Pair* par = searchTreeMap(VJnombre,nombre);
    char Input[80];
    if (par){
        Videojuego* vg = par->value;
        ShowVideojuego(vg);
        printf("Desea modificar este juego? (s / n)\n");
        gets(Input);
        fflush(stdin);
       if (strcmp(Input, "s")==0){
        EliminarVideojuego(VJnombre,VJfecha,VJprecio,VJvaloracion,nombre);
        printf("Eliminar por completo? (s/n) \n");
        gets(Input);
        fflush(stdin);
            if (strcmp(Input, "n")==0){
                printf("Modificando a %s...\n", nombre);
                AgregarVideojuego(VJnombre,VJfecha, VJprecio,VJvaloracion);
                printf("Videojuego modificado.\n");
            }
            else printf("%s eliminado.\n", nombre);
       }
    }
}