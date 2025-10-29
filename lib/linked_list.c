/**
 * Singly linked list implementation.
 *
 * @author: Emily Despres
 * @class: CS 5008
 * @term: Fall 2025
 */

#include <stdlib.h>
#include <stdbool.h>


#include "movie.h"
#include "linked_list.h"


/** 
 * Creates a new linked list node.
*/
node * __ll__new_node(Movie *movie) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->movie = movie;
    new_node->next = NULL;
    return new_node;
}

/**
 * Creates a new linked list.
 * 
 * @return a pointer to the new linked list
 */
LinkedList *new_linked_list() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/**
 * Frees the memory associated with a linked list.
 * 
 * Frees just the linked list and nodes, the movies
 * stored are not freed. 
 * @param list the linked list to free
 */
void free_linked_list(LinkedList *list) {
    node *curr = list->head;
    node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}

/**
 * Frees the memory, including memory allocated
 * to movies stored in the link list. 
 * 
 * @param list the linked list to free
*/
void clear_and_free_linked_list(LinkedList *list) {
    node *curr = list->head;
    node *next;
    while (curr != NULL) {
        next = curr->next;
        free_movie(curr->movie);
        free(curr);
        curr = next;
    }
    free(list);
}

/**
 * Adds a movie to the front of a linked list.
 * 
 * Don't forget to update the tail pointer if the list is empty,
 * as when there is a single node, head and tail should both point
 * towards it.
 * 
 * @param list the linked list to add to
 * @param movie the movie to add
 */
void ll_add_front(LinkedList *list, Movie *movie) {
    // STUDENT TODO: Implement

    node *new_node = __ll__new_node(movie); // create new node to hold movie
    new_node->next = list->head; // point new node to current head
    if (list->tail == NULL) { // if list was empty
        list->tail = new_node; // update tail to point to new node
    }
    list->head = new_node; // update head to point to new node
    list->size++; // increment size of list
}

/**
 * Adds a movie to the back of a linked list.
 *
 * Don't forget to update the head pointer if the list is empty,
 * as when there is a single node, head and tail should both point
 * towards it.
 *
 * @param list the linked list to add to
 * @param movie the movie to add
 */
void ll_add_back(LinkedList *list, Movie *movie) {
    // STUDENT TODO: Implement

    node *new_node = __ll__new_node(movie); // create new node to hold movie
    new_node->next = NULL; // since last node next pointer is NULL

    // if list not empty link current tail to new node
    if (list->tail != NULL) { 
        list->tail->next = new_node;
    } else {
        // if list empty update head to point to new node
        list->head = new_node;
    }
    list->tail = new_node; // update tail to point to new node
    list->size++; // increase size of list
}


/**
 * Inserts a movie into a linked list at a given index.
 * 
 * if n == 0, safe to call ll_add_front, if n == list->size, safe to call ll_add_back
 * 
 * if n is out of bounds, do nothing (return early)
 * 
 * @param list the linked list to insert into
 * @param movie the movie to insert
 * @param n the index to insert at
 */
void ll_insert(LinkedList *list, Movie *movie, int n) {
   // STUDENT TODO: Implement

    // if index is negative or greater than list size
    if (n < 0 || n > list->size) 
        return;

    // if inserting at the front (index 0)
    if (n == 0) {
        ll_add_front(list, movie);
        return;
    }

    // if inserting at the back (index equal to size of list)
    if (n == list->size) {
        ll_add_back(list, movie);
        return;
    }

    node *new_node = __ll__new_node(movie); // create new node to hold movie
    node *curr = list->head; // start at the head of the list
    for (int i = 0; i < n - 1; i++) { // find node just before insertion location
        curr = curr->next; // move to the next node
    }
    new_node->next = curr->next; // link new node to next node 
    curr->next = new_node; // link previous node to new node
    list->size++; // increase size of list
}


/**
 * Removes the first movie from a linked list.
 * 
 * Don't forget if there is only one item in the list, and it is removed,
 * to update the tail pointer.
 * 
 * @param list the linked list to remove from
 * @return the movie that was removed
 */
Movie * ll_remove_front(LinkedList *list) {
    Movie *movie = NULL;
    
    // STUDENT TODO: Implement

    if (list->head == NULL) {
        return NULL; // list is empty, nothing to remove
    }
    node *temp = list->head; // save pointer to current head node (to be removed) 
    movie = temp->movie; // save movie from node to return later
    list->head = temp->next; // update head to point to next node
    
    if (list->head == NULL) {
        list->tail = NULL; // if list is now empty, update tail to NULL
    }
    free(temp); // free memory of removed node
    list->size--; // decrease size of list
    return movie;
}

/**
 * Removes the last movie from a linked list.
 * 
 * Don't forget if there is only one item in the list, and it is removed,
 * to update the head pointer.
 * 
 * @param list the linked list to remove from
 * @return the movie that was removed
 */
Movie * ll_remove_back(LinkedList *list) {
    Movie* movie = NULL;
    // STUDENT TODO: Implement

    if (list->head == NULL) {
        return NULL; // list is empty, nothing to remove
    }

    // if there is only one node in the list
    if (list->head == list->tail) {
        movie = list->head->movie; // get movie from the only node
        free(list->head); // free the only node
        list->head = NULL; // update head to NULL
        list->tail = NULL; // update tail to NULL
        list->size--; // decrease size of list
        return movie; // return removed movie
    }

    // more than one node in the list
    node *curr = list->head; // start at head of list
    while (curr->next != list->tail) {
        curr = curr->next; // traverse until second to last node
    }

    movie = list->tail->movie; // get movie from tail node
    free(list->tail); // free the tail node
    list->tail = curr; // update tail to second to last node
    curr->next = NULL; // set new tail next pointer NULL
    list->size--; // decrease size of list
    return movie; // return removed movie
}

/**
 * Removes a movie from a linked list at a given index.
 * 
 * if n == 0, safe to call ll_remove_front, if n == list->size - 1, safe to call ll_remove_back
 * 
 * if n is out of bounds, return NULL
 * 
 * @param list the linked list to remove from
 * @param n the index to remove at
 * @return the movie that was removed
 */
Movie * ll_remove(LinkedList *list, int n) {
    Movie * movie = NULL;
    // STUDENT TODO: Implement

    // if index is negative or larger than list size
    if (n < 0 || n >= list->size) 
        return NULL; // nothing to remove, invalid index

    // if removing from front (index 0)
    if (n == 0) {
        return ll_remove_front(list);
    }

    // if removing at the back (index is last valid position)
    if (n == list->size - 1) {
        return ll_remove_back(list);
    }

    // removing from middle
    node *curr = list->head; // start at head of list
    for (int i = 0; i < n - 1; i++) { // find node just before removal location
        curr = curr->next; // move to the next node
    }
    node *to_remove = curr->next; // node to be removed
    movie = to_remove->movie; // get movie from node to be removed
    curr->next = to_remove->next; // link previous node to next node
    free(to_remove); // free memory of removed node
    list->size--; // decrease size of list
    return movie; // return removed movie
}

/**
 * Gets a movie from a linked list at a given index.
 * 
 * if n is out of bounds, return NULL
 * 
 * @param list the linked list to get from
 * @param n the index to get at
 * @return the movie at the given index
 */
Movie* ll_get(LinkedList *list, int n) {
    node *curr = list->head;
    if (n < 0 || n >= list->size) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        curr = curr->next;
    }
    return curr->movie;
}

/**
 * Checks if a linked list contains a given movie.
 * 
 * Rare if a linked list contains a movie more than once, but
 * if so, just immediately return true.
 * 
 * @param list the linked list to check
 * @param movie the movie to check for
 * @return true if the linked list contains the movie, false otherwise
 */
bool ll_contains(LinkedList *list, Movie *movie) {
    node *curr = list->head;
    while (curr != NULL) {
        if (curr->movie == movie) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

/**
 * Checks if a linked list is empty.
 * 
 * @param list the linked list to check
 * @return true if the linked list is empty, false otherwise
 */
bool ll_is_empty(LinkedList *list) {
    return list->size == 0;
}

/**
 * Converts a linked list to a string representation.
 * 
 * @param list the linked list to convert
 * @return a string representation of the linked list
 */
char* ll_to_str(LinkedList *list) {
    
    char *str = (char *)malloc(sizeof(char) * (MAX_MOVIE_STR_LEN + 3) * list->size);
    if (list->size == 0) {
        strcpy(str, "[]");
        return str; // early exit
    }
    // implied else
    strcpy(str, "[");
    node *curr = list->head;
    while (curr != list->tail) {
        char *movie_str = movie_to_str(curr->movie);
        strcat(str, movie_str);
        strcat(str, ", ");
        free(movie_str);
        curr = curr->next;
    }
    // now add the tail
    char *movie_str = movie_to_str(curr->movie);
    strcat(str, movie_str);
    free(movie_str);
    strcat(str, "]");

    return str;
}

