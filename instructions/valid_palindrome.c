#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
    int left = 0; // start of the string
    int right = strlen(s) - 1; // end of the string

    // Loop until the two pointers meet in the middle
    while (left < right) {
        // Skip characters that aren't letters or numbers
        while (left < right && !isalnum(s[left])) {
            left++; // move to next character
        }
        // Skip characters that aren't letters or numbers
        while (left < right && !isalnum(s[right])) {
            right--; // move to previous character
        }

        // Compare lowercase characters
        if (tolower(s[left]) != tolower(s[right])) {
            return false; // characters do not match
        }

        left++; // move forward
        right--; 
    }

    return true; // all characters matched
}
