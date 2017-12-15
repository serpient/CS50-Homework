// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open input file

    // create initial array of length 26 + 1 (for null); will be an array of pointers, with its array index as its char identifier
    // allocate memory for size of this array;
    char* arrayOfPointers = malloc(27 * sizeof(void*));

    // while not-end-of-file
        // loop through dictionary word
            // for each character, find the index within arrayOfPointers
            // for arrayOfPointers[i character - 97 (ascii number for a)]
                // if input character is null (end of dictionary word)
                    // go through the linked list until it reaches the last pointer
                    // point it to null within a copy of a 27 length array (so make it index 27)
                    // return to beginning of function and read next word

                // if at that index, there is a pointer that !== NULL
                    // go to next dictionary word character
                    // go to next pointer and see if it equals dictionary word character

                // if pointer == null
                    // make new iteration of arrayOfPointers and point the parent pointer to new array
                    // then go and check on next dictionary word character

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
