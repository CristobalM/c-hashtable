/**
 * @file chained-hash-table.h
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