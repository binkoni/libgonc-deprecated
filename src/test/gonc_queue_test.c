#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../main/gonc_queue.h"
#include "../main/gonc_entry.h"
#include "../main/gonc_primitive.h"

void test()
{
    struct gonc_queue* queue = gonc_queue_create();
    assert_ptr_not_equal(queue, NULL);

    int* value = malloc(sizeof(int));
    *value = 100;
    assert_int_not_equal(gonc_queue_push(queue, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 200;
    assert_int_not_equal(gonc_queue_push(queue, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 300;
    assert_int_not_equal(gonc_queue_push(queue, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 400;
    assert_int_not_equal(gonc_queue_push(queue, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 500;
    assert_int_not_equal(gonc_queue_push(queue, gonc_primitive_create_entry(value, sizeof(int))), -1);

    struct gonc_entry* entry = gonc_queue_pop(queue);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 100);
    gonc_entry_destroy(entry);

    entry = gonc_queue_pop(queue);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 200);
    gonc_entry_destroy(entry);

    entry = gonc_queue_pop(queue);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 300);
    gonc_entry_destroy(entry);

    entry = gonc_queue_pop(queue);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 400);
    gonc_entry_destroy(entry);

    entry = gonc_queue_pop(queue);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 500);
    gonc_entry_destroy(entry);

    gonc_queue_destroy(queue);
}

int main()
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
