/**
 * @file string-concrete-hash-function.c
 * @author Cristobal Miranda T.
 * @brief github.com/CristobalM/c-hashtable
 * @version 0.1
 * @date 2020-07-05
 * 
 * @copyright Copyright (c) 2020
 
MIT License

Copyright (c) 2020 Cristobal Miranda T.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
