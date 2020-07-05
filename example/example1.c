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

    set_value_chained_htable(&cht, "FOO BAR 1", &value1, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO", &value2, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO2", &value3, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO3", &value4, FALSE, NULL_PTR);
    set_value_chained_htable(&cht, "BAZ BAR FOO4", &value5, FALSE, NULL_PTR);

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

    free_chained_htable(&cht);
    return 0;
}
