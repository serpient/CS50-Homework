// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Returns true if word is in dictionary else false
// check is case-insensitive. so convert word to lowercase before checking spelling
bool check(const char *word)
{
    // TODO
    return false;
}

// Loads dictionary into memory, returning true if successful else false
// loads dictionary into a data structure we have created
// look into hashing
bool load(const char *dictionary)
{
    // TODO
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
// free any memory that was allocated in load. 
// use valgrind to watch for leaks
bool unload(void)
{
    // TODO
    return false;
}
