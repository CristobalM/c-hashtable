#include <string.h>
#include <math.h>

#include "hash-function.h"

/**
 * @brief Concrete implementation for strings keys of a hash function
 * 
 */

unsigned long hash_function(void *key, unsigned long mod){
    // Assumes a string ended with a null char
    char *key_str = (char *) key;
    size_t key_size = strlen(key_str);

    unsigned long result = 0;
    for(size_t i = 0; i < key_size; i++){
        result += (key_str[i] * (unsigned long)pow(63, i)) % mod;
    }

    return result % mod;
}

int same_key(void *key1, void *key2){
    char *key_str_1 = (char *) key1;
    char *key_str_2 = (char *) key2;
    return strcmp(key_str_1, key_str_2) == 0;
}
