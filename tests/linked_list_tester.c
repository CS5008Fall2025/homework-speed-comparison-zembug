/**
 * Contains tests to test the linked list implementation.
 * 
 * STUDENT TODO: You should feel free to modify this file adding their own
 * tests if they feel any are missing. 
 * 
 * If you implemented a double linked list instead of as singled linked
 * list, this test file should still work. If it doesn't, please double
 * check your implementation that you haven't modified any of the core
 * functions/layout (such as head/tail naming, etc).
*/


#include <stdio.h>

#include "../lib/movie.h"
#include "../lib/linked_list.h"

#include "testing_util.h"
#include "movie_globals.h"


#define GROUP_GENERAL  "GENERAL"
#define GROUP_ADD      "ADD"
#define GROUP_REMOVE   "REMOVE"
#define GROUP_GET      "GET"
#define GROUP_SORTED   "SORTED"




/******** TESTS  ****************/

/**
 * Tests the new_linked_list() function.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_new_linked_list() {
    LinkedList *list = new_linked_list();
    bool passed = true;
    passed &= ASSERT_EQUAL(list->size, 0);
    passed &= ASSERT_NULL(list->head);
    passed &= ASSERT_NULL(list->tail);
    free(list);
    return passed;
}

/**
 * Tests the ll_add_front() function.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_ll_add_front() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_front(list, movie1);
    PRINT_DEBUG("Testing adding movie1 to the front of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie1->title = %s\n", movie1->title);
    passed &= ASSERT_EQUAL(list->size, 1);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);

    ll_add_front(list, movie2);
    PRINT_DEBUG("Testing adding movie2 to the front of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie2->title = %s\n", movie2->title);

    passed &= ASSERT_EQUAL(list->size, 2);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie2), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);
    
    ll_add_front(list, movie3);
    PRINT_DEBUG("Testing adding movie3 to the front of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie3->title = %s\n", movie3->title);


    passed &= ASSERT_EQUAL(list->size, 3);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie3), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);
    free_linked_list(list);
    return passed;
}

/**
 * Tests the ll_add_back() function.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_ll_add_back() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_back(list, movie1);
    PRINT_DEBUG("Testing adding movie1 to the back of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie1->title = %s\n", movie1->title);


    passed &= ASSERT_EQUAL(list->size, 1);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);
    
    ll_add_back(list, movie2);
    PRINT_DEBUG("Testing adding movie2 to the back of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie2->title = %s\n", movie2->title);

    passed &= ASSERT_EQUAL(list->size, 2);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie2), 0);
    
    ll_add_back(list, movie3);
    PRINT_DEBUG("Testing adding movie3 to the back of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie3->title = %s\n", movie3->title);

    passed &= ASSERT_EQUAL(list->size, 3);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie3), 0);
    free_linked_list(list);
    return passed;
}

/**
 * Tests the ll_insert() function.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_ll_insert() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_insert(list, movie1, 0);
    PRINT_DEBUG("Testing adding movie1 to the list at index 0");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie1->title = %s\n", movie1->title);
   
    passed &= ASSERT_EQUAL(list->size, 1);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);
    
    ll_insert(list, movie2, 0);
    PRINT_DEBUG("Testing adding movie2 to the list at index 0");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie2->title = %s\n", movie2->title);

    passed &= ASSERT_EQUAL(list->size, 2);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie2), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);
    
    ll_insert(list, movie3, 1);
    PRINT_DEBUG("Testing adding movie3 to the list at index 1");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("list->head->next->movie->title = %s\n", list->head->next->movie->title);
    PRINT_DEBUG("movie3->title = %s\n", movie3->title);


    passed &= ASSERT_EQUAL(list->size, 3);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie2), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->head->next->movie, movie3), 0);
    free_linked_list(list);
    return passed;
}

/**
 * Tests the ll_insert() function when the index is out of bounds.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_ll_insert_out_of_bounds() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_insert(list, movie1, 1);
    PRINT_DEBUG("Testing adding movie1 to the list at index 1, when list is empty");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head = %s\n", ASSERT_NULL(list->head) ? "NULL" : "NOT NULL");
    PRINT_DEBUG("list->tail = %s\n", ASSERT_NULL(list->tail) ? "NULL" : "NOT NULL");

    passed &= ASSERT_EQUAL(list->size, 0);
    passed &= ASSERT_NULL(list->head);
    passed &= ASSERT_NULL(list->tail);

    ll_insert(list, movie2, -1);
    PRINT_DEBUG("Testing adding movie2 to the list at index -1, when list is empty");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head = %s\n", ASSERT_NULL(list->head) ? "NULL" : "NOT NULL");
    PRINT_DEBUG("list->tail = %s\n", ASSERT_NULL(list->tail) ? "NULL" : "NOT NULL");


    passed &= ASSERT_EQUAL(list->size, 0);
    passed &= ASSERT_NULL(list->head);
    passed &= ASSERT_NULL(list->tail);
    
    
    ll_add_front(list, movie1);
    ll_insert(list, movie2, 2);
    PRINT_DEBUG("Testing adding movie2 to the list at index 2, when list has 1 element");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("Properly added movie1->title = %s\n", movie1->title);
    PRINT_DEBUG("Invalid add movie2->title = %s\n", movie2->title);

    passed &= ASSERT_EQUAL(list->size, 1);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie1), 0);
    free_linked_list(list);
    return passed;
}



/**
 * Tests the ll_remove_front() function.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_ll_remove_front() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_front(list, movie1);
    ll_add_front(list, movie2);
    ll_add_front(list, movie3);
    passed &= ASSERT_EQUAL(list->size, 3);
    PRINT_DEBUG("creating a list of size %d\n", list->size);

    Movie *removed1 = ll_remove_front(list);
    PRINT_DEBUG("Testing removing movie3 from the front of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed1->title = %s\n", removed1->title);

    passed &= ASSERT_EQUAL(compare_movies(removed1, movie3), 0);
    passed &= ASSERT_EQUAL(list->size, 2);

    Movie *removed2 = ll_remove_front(list);
    PRINT_DEBUG("Testing removing movie2 from the front of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed2->title = %s\n", removed2->title);

    passed &= ASSERT_EQUAL(compare_movies(removed2, movie2), 0);
    passed &= ASSERT_EQUAL(list->size, 1);

    Movie *removed3 = ll_remove_front(list);
    PRINT_DEBUG("Testing removing movie1 from the front of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed3->title = %s\n", removed3->title);
    
    passed &= ASSERT_EQUAL(compare_movies(removed3, movie1), 0);
    passed &= ASSERT_EQUAL(list->size, 0);

    Movie *removed4 = ll_remove_front(list);

    PRINT_DEBUG("Testing removing a movie from the front of the list when the list is empty");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("result = %s\n", ASSERT_NULL(removed4) ? "NULL" : "NOT NULL");

    passed &= ASSERT_NULL(removed4);
    passed &= ASSERT_EQUAL(list->size, 0);
    passed &= ASSERT_NULL(list->head);
    passed &= ASSERT_NULL(list->tail);
    free_linked_list(list);
    return passed;
}


/**
 * Tests the ll_remove_back() function.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_ll_remove_back() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_back(list, movie1);
    ll_add_back(list, movie2);
    ll_add_back(list, movie3);
    PRINT_DEBUG("creating a list of size %d\n", list->size)
    passed &= ASSERT_EQUAL(list->size, 3);

    Movie *removed1 = ll_remove_back(list);
    PRINT_DEBUG("Testing removing movie3 from the back of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed1->title = %s\n", removed1->title);

    passed &= ASSERT_EQUAL(compare_movies(removed1, movie3), 0);
    passed &= ASSERT_EQUAL(list->size, 2);

    Movie *removed2 = ll_remove_back(list);
    PRINT_DEBUG("Testing removing movie2 from the back of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed2->title = %s\n", removed2->title);

    passed &= ASSERT_EQUAL(compare_movies(removed2, movie2), 0);
    passed &= ASSERT_EQUAL(list->size, 1);

    // STUDENT - here is an example if you need to add more debug statements to help you out.
    /* PRINT_DEBUG("Before removing movie1 from the back of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("list->head->movie->title = %s\n", list->head->movie->title);
    PRINT_DEBUG("list->tail->movie->title = %s\n", list->tail->movie->title);
    PRINT_DEBUG("movie1->title = %s\n", movie1->title);
    */

    Movie *removed3 = ll_remove_back(list);
    PRINT_DEBUG("Testing removing movie1 from the back of the list");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed3->title = %s\n", removed3->title);

    passed &= ASSERT_EQUAL(compare_movies(removed3, movie1), 0);
    passed &= ASSERT_EQUAL(list->size, 0);
    
    Movie * removed4 = ll_remove_back(list);
    PRINT_DEBUG("Testing removing a movie from the back of the list when the list is empty");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("result = %s\n", ASSERT_NULL(removed4) ? "NULL" : "NOT NULL");

    passed &= ASSERT_NULL(removed4);
    passed &= ASSERT_EQUAL(list->size, 0);
    passed &= ASSERT_NULL(list->head);
    passed &= ASSERT_NULL(list->tail);
    free_linked_list(list);
    return passed;
}

/**
 * Tests the ll_remove() function.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_ll_remove() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_back(list, movie1);
    ll_add_back(list, movie2);
    ll_add_back(list, movie3);
    PRINT_DEBUG("creating a list of size %d\n", list->size)
    passed &= ASSERT_EQUAL(list->size, 3);

    Movie *removed1 = ll_remove(list, 1);
    PRINT_DEBUG("Testing removing movie2 from the list at index 1");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed1->title = %s\n", removed1->title);

    passed &= ASSERT_EQUAL(compare_movies(removed1, movie2), 0);
    passed &= ASSERT_EQUAL(list->size, 2);

    Movie *removed2 = ll_remove(list, 0);
    PRINT_DEBUG("Testing removing movie1 from the list at index 0");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed2->title = %s\n", removed2->title);

    passed &= ASSERT_EQUAL(compare_movies(removed2, movie1), 0);
    passed &= ASSERT_EQUAL(list->size, 1);

    Movie *removed3 = ll_remove(list, 0);
    PRINT_DEBUG("Testing removing movie3 from the list at index 0");
    PRINT_DEBUG("list->size = %d\n", list->size);
    PRINT_DEBUG("removed3->title = %s\n", removed3->title);

    passed &= ASSERT_EQUAL(compare_movies(removed3, movie3), 0);
    passed &= ASSERT_EQUAL(list->size, 0);
    
    free_linked_list(list);
    return passed;
}

/**
 * Tests the ll_remove() function when the index is out of  bounds.
*/
bool test_ll_remove_out_of_bounds() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_back(list, movie1);
    ll_add_back(list, movie2);
    ll_add_back(list, movie3);
    PRINT_DEBUG("creating a list of size %d\n", list->size)

    PRINT_DEBUG("Testing removing a movie from the list at index 3");
    passed &= ASSERT_EQUAL(list->size, 3);

    PRINT_DEBUG("Testing removing a movie from the list at index -1");
    passed &= ASSERT_NULL(ll_remove(list, -1));
    passed &= ASSERT_EQUAL(list->size, 3);

 
    free_linked_list(list);
    return passed;
}


/**
 * Tests the ll_get() function.
 * @return true if the test passed, false if it failed
*/
bool test_ll_get() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_back(list, movie1);
    ll_add_back(list, movie2);
    ll_add_back(list, movie3);
    PRINT_DEBUG("creating a list of size %d\n", list->size)

    Movie *movie = ll_get(list, 0);
    PRINT_DEBUG("Testing getting a movie from the list at index 0");
    PRINT_DEBUG("movie->title = %s\n", movie->title);

    passed &= ASSERT_EQUAL(compare_movies(movie, movie1), 0);
    passed &= ASSERT_EQUAL(list->size, 3);

    movie = ll_get(list, 1);
    PRINT_DEBUG("Testing getting a movie from the list at index 1");
    PRINT_DEBUG("movie->title = %s\n", movie->title);

    passed &= ASSERT_EQUAL(compare_movies(movie, movie2), 0);
    passed &= ASSERT_EQUAL(list->size, 3);

    movie = ll_get(list, 2);
    PRINT_DEBUG("Testing getting a movie from the list at index 2");
    PRINT_DEBUG("movie->title = %s\n", movie->title);

    passed &= ASSERT_EQUAL(compare_movies(movie, movie3), 0);
    passed &= ASSERT_EQUAL(list->size, 3);

   
    free_linked_list(list);
    return passed;
}

/**
 * Tests the ll_get() function when the index is out of bounds.
 * @return true if the test passed, false if it failed
*/
bool test_ll_get_out_of_bounds() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    ll_add_back(list, movie1);
    ll_add_back(list, movie2);
    ll_add_back(list, movie3);
    PRINT_DEBUG("creating a list of size %d\n", list->size)

    PRINT_DEBUG("Testing getting a movie from the list at index 3");
    passed &= ASSERT_NULL(ll_get(list, 3));
    passed &= ASSERT_EQUAL(list->size, 3);

    PRINT_DEBUG("Testing getting a movie from the list at index -1");
    passed &= ASSERT_NULL(ll_get(list, -1));
    passed &= ASSERT_EQUAL(list->size, 3);

    free_linked_list(list);
    list = new_linked_list();

    PRINT_DEBUG("Testing getting a movie from the list at index 0 when the list is empty");
    passed &= ASSERT_NULL(ll_get(list, 0));
    passed &= ASSERT_EQUAL(list->size, 0);


    return passed;
}

/**
 * Tests the ll_is_empty() function.
 * @return true if the test passed, false if it failed
*/
bool test_ll_is_empty() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    
    PRINT_DEBUG("Testing ll_is_empty() on an empty list");
    passed &= ASSERT_TRUE(ll_is_empty(list));

    PRINT_DEBUG("Testing ll_is_empty() on a list with one element added via add_back");
    ll_add_back(list, movie1);
    passed &= ASSERT_FALSE(ll_is_empty(list));

    free_linked_list(list);
    return passed;
}


/**
 * Tests the ll_to_str() function.
 * @return true if the test passed, false if it failed
*/
bool test_ll_to_str() {
    bool passed = true;
    LinkedList *list = new_linked_list();
    char *str = ll_to_str(list);
    PRINT_DEBUG("Testing ll_to_str() on an empty list");
    PRINT_DEBUG("str = %s\n", str);
    passed &= ASSERT_STR_EQUAL(str, "[]");
    free(str);

    ll_add_back(list, movie1);
    str = ll_to_str(list);
    PRINT_DEBUG("Testing ll_to_str() on a list with one element added via add_back");
    PRINT_DEBUG("str = %s\n", str);
    passed &= ASSERT_STR_EQUAL(str, "[{title: A Movie One, id: 1}]");
    free(str);

    ll_add_back(list, movie2);
    str = ll_to_str(list);
    PRINT_DEBUG("Testing ll_to_str() on a list with two elements added via add_back");
    PRINT_DEBUG("str = %s\n", str);
    passed &= ASSERT_STR_EQUAL(str, "[{title: A Movie One, id: 1}, {title: B Movie Two, id: 2}]");
    free(str);

    ll_add_back(list, movie3);
    str = ll_to_str(list);
    PRINT_DEBUG("Testing ll_to_str() on a list with three elements added via add_back");
    PRINT_DEBUG("str = %s\n", str);
    passed &= ASSERT_STR_EQUAL(str, "[{title: A Movie One, id: 1}, {title: B Movie Two, id: 2}, {title: C Movie Three, id: 3}]");
    free(str);

    free_linked_list(list);
    return passed;
}


/**
 * Adds movies to a sorted_list and checks that they are in the correct order.
 * 
 * @return true if the test passed, false if it failed
*/
bool test_sorted_list_add() {
    bool passed = true;
    SortedList *list = new_sorted_list();

    PRINT_DEBUG("Testing adding movie2 to the sorted list\n");
    add_to_sorted_list(list, movie2);
    PRINT_DEBUG("Sorted List is %s\n", sorted_list_to_str(list));


    passed &= ASSERT_EQUAL(list->size, 1);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie2), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie2), 0);

    PRINT_DEBUG("Testing adding movie1 to the sorted list\n");

    add_to_sorted_list(list, movie1);

    PRINT_DEBUG("Sorted List is %s\n", sorted_list_to_str(list));

    passed &= ASSERT_EQUAL(list->size, 2);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie2), 0);

    PRINT_DEBUG("Testing adding movie3 to the sorted list\n");
    add_to_sorted_list(list, movie3);
    PRINT_DEBUG("Sorted List is %s\n", sorted_list_to_str(list));


    passed &= ASSERT_EQUAL(list->size, 3);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->head->next->movie, movie2), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie3), 0);

    PRINT_DEBUG("Testing adding movie4 to the sorted list\n");
    add_to_sorted_list(list, movie4);
    PRINT_DEBUG("Sorted List is %s\n", sorted_list_to_str(list));


    passed &= ASSERT_EQUAL(list->size, 4);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie1), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->head->next->movie, movie2), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->head->next->next->movie, movie3), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie4), 0);

    free_sorted_list(list);
    return passed;
}

/**
 * Tests find in sorted list
 * 
 * @return true if the test passed, false if it failed
*/
bool test_sorted_list_find() {
    bool passed = true;
    SortedList *list = new_sorted_list();
    add_to_sorted_list(list, movie1);
    add_to_sorted_list(list, movie2);
    add_to_sorted_list(list, movie3);
    add_to_sorted_list(list, movie4);

    PRINT_DEBUG("Testing finding movie1 in the sorted list\n");
    Movie *found = find_in_sorted_list(list, movie1->title);
    passed &= ASSERT_EQUAL(compare_movies(found, movie1), 0);
    PRINT_DEBUG("Found movie1 = %s\n", found->title)


    PRINT_DEBUG("Testing finding movie2 in the sorted list\n");
    found = find_in_sorted_list(list, movie2->title);
    passed &= ASSERT_EQUAL(compare_movies(found, movie2), 0);
    PRINT_DEBUG("Found movie2 = %s\n", found->title)

    PRINT_DEBUG("Testing finding movie3 in the sorted list\n");
    found = find_in_sorted_list(list, movie3->title);
    passed &= ASSERT_EQUAL(compare_movies(found, movie3), 0);
    PRINT_DEBUG("Found movie3 = %s\n", found->title)

    PRINT_DEBUG("Testing finding movie4 in the sorted list\n");
    found = find_in_sorted_list(list, movie4->title);
    passed &= ASSERT_EQUAL(compare_movies(found, movie4), 0);
    PRINT_DEBUG("Found movie4 = %s\n", found->title)

    PRINT_DEBUG("Testing finding a movie that exist in the sorted list\n");
    found = find_in_sorted_list(list, "A Movie That Does Not Exist");
    passed &= ASSERT_NULL(found);
    PRINT_DEBUG("Found movie = %s\n", found == NULL ? "NULL" : found->title)

    free_sorted_list(list);
    return passed;
}

/**
 * Tests to make sure the sorted list removes movies based on title
 * 
 * @return true if the test passed, false if it failed
*/
bool test_sorted_list_remove() {
    bool passed = true;
    SortedList *list = new_sorted_list();
    add_to_sorted_list(list, movie1);
    add_to_sorted_list(list, movie2);
    add_to_sorted_list(list, movie3);
    add_to_sorted_list(list, movie4);

    PRINT_DEBUG("Testing removing movie1 from the sorted list\n");

    Movie *removed = sorted_list_remove(list, movie1->title);
    passed &= ASSERT_EQUAL(compare_movies(removed, movie1), 0);
    passed &= ASSERT_EQUAL(list->size, 3);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie2), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->head->next->movie, movie3), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie4), 0);

    PRINT_DEBUG("Testing removing movie2 from the sorted list\n");
    
    removed = sorted_list_remove(list, movie2->title);
    passed &= ASSERT_EQUAL(compare_movies(removed, movie2), 0);
    passed &= ASSERT_EQUAL(list->size, 2);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie3), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie4), 0);

    PRINT_DEBUG("Testing removing movie3 from the sorted list\n");

    removed = sorted_list_remove(list, movie3->title);
    passed &= ASSERT_EQUAL(compare_movies(removed, movie3), 0);
    passed &= ASSERT_EQUAL(list->size, 1);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie4), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie4), 0);

    PRINT_DEBUG("Testing at removing an invalid movie from the sorted list\n");

    removed = sorted_list_remove(list, "A Movie That Does Not Exist");
    passed &= ASSERT_NULL(removed);
    passed &= ASSERT_EQUAL(list->size, 1);
    passed &= ASSERT_EQUAL(compare_movies(list->head->movie, movie4), 0);
    passed &= ASSERT_EQUAL(compare_movies(list->tail->movie, movie4), 0);

    

    free_sorted_list(list);
    return passed;
}


/******* END TESTS ************/





/**
 * Adds every testing function to the testing set.
 * Includes the name of the test, the group tag, and the function to run.
*/
TestingSet * init_testing_set() {
    TestingSet * set = new_testing_set();
    add_test(set, "new_linked_list() creates an empty linked list", GROUP_GENERAL, 
        test_new_linked_list);  
    add_test(set, "ll_add_front() adds a node to the front of the list", GROUP_ADD, 
        test_ll_add_front);  
    add_test(set, "ll_add_back() adds a node to the back of the list", GROUP_ADD,
        test_ll_add_back); 
    add_test(set, "ll_insert() adds a node to the list at the given index", GROUP_ADD,
        test_ll_insert); 
    add_test(set, "ll_insert() does nothing if the index is out of bounds", GROUP_ADD,
        test_ll_insert_out_of_bounds); 
    add_test(set, "ll_remove_front() removes a node from the front of the list", GROUP_REMOVE,
        test_ll_remove_front); 
    add_test(set, "ll_remove_back() removes a node from the back of the list", GROUP_REMOVE,
        test_ll_remove_back); 
    add_test(set, "ll_remove() removes a node from the list at the given index", GROUP_REMOVE,
        test_ll_remove); 
    add_test(set, "ll_remove() does nothing if the index is out of bounds", GROUP_REMOVE,
        test_ll_remove_out_of_bounds); 
    add_test(set, "ll_get() gets a node from the list at the given index", GROUP_GET,
        test_ll_get); 
    add_test(set, "ll_get() does nothing if the index is out of bounds", GROUP_GET,
        test_ll_get_out_of_bounds); 
    add_test(set, "ll_is_empty() returns true if the list is empty", GROUP_GENERAL,
        test_ll_is_empty); 
    add_test(set, "ll_to_str() returns a string representation of the list", GROUP_GENERAL,
        test_ll_to_str); 
    add_test(set, "add_to_sorted_list() adds a movie to the sorted list", GROUP_SORTED,
        test_sorted_list_add);
    add_test(set, "find_in_sorted_list() finds a movie in the sorted list", GROUP_SORTED,
        test_sorted_list_find);
    add_test(set, "sorted_list_remove() properly removes movies based on title", GROUP_SORTED,
        test_sorted_list_remove);



        


    return set;
}

/**
 * Runs the tests for the linked list implementation.
 * 
 * @param start_test the test to start running from
 * @param end_test the test to stop running at
*/
int main(const int argc, const char *argv[]) {
    init_movies(); // initialize a few movies to help us out

    TestingSet * set = init_testing_set(); // initialize the testing set
    
    // now proccess args and run the test program
    VERBOSE = check_for_verbose(argc, argv); // check for verbose flag and set the global variable found in testing_util.h
    DEBUG = check_for_debug(argc, argv); // check for debug flag and set the global variable found in testing_util.h

    const char * group_tag = check_for_group_tag(argc, argv); // check for group tag and set the global variable found in testing_util.h
    
    if (group_tag == NULL) {
        int test_start_loc = 1; // the index to start looking for tests at, but may change if -v is there
        int start_test = get_int_arg(argc, argv, 1, 0, &test_start_loc); // get the start test, default to 0
        int end_test = get_int_arg(argc, argv, test_start_loc + 1, set->num_tests-1, &test_start_loc); // get the end test, default to 0
        PRINT_VERBOSE("Running tests %d through %d\n", start_test, end_test);
        run_tests(set, start_test, end_test);
    } else {
        PRINT_VERBOSE("Running tests for group %s\n", group_tag);
        run_tests_group(set, (char *)group_tag);
    }
 



    // this has to be done separately because movies are used across multiple lists
    free_movies();
    free_testing_set(set);
    return 0;
}