/**
 * A binary search tree implementation designed
 * to hold Movie structs.
 * 
 * @author: STUDENT ADD YOUR NAME
 * @class: CS 5008
 * @term: UPDATE WITH CURRENT SEMESTER
*/

#ifndef BST_H
#define BST_H


#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "movie.h"

#define POST_ORDER 0
#define IN_ORDER 1
#define PRE_ORDER 2
#define BREADTH_FIRST 3

typedef struct bst_node {
    Movie * movie;
    struct bst_node * left;
    struct bst_node * right;
} BSTNode;


typedef struct bst {
    BSTNode * root;
    int size;
} BST;

BST * new_bst();
void free_bst(BST * bst);
void clear_and_free_bst(BST * bst);
void bst_add(BST * bst, Movie * movie);
void bst_remove(BST * bst, Movie * movie);


Movie * bst_find(BST * bst, const char * title);
char* bst_to_str(BST * bst, int ordering);

Movie ** bst_to_sorted_array(BST * bst);


#endif // BST_H