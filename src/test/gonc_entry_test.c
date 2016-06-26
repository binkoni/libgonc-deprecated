#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>
#include <cmocka.h>
#include "../main/gonc_entry.h"
#include "../main/gonc_primitive.h"

void test()
{
    int* value = malloc(sizeof(int));
    *value = 100;

    struct gonc_entry* entry = gonc_primitive_create_entry(value, sizeof(int));

    assert_ptr_not_equal(entry, NULL);

    assert_ptr_not_equal(entry->data, NULL);

    assert_int_equal(*(int*)(((struct gonc_primitive*)entry->data)->value), 100);

    gonc_entry_destroy(entry);
}

int main(int argc, char** argv)
{
    struct CMUnitTest tests[] = {
        cmocka_unit_test(test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
