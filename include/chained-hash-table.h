#ifndef CHAINED_HASH_TABLE_H
#define CHAINED_HASH_TABLE_H

#include "definitions.h"

struct chained_hash_table{
    void *container;
    unsigned long container_size;
    unsigned long element_size;
};

struct ll_node{
    int root_node:1;
    void *previous, *next;
    void *key;
    void *value;
};

int init_chained_htable(struct chained_hash_table *h, unsigned long container_size);
int free_chained_htable(struct chained_hash_table *h);

struct ll_node * get_node_chained_htable(struct chained_hash_table *h, void *key);
void * get_value_chained_table(struct chained_hash_table *h, void *key);
void * pop_value_chained_table(struct chained_hash_table *h, void *key);
int set_value_chained_htable(struct chained_hash_table *h, void *key, void *value, int replace_existing, void **old_value);
int delete_node_chained_table(struct chained_hash_table *h, struct ll_node *node);
int delete_key_chained_table(struct chained_hash_table *h, void *key);

#endif /* CHAINED_HASH_TABLE_H */