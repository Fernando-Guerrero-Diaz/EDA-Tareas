#ifndef TREEMAP_h
#define TREEMAP_h

typedef struct TreeMap TreeMap;

typedef struct Pair {
     void * key;
     void * value;
} Pair;

TreeMap * createTreeMap(int (*lower_than_int) (void* key1, void* key2));

int is_equal(TreeMap* tree, void* key1, void* key2);

void insertTreeMap(TreeMap * tree, void* key, void * value);

void eraseTreeMap(TreeMap * tree, void* key);

Pair * searchTreeMap(TreeMap * tree, void* key);

Pair * upperBound(TreeMap * tree, void* key);

Pair * firstTreeMap(TreeMap * tree);

Pair * lastTreeMap(TreeMap * tree);

Pair * nextTreeMap(TreeMap * tree);

Pair * prevTreeMap(TreeMap * tree);

void eraseTreeMapTarget(TreeMap * tree, void* key, Pair* target);

int InBounds(TreeMap* tree, void* key, void* keybound);

#endif /* TREEMAP_h */
