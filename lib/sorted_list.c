/**
 * Functions related to the SortedList. 
 * 
 * This file, all the functions are provided for you.
*/

#include "linked_list.h"
#include "movie.h"


/**
 * Adds an item to the sorted list
 * 
 * @param list the list to add the item to
 * @param movie the movie to add
*/
void add_to_sorted_list(SortedList *list, Movie *movie) {
    node *new_node = __ll__new_node(movie);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return;
    }
    node *curr = list->head;
    node *prev = NULL;
    while (curr != NULL) {
        if (compare_movies(movie, curr->movie) < 0) {
            if (prev == NULL) {
                new_node->next = curr;
                list->head = new_node;
            } else {
                prev->next = new_node;
                new_node->next = curr;
            }
            list->size++;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = new_node;
    list->tail = new_node;
    list->size++;
}

/**
 * Finds a movie in the sorted list based on title. 
 * 
 * @param list the list to search
 * @param title the title of the movie to find
 * @return the movie if found, NULL otherwise
*/
Movie* find_in_sorted_list(SortedList *list, const char * title) {
    node *curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->movie->title, title) == 0) {
            return curr->movie;
        }
        curr = curr->next;
    }
    return NULL;
}


/**
 * Removes a movie from a sorted list based on title.
 * 
 * @param list the list to search
 * @param title the title of the movie to find
 * @return The movie removed or NULL otherwise
*/
Movie * sorted_list_remove(SortedList *list, const char * title) {
    if (list->head == NULL) {
        return NULL;
    }
    node *curr = list->head;
    node *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->movie->title, title) == 0) {
            if (prev == NULL) {
                list->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if (curr == list->tail) {
                list->tail = prev;
            }
            Movie *movie = curr->movie;
            free(curr);
            list->size--;
            return movie;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}