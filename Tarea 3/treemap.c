#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"
#include "source.h"

typedef struct TreeNode TreeNode;

struct TreeNode {
    Pair * pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}

TreeNode * minimum(TreeNode * x){
    if (x == NULL) return NULL;
    
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}
TreeNode * maximum(TreeNode * x){
    if (x == NULL) return NULL;
    
    while (x->right != NULL) {
        x = x->right;
    }
    return x;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
    
    TreeMap * new = (TreeMap *)malloc(sizeof(TreeMap));
    if (new == NULL) return NULL;
    new->root = new->current = NULL;
    new->lower_than = lower_than;
    return new;
}

void insertTreeMap(TreeMap * tree, void* key, void * value) {
    if (tree == NULL) return;
    
    TreeNode * aux = tree->root;
    TreeNode * parent = NULL;
    
    while (aux != NULL) {
        parent = aux;
        
        if (tree->lower_than(key,aux->pair->key)) {
            aux = aux->left;
        } else{
            aux = aux->right;
        }
    }
    
    TreeNode * new = createTreeNode(key, value);
    
    new->parent = parent;
    
    if (parent == NULL) {
        tree->root = new;
    } else if (tree->lower_than(key,parent->pair->key)) {
        parent->left = new;
    } else {
        parent->right = new;
    }
    tree->current = new;
}

void removeNode(TreeMap * tree, TreeNode* node) {
    //nodo hoja
    if(node->right==NULL && node->left==NULL){
        TreeNode* parent=node->parent;
        if(parent == NULL) tree->root=NULL;
        else if(parent->left==node) parent->left=NULL;
        else if(parent->right==node) parent->right=NULL;
    }else if(node->right!=NULL && node->left!=NULL){ //2 hijos
        TreeNode* aux = node->right;
        aux  = minimum(aux);
        node->pair->key=aux->pair->key;
        node->pair->value=aux->pair->value;
        removeNode(tree, aux);
        return;
    }else{ // 1 hijo
        TreeNode* parent=node->parent;
        TreeNode* child = node->right;
        if(child==NULL) child = node->left;
        child->parent = parent;
        if(parent == NULL) tree->root=child;
        else if(parent->left==node) parent->left=child;
        else if(parent->right==node) parent->right=child;
    }
    free(node->pair);
    free(node); 
    return;

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
    if (tree == NULL || tree->root == NULL) return NULL;
    
    TreeNode * aux = tree->root;
    
    while (aux != NULL) {
        if (tree->lower_than(key, aux->pair->key)) {
            aux = aux->left;
        } else if (tree->lower_than(aux->pair->key, key)) {
            aux = aux->right;
        }else break;
    }
    
    tree->current = aux;
    
    if (aux == NULL) return NULL;
    
    return (void *)aux->pair;
}


Pair * upperBound(TreeMap * tree, void* key) {
    if (tree == NULL || tree->root == NULL) return NULL;
    
    TreeNode * aux = tree->root;
    TreeNode * ub_node = NULL;
    
    while (aux != NULL) {
        if( (ub_node==NULL || tree->lower_than(aux->pair->key, ub_node->pair->key)) &&
           !tree->lower_than(aux->pair->key,key))
           ub_node=aux;

        if (tree->lower_than(key, aux->pair->key)) {
            aux = aux->left;
        } else if (tree->lower_than(aux->pair->key, key)) {
            aux = aux->right;
        }else break;
    }
    
    tree->current = ub_node;

    if (ub_node == NULL) return NULL;
    
    return ub_node->pair;
}

Pair * firstTreeMap(TreeMap * tree) {
    if (tree == NULL || tree->root == NULL) return NULL;
    
    TreeNode * aux = tree->root;
    
    tree->current = minimum(aux);
    
    if (tree->current == NULL) return NULL;
    
    return tree->current->pair;
}

Pair * lastTreeMap(TreeMap * tree) {
    if (tree == NULL || tree->root == NULL) return NULL;
    
    TreeNode * aux = tree->root;
    
    tree->current = maximum(aux);
    
    if (tree->current == NULL) return NULL;
    
    return tree->current->pair;
}

Pair * nextTreeMap(TreeMap * tree) {
    if (tree == NULL || tree->root == NULL || tree->current == NULL) return NULL;
    
    if (tree->current->right != NULL) {
        TreeNode * aux = tree->current->right;

        tree->current = minimum(aux);
        
        return tree->current->pair;
    }
    
    TreeNode * aux = tree->current->parent;
    
    while (aux != NULL && tree->current == aux->right) {
        tree->current = aux;
        aux = aux->parent;
    }
    
    tree->current = aux;
    
    if (aux == NULL) return NULL;
    
    return aux->pair;
}
Pair * prevTreeMap(TreeMap * tree) {
    if (tree == NULL || tree->root == NULL || tree->current == NULL) return NULL;
    
    if (tree->current->left != NULL) {
        TreeNode * aux = tree->current->left;

        tree->current = maximum(aux);
        
        return tree->current->pair;
    }
    
    TreeNode * aux = tree->current->parent;
    
    while (aux != NULL && tree->current == aux->left) {
        tree->current = aux;
        aux = aux->parent;
    }
    
    tree->current = aux;
    
    if (aux == NULL) return NULL;
    
    return aux->pair;
}

void eraseTreeMapTarget(TreeMap * tree, void* key, Pair* target){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    while(node && is_equal(tree,key,node->pair->key)){
    if (VideojuegoCorrecto(target,node->pair)){
        removeNode(tree, node);
        break;}
    else {
        nextTreeMap(tree);
        node = tree->current;
    }
    }
}

int InBounds(TreeMap* tree, void* key, void* keybound){
    return is_equal(tree, key,keybound);
}