/**
 * @file example1.c
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

#include <stdio.h>

#include <definitions.h>
#include <chained-hash-table.h>


int main(){

    struct chained_hash_table cht;
    init_chained_htable(&cht, 1);

    int value1 = 100;
    int value2 = 10320233;
    int value3 = 1;
    int value4 = 2;
    int value5 = 3;
    int value6 = 4;
    int value7 = 7;

    set_value_chained_htable(&cht, "FOO BAR 1", &value1, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO", &value2, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO2", &value3, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO3", &value4, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO4", &value5, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO5", &value6, FALSE, NULL_PTR);
    int *old_value;
    set_value_chained_htable(&cht, "BAZ BAR FOO5", &value7, TRUE, (void **)&old_value);

    struct ll_node *result1 = get_node_chained_htable(&cht, "FOO BAR 1");
    struct ll_node *result2 = get_node_chained_htable(&cht, "BAZ BAR FOO");

    printf("result 1 value: %d\n", *(int *)result1->value);
    printf("result 2 value: %d\n", *(int *)result2->value);

    delete_node_chained_table(&cht, result1);
    delete_node_chained_table(&cht, result2);

    result1 = get_node_chained_htable(&cht, "FOO BAR 1");
    result2 = get_node_chained_htable(&cht, "BAZ BAR FOO");
    if(result1 == NULL_PTR){
        printf("result 1 is null!\n");
    }
    else{
        printf("Something went wrong, result 1 is not null\n");
    }
    if(result2 == NULL_PTR){
        printf("result 2 is null!\n");
    }
    else{
        printf("Something went wrong, result 2 is not null\n");
    }

    struct ll_node *result5 = get_node_chained_htable(&cht, "BAZ BAR FOO4");
    printf("result5  value: %d\n", *(int *)result5->value);

    int *result3 = pop_value_chained_table(&cht, "BAZ BAR FOO2");
    printf("result3  value: %d\n", *result3);

    int *result4 = pop_value_chained_table(&cht, "BAZ BAR FOO3");
    printf("result4  value: %d\n", *result4);

    if(old_value == &value6){
        printf("old value equals value6!\n");
    }
    else{
        printf("old value not equal to value6!\n");
    }
    struct ll_node *result7 = get_node_chained_htable(&cht, "BAZ BAR FOO5");
    if((int *)result7->value == &value7){
        printf("result7 holds value7!!\n");
    }
    else{
        printf("result7 does not hold value7!!\n");
    }

    free_chained_htable(&cht);
    return 0;
}
