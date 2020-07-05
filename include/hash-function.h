#ifndef CHAINED_HASH_FUNCTION_H
#define CHAINED_HASH_FUNCTION_H

/**
 * @brief Abstract hash function signature
 * 
 * Enables customizing the function by defining it in other source file
 * 
 * @param key 
 * @return unsigned long 
 */
unsigned long hash_function(void *key, unsigned long mod);
int same_key(void *key1, void *key2);

#endif /* CHAINED_HASH_FUNCTION_H */