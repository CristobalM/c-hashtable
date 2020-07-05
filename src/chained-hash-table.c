/**
 * @file chained-hash-table.c
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

#include <stdlib.h>

#include "chained-hash-table.h"
#include "hash-function.h"


int init_chained_htable(struct chained_hash_table *h, unsigned long container_size){
    h->container = calloc(container_size, sizeof(void *));
    h->container_size = container_size;
    return SUCCESS_ECODE;
}

int free_chained_htable(struct chained_hash_table *h){
    for(size_t i = 0; i < h->container_size; i++){
        void **head = ((void **)h->container) + i;
        if(head == NULL_PTR) continue;
        struct ll_node *curr = *head;
        while(curr != NULL_PTR){
            struct ll_node *next = curr->next;
            free(curr);
            curr = next;
        }
    }

    free(h->container);
    return SUCCESS_ECODE;
}

struct ll_node * get_node_chained_htable(struct chained_hash_table *h, void *key){    
    unsigned long hpos = hash_function(key, h->container_size);
    void **ptr = ((void **)h->container) + hpos;

    struct ll_node *result = *ptr;
    while(result != NULL_PTR && !same_key(key, result->key)){
        result = result->next;
    }

    return result;
}

void * get_value_chained_table(struct chained_hash_table *h, void *key){
    struct ll_node *node = get_node_chained_htable(h, key);
    if(node == NULL_PTR){
        return NULL_PTR;
    }
    return node->value;
}

void * pop_value_chained_table(struct chained_hash_table *h, void *key){
    struct ll_node *node = get_node_chained_htable(h, key);
    void *value = node->value;
    delete_node_chained_table(h, node);
    return value;
}

static inline struct ll_node * create_ll_node(void *key, void *value){
    struct ll_node *node = malloc(sizeof(struct ll_node));
    node->root_node = FALSE;
    node->previous = NULL_PTR;
    node->next = NULL_PTR;
    node->key = key;
    node->value = value;
    return node;
}

int set_value_chained_htable(struct chained_hash_table *h, void *key, void *value, int replace_existing, void **old_value){
    unsigned long hpos = hash_function(key, h->container_size);

    void **ptr = ((void **)h->container) + hpos;


    if(replace_existing){
        struct ll_node *curr = *ptr;
        while(curr != NULL_PTR && !same_key(key, curr->key)){
            curr = curr->next;
        }
        if(curr != NULL_PTR){
            *old_value = curr->value;
            curr->value = value;
            return SUCCESS_ECODE;
        }
    }

    struct ll_node *head = create_ll_node(key, value);
    head->root_node = TRUE;
    head->previous = ptr;

    if(*ptr != NULL_PTR){
        struct ll_node *previous_head = *ptr;
        previous_head->root_node = FALSE;
        previous_head->previous = head;
        head->next = previous_head;
    }

    *ptr = head;

    return SUCCESS_ECODE;
}

int delete_node_chained_table(struct chained_hash_table *h, struct ll_node *node){
    void *previous = node->previous;
    if(node->root_node){
        *((void **)node->previous) = node->next;
    }
    else{
        ((struct ll_node *)node->previous)->next = node->next;
    }
    
    if(node->next != NULL_PTR){
        struct ll_node *next_node = node->next;
        next_node->previous = previous;
        if(node->root_node){
            next_node->root_node = TRUE;
        }
    }
    free(node);
    return SUCCESS_ECODE;
}

int delete_key_chained_table(struct chained_hash_table *h, void *key){
    unsigned long hpos = hash_function(key, h->container_size);
    void **ptr = ((void **)h->container) + hpos;
    struct ll_node *curr = *ptr;
    while(curr != NULL_PTR && !same_key(key, curr->key)){
        curr = curr->next;
    }

    if(curr != NULL_PTR){
        delete_node_chained_table(h, curr);
    }

    return SUCCESS_ECODE;
}