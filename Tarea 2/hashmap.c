#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"
#include "list.h"

typedef struct HashMap HashMap;

typedef struct IdData IdData;
struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair(char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}
struct IdData{
  char id[20];
};

IdData* createId(char* id){
  IdData* new = (IdData*)malloc(sizeof(IdData));
  strcpy(new->id,id);
}
void PushToListInMap(HashMap* ListMap, char* key, void* data){
    Pair* searchResult = searchMap(ListMap,key);
    if(searchResult){
        List* lista= searchResult->value;
        pushBack(lista,data);
    }
    else{
        List* lista = createList();
        pushFront(lista,data);
        insertMap(ListMap,key,lista);
    }
 }

long Hash( void * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

long simpleHash(void* key, long capacity){
 /* unsigned long hash = atol(key);
  return hash%capacity;
  */

}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
  long keyhash = Hash(key,map->capacity);
  while(1){
  if(map->buckets[keyhash]==NULL || map->buckets[keyhash]->key==NULL){
    Pair* newpair = createPair(key,value);
    map->buckets[keyhash]= newpair;
    map->size +=1;
    map->current = keyhash;
    break;
  }
  if(map->buckets[keyhash] && is_equal(map->buckets[keyhash]->key,key)) break;
  keyhash++;
  keyhash = keyhash%map->capacity;
    }
}

void enlarge(HashMap * map) {
  Pair** oldBuckets = map->buckets;
  int oldCapacity = map->capacity;
  map->capacity= oldCapacity*2;
  map->buckets = (Pair **) calloc (map->capacity,sizeof(Pair *));
  map->size=0;
  for(int i=0; i <= oldCapacity ;i++){
    if (oldBuckets[i]  && oldBuckets[i]->key){
    insertMap(map, oldBuckets[i]->key,oldBuckets[i]->value);
    }
  }
}



HashMap * createMap(long capacity) {
  HashMap * map = (HashMap *)malloc(sizeof(HashMap));
  map->buckets = (Pair **) calloc (capacity,sizeof(Pair *));
  map->capacity = capacity;
  map->current = -1;
    return map;
}

void eraseMap(HashMap * map,  char * key) {    
  Pair* eliminarpair = searchMap(map,key);
  if (eliminarpair !=NULL){
    eliminarpair->key = NULL;
    map->size--;
  }

}

Pair * searchMap(HashMap * map,  char * key) {   
    long idx = Hash(key, map->capacity);
    while (map->buckets[idx] != NULL && is_equal(map->buckets[idx]->key, key) == 0) 
        idx = (idx + 1) % map->capacity;
    
    if (map->buckets[idx] == NULL || map->buckets[idx]->value == NULL) return NULL;
    
    map->current = idx;
    
    return (void *)map->buckets[idx];
}

Pair * firstMap(HashMap * map) {
    map->current = 0;
    while(1){
      if(map->buckets[map->current] && map->buckets[map->current]->key){
        return map->buckets[map->current];
      }
      map->current++;
      if (map->current >= map->capacity) return NULL;
      }
}

Pair * nextMap(HashMap * map) {
  map->current++;
  while(1){
    if (map->current>=map->capacity) return NULL;
    if(map->buckets[map->current] && map->buckets[map->current]->key){
        return map->buckets[map->current];
      }
    map->current++;
    }
}
