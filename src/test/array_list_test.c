#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../main/gonc_array_list.h"

void test()
{
    struct gonc_array_list* array_list = gonc_array_list_create(5);
    assert_ptr_not_equal(array_list, NULL);
    assert_int_equal(gonc_array_list_get_capacity(array_list), 5);
    int p1 = 100;
    assert_int_not_equal(gonc_array_list_append(array_list, &p1, sizeof(int)), -1);
    p1 = 200;
    assert_int_not_equal(gonc_array_list_append(array_list, &p1, sizeof(int)), -1);
    p1 = 300;
    assert_int_not_equal(gonc_array_list_append(array_list, &p1, sizeof(int)), -1);
    p1 = 400;
    assert_int_not_equal(gonc_array_list_append(array_list, &p1, sizeof(int)), -1);
    p1 = 500;
    assert_int_not_equal(gonc_array_list_append(array_list, &p1, sizeof(int)), -1);
    p1 = 600;
    assert_int_not_equal(gonc_array_list_insert(array_list, 2, &p1, sizeof(int)), -1);

    assert_int_equal(gonc_array_list_get_size(array_list), 6);
    assert_int_equal(gonc_array_list_get_capacity(array_list), 10);

    int p2;
    assert_int_not_equal(gonc_array_list_get(array_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);
    assert_int_not_equal(gonc_array_list_get(array_list, 1, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    assert_int_not_equal(gonc_array_list_get(array_list, 2, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 600);
    assert_int_not_equal(gonc_array_list_get(array_list, 3, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_array_list_get(array_list, 4, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    assert_int_not_equal(gonc_array_list_get(array_list, 5, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);

    assert_int_not_equal(gonc_array_list_remove(array_list, 2, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 600);
    assert_int_not_equal(gonc_array_list_get(array_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);
    assert_int_not_equal(gonc_array_list_get(array_list, 1, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    assert_int_not_equal(gonc_array_list_get(array_list, 2, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_array_list_get(array_list, 3, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    assert_int_not_equal(gonc_array_list_get(array_list, 4, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);

    gonc_array_list_destroy(array_list);
}

int main()
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
