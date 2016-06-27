#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../main/gonc_stack.h"
#include "../main/gonc_entry.h"
#include "../main/gonc_primitive.h"

void test()
{
    struct gonc_stack* stack = gonc_stack_create();
    assert_ptr_not_equal(stack, NULL);

    int* value = malloc(sizeof(int));
    *value = 100;
    assert_int_not_equal(gonc_stack_push(stack, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 200;
    assert_int_not_equal(gonc_stack_push(stack, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 300;
    assert_int_not_equal(gonc_stack_push(stack, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 400;
    assert_int_not_equal(gonc_stack_push(stack, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 500;
    assert_int_not_equal(gonc_stack_push(stack, gonc_primitive_create_entry(value, sizeof(int))), -1);

    struct gonc_entry* entry = gonc_stack_pop(stack);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 500);
    gonc_entry_destroy(entry);
    
    entry = gonc_stack_pop(stack);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 400);
    gonc_entry_destroy(entry);
    
    entry = gonc_stack_pop(stack);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 300);
    gonc_entry_destroy(entry);
    
    entry = gonc_stack_pop(stack);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 200);
    gonc_entry_destroy(entry);
    
    entry = gonc_stack_pop(stack);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 100);
    gonc_entry_destroy(entry);

    gonc_stack_destroy(stack);
}

int main()
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
