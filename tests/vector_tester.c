/**
 * Test functions to test the MovieVector Implementation
 * 
 * STUDENT TODO: you should feel free to add your own tests, and
 * make sure you check these tests. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "testing_util.h"
#include "movie_globals.h"

#include "../lib/movie.h"
#include "../lib/vector.h"

// these are the group flags, so you can run tests that only below to a certain group
// For example,  ./test-vector -g ADD -v 
// will only run the tests that have the group tag ADD, printing out both pass and failed dialogs

#define GROUP_GENERAL "GENERAL"
#define GROUP_ADD     "ADD"
#define GROUP_REMOVE  "REMOVE"
#define GROUP_GET     "GET"
#define GROUP_SORTED  "SORTED"

/******************** TESTS ******************/

/**
 * Tests that a new vector is created correctly
 * 
 * @return true if the test passed, false otherwise
 */
bool test_new_vector() {
    MovieVector *vector = new_vector();
    bool passed = true;
    passed &= ASSERT_NOT_NULL(vector);
    passed &= ASSERT_EQUAL(vector->size, 0);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    free_vector(vector);
    return passed;
}


void __debug_print_vector(MovieVector *vector) {
    PRINT_DEBUG("Vector size: %d\n", vector->size);
    PRINT_DEBUG("Vector capacity: %d\n", vector->capacity);
    PRINT_DEBUG("Full vector: %s\n", vector_to_str(vector));
}

/** 
 * Tests vector_insert to make sure a basic insert is
 * correct across various sizes.
 * 
 * @return true if the test passed, false otherwise
*/
bool test_vector_insert() {
    bool passed = true;
    MovieVector *vector = new_vector();

    PRINT_DEBUG("Initializing and empty vector to test vector_insert()\n");
    __debug_print_vector(vector);

    PRINT_DEBUG("Inserting a single movie to the vector at index 0\n");
    PRINT_DEBUG("Inserting movie: %s\n", movie1->title);

    vector_insert(vector, movie1, 0);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 1);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);

    PRINT_DEBUG("Inserting a second movie to the vector at index 0\n");
    PRINT_DEBUG("Inserting movie: %s\n", movie2->title);

    vector_insert(vector, movie2, 0);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 2);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie2);

    PRINT_DEBUG("Inserting a third movie to the vector at index 1\n");
    PRINT_DEBUG("Inserting movie: %s\n", movie3->title);

    vector_insert(vector, movie3, 1);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[1], movie3);

    PRINT_DEBUG("Inserting a fourth movie to the vector at index 2\n");
    PRINT_DEBUG("Inserting movie: %s\n", movie4->title);

    vector_insert(vector, movie4, 2);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 4);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[2], movie4);

    free_vector(vector);
    return passed;
}


/**
 * Tests vector_add to make sure a basic add is
 * correct across various sizes
 * 
 * @return true if the test passed, false otherwise
 */
bool test_vector_add_back() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing and empty vector to test vector_add_back()\n");
   __debug_print_vector(vector);

    PRINT_DEBUG("Adding a single movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie1->title);
    
    vector_add_back(vector, movie1);


   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 1);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);

    PRINT_DEBUG("Adding a second movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie2->title);

    vector_add_back(vector, movie2);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 2);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);


    free_vector(vector);
    return passed;
}


/** Test add front for the Vector
 * @returns true if the tests passed or false if they did not
*/
bool test_vector_add_front() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing and empty vector to test vector_add_front()\n");
   __debug_print_vector(vector);

    PRINT_DEBUG("Adding a single movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie1->title);
    
    vector_add_front(vector, movie1);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 1);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);

    PRINT_DEBUG("Adding a second movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie2->title);
    
    vector_add_front(vector, movie2);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 2);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie2);

    free_vector(vector);
    return passed;
}

/** Reducing capacity of vector, and applying each
 * add to make sure the vector expands correctly each time
 * 
 * @return true if the test passed, false otherwise
*/
bool test_capacity() {
    bool passed = true;
    MovieVector *vector = new_vector();
    vector->capacity = 2;

    PRINT_DEBUG("Initializing and empty vector to test vector_add_front()\n");
   __debug_print_vector(vector);
    
    PRINT_DEBUG("Adding a single movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie1->title);
    
    vector_add_front(vector, movie1);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 1);
    passed &= ASSERT_EQUAL(vector->capacity, 2);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);


    PRINT_DEBUG("Adding a second movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie2->title);
    
    vector_add_back(vector, movie2);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 2);
    passed &= ASSERT_EQUAL(vector->capacity, 2);
    passed &= ASSERT_EQUAL(vector->movies[1], movie2);


    PRINT_DEBUG("Adding a third movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie3->title);
    
    vector_add_back(vector, movie3);

   __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, 4);//doubles
    passed &= ASSERT_EQUAL(vector->movies[2], movie3);


    PRINT_DEBUG("Adding a fourth movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie4->title);
    


    vector_add_back(vector, movie4);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 4);
    passed &= ASSERT_EQUAL(vector->capacity, 4);
    passed &= ASSERT_EQUAL(vector->movies[3], movie4);

    PRINT_DEBUG("Adding a fifth movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie5->title);
    
    vector_add_back(vector, movie5);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 5);
    passed &= ASSERT_EQUAL(vector->capacity, 8);//doubles
    passed &= ASSERT_EQUAL(vector->movies[4], movie5);


    PRINT_DEBUG("Adding a sixth movie to the vector\n");
    PRINT_DEBUG("Adding movie: %s\n", movie6->title);
    
    vector_add_back(vector, movie6);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 6);
    passed &= ASSERT_EQUAL(vector->capacity, 8);
    passed &= ASSERT_EQUAL(vector->movies[5], movie6);


    
    return passed;
}


/** Test remove for the Vector
 * @returns true if the tests passed or false if they did not
*/
bool test_vector_remove_front() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing a vector with two movies to test remove_front\n");
    
    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);

   __debug_print_vector(vector);



    PRINT_DEBUG("Removing the first movie from the vector\n");
    PRINT_DEBUG("Removing movie: %s\n", movie1->title);
    
    Movie *one = vector_remove_front(vector);
 
   __debug_print_vector(vector);
    PRINT_DEBUG("Movie removed: %s\n", one->title);

    passed &= ASSERT_EQUAL(vector->size, 1);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie2);
    passed &= ASSERT_EQUAL(one, movie1);

    PRINT_DEBUG("Removing the second movie from the vector\n");
    PRINT_DEBUG("Removing movie: %s\n", movie2->title);
    
    Movie *two = vector_remove_front(vector);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie removed: %s\n", two->title);

    passed &= ASSERT_EQUAL(vector->size, 0);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(two, movie2);

    free_vector(vector);
    return passed;
}

/**
 * Test vector remove_back to make sure a basic remove is
 * correct across various sizes
 * @return true if tests passed, false otherwise
*/
bool test_vector_remove_back() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing a vector with two movies to test remove_back\n");
    
    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);

   __debug_print_vector(vector);

    PRINT_DEBUG("Removing the second movie from the vector\n");
    PRINT_DEBUG("Removing movie: %s\n", movie2->title);
    
    Movie *two = vector_remove_back(vector);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie removed: %s\n", two->title);

    passed &= ASSERT_EQUAL(vector->size, 1);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);
    passed &= ASSERT_EQUAL(two, movie2);

    PRINT_DEBUG("Removing the first movie from the vector\n");
    PRINT_DEBUG("Removing movie: %s\n", movie1->title);
    
    Movie *one = vector_remove_back(vector);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie removed: %s\n", one->title);

    passed &= ASSERT_EQUAL(vector->size, 0);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(one, movie1);

    free_vector(vector);
    return passed;
}

/** Tests vector_remove with an emphasis of removing
 * movies in the middle of the vector, so will start
 * with a vector of 4 and remove two in the middle there
 * @return true if the tests passed or false if they did not
*/
bool test_vector_remove() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing a vector with four movies to test remove\n");
    
    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);
    vector_add_back(vector, movie3);
    vector_add_back(vector, movie4);

   __debug_print_vector(vector);

    PRINT_DEBUG("Removing the second movie from the vector\n");
    PRINT_DEBUG("Removing movie: %s\n", movie2->title);
    
    Movie *two = vector_remove(vector, 1);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie removed: %s\n", two->title);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);
    passed &= ASSERT_EQUAL(vector->movies[1], movie3);
    passed &= ASSERT_EQUAL(vector->movies[2], movie4);
    passed &= ASSERT_EQUAL(two, movie2);

    PRINT_DEBUG("Removing the third movie from the vector\n");
    PRINT_DEBUG("Removing movie: %s\n", movie3->title);
    
    Movie *three = vector_remove(vector, 1);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie removed: %s\n", three->title);

    passed &= ASSERT_EQUAL(vector->size, 2);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);
    passed &= ASSERT_EQUAL(vector->movies[1], movie4);
    passed &= ASSERT_EQUAL(three, movie3);

    free_vector(vector);
    return passed;
}


/** 
 * Tests all three vector remove functions to make sure
 * they return NULL when they should (empty vectors, and index out of bounds)
 * @return true if the tests passed, false otherwise
*/
bool test_vector_remove_null() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing an empty vector to test remove\n");
    
    PRINT_DEBUG("Removing the first movie from the vector\n");
    
    
    Movie *one = vector_remove_front(vector);

    __debug_print_vector(vector);
    

    passed &= ASSERT_EQUAL(vector->size, 0);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(one);

    PRINT_DEBUG("Removing the last movie from the vector\n");
     
    Movie *two = vector_remove_back(vector);

    __debug_print_vector(vector);
    

    passed &= ASSERT_EQUAL(vector->size, 0);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(two);

    PRINT_DEBUG("Adding movies to the vector to test remove out of bounds\n");

    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);
    vector_add_back(vector, movie3);

    __debug_print_vector(vector);

    PRINT_DEBUG("Removing the movie at index 3 from the vector\n");
    
    Movie *three = vector_remove(vector, 3);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(three);

    PRINT_DEBUG("Removing the movie at index -1 from the vector\n");

    Movie *four = vector_remove(vector, -1);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(four);



    free_vector(vector);
    return passed;
}

/** Tests vector_get with a simple list
 * @returns true if the tests passed or false if they did not
*/
bool test_vector_get() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing a vector with four movies to test get\n");
    
    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);
    vector_add_back(vector, movie3);
    vector_add_back(vector, movie4);

   __debug_print_vector(vector);

    PRINT_DEBUG("Getting the first movie from the vector\n");
    PRINT_DEBUG("Getting movie: %s\n", movie1->title);
    
    Movie *one = vector_get(vector, 0);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie gotten: %s\n", one->title);

    passed &= ASSERT_EQUAL(vector->size, 4);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(one, movie1);

    PRINT_DEBUG("Getting the second movie from the vector\n");
    PRINT_DEBUG("Getting movie: %s\n", movie2->title);
    
    Movie *two = vector_get(vector, 1);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie gotten: %s\n", two->title);

    passed &= ASSERT_EQUAL(vector->size, 4);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(two, movie2);

    PRINT_DEBUG("Getting the third movie from the vector\n");
    PRINT_DEBUG("Getting movie: %s\n", movie3->title);
    
    Movie *three = vector_get(vector, 2);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie gotten: %s\n", three->title);

    passed &= ASSERT_EQUAL(vector->size, 4);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(three, movie3);

    PRINT_DEBUG("Getting the fourth movie from the vector\n");
    PRINT_DEBUG("Getting movie: %s\n", movie4->title);
    
    Movie *four = vector_get(vector, 3);

   __debug_print_vector(vector);
    PRINT_DEBUG("Movie gotten: %s\n", four->title);

    passed &= ASSERT_EQUAL(vector->size, 4);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(four, movie4);

    free_vector(vector);
    return passed;
}

/** Tests vector get when it attempts to pull from out of bounds.
 * @returns true if the tests passed or false if they did not
*/
bool test_vector_get_null() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing an empty vector to test get\n");
    
    PRINT_DEBUG("Getting the first movie from the vector\n");
    
    Movie *one = vector_get(vector, 0);

    __debug_print_vector(vector);
    

    passed &= ASSERT_EQUAL(vector->size, 0);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(one);

    PRINT_DEBUG("Getting the last movie from the vector\n");
     
    Movie *two = vector_get(vector, -1);

    __debug_print_vector(vector);
    

    passed &= ASSERT_EQUAL(vector->size, 0);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(two);

    PRINT_DEBUG("Adding movies to the vector to test get out of bounds\n");

    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);
    vector_add_back(vector, movie3);

    __debug_print_vector(vector);

    PRINT_DEBUG("Getting the movie at index 3 from the vector\n");
    
    Movie *three = vector_get(vector, 3);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(three);

    PRINT_DEBUG("Getting the movie at index -1 from the vector\n");

    Movie *four = vector_get(vector, -1);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_NULL(four);

    free_vector(vector);
    return passed;
}

/** 
 * Tests vector_is_empty to make sure it returns true when it should
 * and false when it should
*/
bool test_vector_is_empty() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing an empty vector to test is_empty\n");
    
    passed &= ASSERT_TRUE(vector_is_empty(vector));

    PRINT_DEBUG("Adding movies to the vector to test is_empty\n");

    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);
    vector_add_back(vector, movie3);

    __debug_print_vector(vector);

    passed &= ASSERT_FALSE(vector_is_empty(vector));

    free_vector(vector);
    return passed;
}

/** 
 * Tests vector_to_str to make sure it returns the correct string
 * 
 * @return true if the test passed, false otherwise
*/
bool test_vector_to_str() {
    bool passed = true;
    MovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing an empty vector to test to_str\n");
    
    char *str = vector_to_str(vector);

    passed &= ASSERT_EQUAL(strcmp(str, "[]"), 0);

    PRINT_DEBUG("Adding movies to the vector to test to_str\n");

    vector_add_back(vector, movie1);
    vector_add_back(vector, movie2);
    vector_add_back(vector, movie3);
    


    __debug_print_vector(vector);
    free(str);
    str = vector_to_str(vector);

    passed &= ASSERT_STR_EQUAL(str, "[{title: A Movie One, id: 1}, {title: B Movie Two, id: 2}, {title: C Movie Three, id: 3}]");


    free(str);
    free_vector(vector);

    return passed;
}

/**
 * Tests vector_add_sorted to make sure it adds movies in the correct order
 * 
 * @return true if the test passed, false otherwise
*/
bool test_vector_add_sorted() {
    bool passed = true;
    SortedMovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing an empty vector to test add_sorted\n");
    
    PRINT_DEBUG("Adding movies to the vector to test add_sorted\n");

    add_to_sorted_vector(vector, movie3);
    add_to_sorted_vector(vector, movie1);
    add_to_sorted_vector(vector, movie4);
    add_to_sorted_vector(vector, movie2);

    __debug_print_vector(vector);

    passed &= ASSERT_EQUAL(vector->size, 4);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie1);
    passed &= ASSERT_EQUAL(vector->movies[1], movie2);
    passed &= ASSERT_EQUAL(vector->movies[2], movie3);
    passed &= ASSERT_EQUAL(vector->movies[3], movie4);

    free_vector(vector);
    return passed;
}


/**
 * Tests find_in_sorted_vector to make sure it finds movies correctly
 * 
 * @return true if the test passed, false otherwise
*/
bool test_find_in_sorted_vector() {
    bool passed = true;
    SortedMovieVector *vector = new_vector();
    PRINT_DEBUG("Initializing an empty vector to test find_in_sorted_vector\n");
    
    PRINT_DEBUG("Adding movies to the vector to test find_in_sorted_vector\n");

    add_to_sorted_vector(vector, movie3);
    add_to_sorted_vector(vector, movie1);
    add_to_sorted_vector(vector, movie4);
    add_to_sorted_vector(vector, movie2);

    __debug_print_vector(vector);

    Movie *found = find_in_sorted_vector(vector, "A Movie One");
    PRINT_DEBUG("Found movie: %s\n", found->title);

    passed &= ASSERT_EQUAL(found, movie1);

    found = find_in_sorted_vector(vector, "B Movie Two");
    PRINT_DEBUG("Found movie: %s\n", found->title);

    passed &= ASSERT_EQUAL(found, movie2);

    found = find_in_sorted_vector(vector, "C Movie Three");
    PRINT_DEBUG("Found movie: %s\n", found->title);

    passed &= ASSERT_EQUAL(found, movie3);

    found = find_in_sorted_vector(vector, "D Movie Four");
    PRINT_DEBUG("Found movie: %s\n", found->title);

    passed &= ASSERT_EQUAL(found, movie4);


    found = find_in_sorted_vector(vector, "Should not find");
    PRINT_DEBUG("Searched for movie that should have returned NULL, it returned: %s\n",  
        found == NULL ? "NULL" : found->title);

    free_vector(vector);
    return passed;
}

/**
 * Tests sorted vector remove removes files correctly
 * 
 * @return true if the test passed, false otherwise
*/
bool test_sorted_vector_remove() {
    bool passed = true;
    SortedMovieVector *vector = new_vector();
    
    PRINT_DEBUG("Adding movies to the vector to test remove\n");

    add_to_sorted_vector(vector, movie3);
    add_to_sorted_vector(vector, movie1);
    add_to_sorted_vector(vector, movie4);
    add_to_sorted_vector(vector, movie2);

    __debug_print_vector(vector);

    Movie * removed = sorted_vector_remove(vector, movie1->title);
    PRINT_DEBUG("Removed movie: %s\n", removed->title);

    passed &= ASSERT_EQUAL(vector->size, 3);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie2);
    passed &= ASSERT_EQUAL(vector->movies[1], movie3);
    passed &= ASSERT_EQUAL(vector->movies[2], movie4);
    passed &= ASSERT_EQUAL(removed, movie1);

    removed = sorted_vector_remove(vector, movie2->title);
    PRINT_DEBUG("Removed movie: %s\n", removed->title);

    passed &= ASSERT_EQUAL(vector->size, 2);
    passed &= ASSERT_EQUAL(vector->capacity, INITIAL_CAPACITY);
    passed &= ASSERT_EQUAL(vector->movies[0], movie3);
    passed &= ASSERT_EQUAL(vector->movies[1], movie4);
    passed &= ASSERT_EQUAL(removed, movie2);




    free_vector(vector);
    return passed;
}

/*************************** end tests ***********/

/**
 * Adds every testing function to the testing set.
 * Includes the name of the test, the group tag, and the function to run.
 */
TestingSet *init_testing_set()
{
    TestingSet *set = new_testing_set();
    add_test(set, "new_vector() creates an empty MovieVector", GROUP_GENERAL,
                test_new_vector); 
    add_test(set, "vector_insert() inserts a movie into the vector", GROUP_ADD,
                test_vector_insert);       
    add_test(set, "vector_add_back() adds a movie to the back of the vector", GROUP_ADD,
                test_vector_add_back); 
    add_test(set, "vector_add_front() adds a movie to the front of the vector", GROUP_ADD,
                test_vector_add_front);
    add_test(set, "vector's capacity changes when set low and movies are added past it", GROUP_ADD,
                test_capacity);
    add_test(set, "vector_remove_front() removes a movie from the front of the vector", GROUP_REMOVE,
                test_vector_remove_front);
    add_test(set, "vector_remove_back() removes a movie from the back of the vector", GROUP_REMOVE,
                test_vector_remove_back);
    add_test(set, "vector_remove() removes a movie from the middle of the vector", GROUP_REMOVE,
                test_vector_remove);
    add_test(set, "vector_remove(),front(),back() returns NULL when removing from an empty vector", GROUP_REMOVE,
                test_vector_remove_null);
    add_test(set, "vector_get() gets a movie from the vector", GROUP_GET,
                test_vector_get);
    add_test(set, "vector_get() returns NULL when getting from an empty vector, or index out of bounds on a vector with items", GROUP_GET,
                test_vector_get_null);
    add_test(set, "vector_is_empty() returns true when the vector is empty, and false when it is not", GROUP_GENERAL,
                test_vector_is_empty);
    add_test(set, "vector_to_str() returns the correct string representation of the vector", GROUP_GENERAL,
                test_vector_to_str);
    add_test(set, "vector_add_sorted() adds movies to the vector in the correct order", GROUP_SORTED,
                test_vector_add_sorted);
    add_test(set, "find_in_sorted_vector() finds movies in the sorted vector", GROUP_SORTED,
                test_find_in_sorted_vector);
    add_test(set, "sorted_vector_remove() properly removes by title", GROUP_SORTED,
             test_sorted_vector_remove);

    return set;
}

/**
 * Runs the tests for the linked list implementation.
 *
 * @param start_test the test to start running from
 * @param end_test the test to stop running at
 */
int main(const int argc, const char *argv[])
{
    init_movies(); // initialize a few movies to help us out

    TestingSet *set = init_testing_set(); // initialize the testing set

    // now proccess args and run the test program
    check_for_verbose(argc, argv); // check for verbose flag and set the global variable found in testing_util.h
    check_for_debug(argc, argv);     // check for debug flag and set the global variable found in testing_util.h

    const char *group_tag = check_for_group_tag(argc, argv); // check for group tag and set the global variable found in testing_util.h

    if (group_tag == NULL)
    {
        int test_start_loc = 1;                                                                      // the index to start looking for tests at, but may change if -v is there
        int start_test = get_int_arg(argc, argv, 1, 0, &test_start_loc);                             // get the start test, default to 0
        int end_test = get_int_arg(argc, argv, test_start_loc + 1, set->num_tests-1, &test_start_loc); // get the end test, default to 0
        PRINT_VERBOSE("Running tests %d through %d\n", start_test, end_test);
        run_tests(set, start_test, end_test);
    }
    else
    {
        PRINT_VERBOSE("Running tests for group %s\n", group_tag);
        run_tests_group(set, (char *)group_tag);
    }

    free_movies();
    free_testing_set(set);
    return 0;
}