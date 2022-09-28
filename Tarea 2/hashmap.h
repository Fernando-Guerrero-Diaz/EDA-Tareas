
#ifndef HashMap_h
#define HashMap_h


typedef struct HashMap HashMap;

typedef struct Pair {
     void * key;
     void * value;
} Pair;

HashMap * createMap(long capacity, int hash_style);

void insertMap(HashMap * table, void * key, void * value);

void eraseMap(HashMap * table, void * key);

Pair * searchMap(HashMap * table, void * key);

Pair * firstMap(HashMap * table);

Pair * nextMap(HashMap * table);

void enlarge(HashMap * map);

void PushToListInMap(HashMap* ListMap, void* key, void* data);

#endif /* HashMap_h */
