#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../main/gonc_stack.h"

void test()
{
    struct gonc_stack* stack = gonc_stack_create();
    assert_ptr_not_equal(stack, NULL);

    int p1;
    p1 = 100;
    assert_int_not_equal(gonc_stack_push(stack, &p1, sizeof(int)), -1);
    p1 = 200;
    assert_int_not_equal(gonc_stack_push(stack, &p1, sizeof(int)), -1);
    p1 = 300;
    assert_int_not_equal(gonc_stack_push(stack, &p1, sizeof(int)), -1);
    p1 = 400;
    assert_int_not_equal(gonc_stack_push(stack, &p1, sizeof(int)), -1);
    p1 = 500;
    assert_int_not_equal(gonc_stack_push(stack, &p1, sizeof(int)), -1);

    int p2;
    assert_int_not_equal(gonc_stack_pop(stack, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);
    assert_int_not_equal(gonc_stack_pop(stack, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    gonc_stack_peek(stack, &p2, sizeof(int));
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_stack_pop(stack, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_stack_pop(stack, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    assert_int_not_equal(gonc_stack_pop(stack, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);
    assert_int_equal(gonc_stack_pop(stack, &p2, sizeof(int)), -1);

    gonc_stack_destroy(stack);
}

int main()
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
