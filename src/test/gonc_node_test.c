#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>
#include <cmocka.h>
#include "../main/gonc_node.h"

void test()
{
    struct gonc_node* node = malloc(sizeof(struct gonc_node));
    assert_ptr_not_equal(node, NULL);

    node->data = malloc(sizeof(int));
    assert_ptr_not_equal(node->data, NULL);
    *(int*)(node->data) = 100;
    assert_int_equal(*(int*)(node->data), 100);

    node->next = malloc(sizeof(struct gonc_node));
    assert_ptr_not_equal(node->next, NULL);

    node->next->data = malloc(sizeof(struct gonc_node));
    assert_ptr_not_equal(node->next->data, NULL);
    *(int*)(node->next->data) = 200;
    assert_int_equal(*(int*)(node->next->data), 200);

    free(node->next->data);
    free(node->next);
    free(node->data);
    free(node);
}

int main(int argc, char** argv)
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
