#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>
#include <cmocka.h>
#include "../main/gonc_node.h"
#include "../main/gonc_entry.h"
#include "../main/gonc_primitive.h"

void test()
{
    struct gonc_node* node = malloc(sizeof(struct gonc_node));
    assert_ptr_not_equal(node, NULL);

    int* value = malloc(sizeof(int));
    *value = 100;
    node->entry = gonc_primitive_create_entry(value, sizeof(int));
    
    assert_ptr_not_equal(node->entry, NULL);

    assert_int_equal(*(int*)(((struct gonc_primitive*)node->entry->data)->value), 100);

    node->next = malloc(sizeof(struct gonc_node));
    assert_ptr_not_equal(node->next, NULL);

    value = malloc(sizeof(int));
    *value = 200;
    node->next->entry = gonc_entry_create_entry(value, sizeof(int));
    assert_ptr_not_equal(node->next->entry, NULL);

    assert_int_equal(*(int*)(((struct gonc_primitive*)node->next->entry->data)->value), 200);

    gonc_entry_destroy(node->next->entry);
    free(node->next);
    gonc_entry_destroy(node->entry);
    free(node);
}

int main(int argc, char** argv)
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
