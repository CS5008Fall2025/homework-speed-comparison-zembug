/**
 * Contains functions for the sorted vector struct
 *
 * @author: Emily Despres
 * @class: CS 5008
 * @term: Fall 2025
**/

#include "vector.h"
#include "movie.h"


/**
 * adds a movie to the sorted vector.
 * 
 * Based on the movie (compare_movies), it will find the correct index
 * using a linear search.
 * 
 * The moment it finds that the movie to add is greater than the
 * current movie, it will insert it at that next index calling vector_insert.
 * 
 * 
 * @param vector the vector to add the movie to
 * @param movie the movie to add
*/
void add_to_sorted_vector(SortedMovieVector * vector, Movie * movie) {
    // STUDENT TODO: implement this function
    int i = 0; // start at beginning of vector

    // loop through vector to find correct index to insert movie
    while (i < vector->size) {
        // get title currently at index i
        Movie * current_movie = vector->movies[i];
        // compare titles (case insensitive)
        int cmp = strcasecmp(movie->title, current_movie->title); 
        // if new title is alphabetically after current title
        if (cmp > 0) {
            i++; // move to next index
        } else {
            break; // found correct index
        }
    }
    vector_insert(vector, movie, i); // insert movie at correct index
}

/**
 * Finds a movie in the sorted vector based on the title only of the movie.
 *
 * strcasecmp is used to compare the titles, so the search is case insensitive.
 *
 * For example: int cmp = strcasecmp(title, movie->title);
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one. 
 *
 * @param vector the vector to search
 * @param title the title of the movie to find
 * @return the movie if found, NULL otherwise
 */
Movie * find_in_sorted_vector(SortedMovieVector * vector, const char * title) {
    // STUDENT TODO: implement this function
    int left = 0; // start of search rangee
    int right = vector->size - 1; // end of search range

    while (left <= right) {
        int middle = left + (right - left) / 2; // calculate middle index
        Movie * middle_movie = vector->movies[middle]; // get movie at middle index
        // compare titles (case insensitive)
        int cmp = strcasecmp(title, middle_movie->title); 

        if (cmp == 0) {
            return middle_movie; // found the movie
        } else if (cmp < 0) {
            right = middle - 1; // search left half
        } else {
            left = middle + 1; // search right half
        }
    }
    return NULL; // movie not found
}

/**
 * Checks if the sorted vector contains a movie with the given title.
 *
 * Very similar to find_in_sorted_vector, but instead of just finding
 * the movie will call vector_remove(vector, index) to remove the movie
 * returning the resulted removed movie.
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one.
 *
 * @param vector the vector to check
 * @param title the title to check for
 * @return the movie removed, NULL otherwise
 */
Movie* sorted_vector_remove(SortedMovieVector *vector, const char *title){
    // STUDENT TODO: implement this function
    int left = 0; // start of search range
    int right = vector->size - 1; // end of search range

    while (left <= right) {
        int middle = left + (right - left) / 2; // calculate middle index
        Movie * middle_movie = vector->movies[middle]; // get movie at middle index
        // compare titles (case insensitive)
        int cmp = strcasecmp(title, middle_movie->title); 

        if (cmp == 0) {
            return vector_remove(vector, middle); // found the movie: remove, return result
        } else if (cmp < 0) {
            right = middle - 1; // search left half
        } else {
            left = middle + 1; // search right half
        }
    }
    return NULL; // movie not found
}
