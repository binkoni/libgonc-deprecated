#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../main/gonc_queue.h"

void test()
{
    struct gonc_queue* queue = gonc_queue_create();
    assert_ptr_not_equal(queue, NULL);

    int p1;
    p1 = 100;
    assert_int_not_equal(gonc_queue_push(queue, &p1, sizeof(int)), -1);
    p1 = 200;
    assert_int_not_equal(gonc_queue_push(queue, &p1, sizeof(int)), -1);
    p1 = 300;
    assert_int_not_equal(gonc_queue_push(queue, &p1, sizeof(int)), -1);
    p1 = 400;
    assert_int_not_equal(gonc_queue_push(queue, &p1, sizeof(int)), -1);
    p1 = 500;
    assert_int_not_equal(gonc_queue_push(queue, &p1, sizeof(int)), -1);

    int p2;
    assert_int_not_equal(gonc_queue_pop(queue, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 100);
    assert_int_not_equal(gonc_queue_pop(queue, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 200);
    gonc_queue_peek(queue, &p2, sizeof(int));
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_queue_pop(queue, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 300);
    assert_int_not_equal(gonc_queue_pop(queue, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 400);
    assert_int_not_equal(gonc_queue_pop(queue, &p2, sizeof(int)), -1);
    assert_int_equal(p2, 500);
    assert_int_equal(gonc_queue_pop(queue, &p2, sizeof(int)), -1);

    gonc_queue_destroy(queue);
}

int main()
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
