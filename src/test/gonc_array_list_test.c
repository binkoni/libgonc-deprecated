#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../main/gonc_array_list.h"
#include "../main/gonc_entry.h"
#include "../main/gonc_primitive.h"

void general_test()
{
    struct gonc_array_list* array_list = gonc_array_list_create(5);
    assert_ptr_not_equal(array_list, NULL);
    assert_int_equal(gonc_array_list_get_capacity(array_list), 5);

    int* value;
    value = malloc(sizeof(int));
    *value = 100;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 200;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 300;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 400;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 500;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 600;
    assert_int_not_equal(gonc_array_list_insert(array_list, 2, gonc_primitive_create_entry(value, sizeof(int))), -1);

    assert_int_equal(gonc_array_list_get_size(array_list), 6);
    assert_int_equal(gonc_array_list_get_capacity(array_list), 10);


    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 0)->data)->value, 100);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 1)->data)->value, 200);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 2)->data)->value, 600);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 3)->data)->value, 300);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 4)->data)->value, 400);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 5)->data)->value, 500);
    struct gonc_entry* entry = gonc_array_list_remove(array_list, 2);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 600);
    gonc_entry_destroy(entry);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 0)->data)->value, 100);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 1)->data)->value, 200);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 2)->data)->value, 300);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 3)->data)->value, 400);
    assert_int_equal(*(int*)((struct gonc_primitive*)gonc_array_list_get(array_list, 4)->data)->value, 500);


    gonc_array_list_destroy(array_list);
}

void prepend_and_remove_test()
{
    struct gonc_array_list* array_list = gonc_array_list_create(5);
    assert_ptr_not_equal(array_list, NULL);

    int* value;
    value = malloc(sizeof(int));
    *value = 100;
    assert_int_not_equal(gonc_array_list_prepend(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 200;
    assert_int_not_equal(gonc_array_list_prepend(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 300;
    assert_int_not_equal(gonc_array_list_prepend(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 400;
    assert_int_not_equal(gonc_array_list_prepend(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 500;
    assert_int_not_equal(gonc_array_list_prepend(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    struct gonc_entry* entry = gonc_array_list_remove(array_list, 0);   
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 500);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);    
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 400);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);    
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 300);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 200);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 100);
    gonc_entry_destroy(entry);

    gonc_array_list_destroy(array_list);
}

void append_and_remove_test()
{
    struct gonc_array_list* array_list = gonc_array_list_create(5);
    assert_ptr_not_equal(array_list, NULL);

    int* value;
    value = malloc(sizeof(int));
    *value = 100;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 200;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 300;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 400;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    value = malloc(sizeof(int));
    *value = 500;
    assert_int_not_equal(gonc_array_list_append(array_list, gonc_primitive_create_entry(value, sizeof(int))), -1);

    struct gonc_entry* entry = gonc_array_list_remove(array_list, 0);   
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 100);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);    
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 200);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);    
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 300);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 400);
    gonc_entry_destroy(entry);

    entry = gonc_array_list_remove(array_list, 0);
    assert_ptr_not_equal(entry, NULL);
    assert_int_equal(*(int*)((struct gonc_primitive*)entry->data)->value, 500);
    gonc_entry_destroy(entry);

    gonc_array_list_destroy(array_list);
}

int main()
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(general_test),
        cmocka_unit_test(prepend_and_remove_test),
        cmocka_unit_test(append_and_remove_test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
