#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../main/gonc_linked_list.h"

void general_test()
{
    struct gonc_linked_list* linked_list = gonc_linked_list_create();
    assert_ptr_not_equal(linked_list, NULL);
    int p1 = 100;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);

    p1 = 200;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 300;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 400;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 500;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 600;
    assert_int_not_equal(gonc_linked_list_insert(linked_list, 2, &p1, sizeof(int)), -1);

    assert_int_equal(gonc_linked_list_get_size(linked_list), 6);

    int p2;
    assert_int_not_equal(gonc_linked_list_get(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 1, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 2, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 600);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 3, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 4, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 5, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);

    assert_int_not_equal(gonc_linked_list_remove(linked_list, 2, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 600);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 1, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 2, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 3, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    assert_int_not_equal(gonc_linked_list_get(linked_list, 4, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);

    gonc_linked_list_destroy(linked_list);

}

void prepend_and_remove_test()
{
    struct gonc_linked_list* linked_list = gonc_linked_list_create();
    assert_ptr_not_equal(linked_list, NULL);
    int p1 = 100;
    assert_int_not_equal(gonc_linked_list_prepend(linked_list, &p1, sizeof(int)), -1);
    p1 = 200;
    assert_int_not_equal(gonc_linked_list_prepend(linked_list, &p1, sizeof(int)), -1);
    p1 = 300;
    assert_int_not_equal(gonc_linked_list_prepend(linked_list, &p1, sizeof(int)), -1);
    p1 = 400;
    assert_int_not_equal(gonc_linked_list_prepend(linked_list, &p1, sizeof(int)), -1);
    p1 = 500;
    assert_int_not_equal(gonc_linked_list_prepend(linked_list, &p1, sizeof(int)), -1);
    int p2;
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);

    gonc_linked_list_destroy(linked_list);
}

void append_and_remove_test()
{
    struct gonc_linked_list* linked_list = gonc_linked_list_create();
    assert_ptr_not_equal(linked_list, NULL);
    int p1 = 100;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 200;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 300;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 400;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    p1 = 500;
    assert_int_not_equal(gonc_linked_list_append(linked_list, &p1, sizeof(int)), -1);
    int p2;
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 4, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 3, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 2, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 1, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    assert_int_not_equal(gonc_linked_list_remove(linked_list, 0, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);

    gonc_linked_list_destroy(linked_list);
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
