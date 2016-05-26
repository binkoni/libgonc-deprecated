#include <stdio.h>
#include "../main/gonc_array_list.h"

int main()
{
    struct gonc_array_list* array_list = gonc_array_list_create(5, sizeof(int));
    int p;
    p = 100;
    gonc_array_list_append(array_list, &p);
    p = 200;
    gonc_array_list_append(array_list, &p);
    p = 300;
    gonc_array_list_append(array_list, &p);
    p = 400;
    gonc_array_list_append(array_list, &p);
    p = 500;
    gonc_array_list_append(array_list, &p);
    p = 600;
    gonc_array_list_insert(array_list, 2, &p);
    
    printf("%d\n", gonc_array_list_get_size(array_list));
    printf("%d\n", gonc_array_list_get_capacity(array_list));
    for(int i = 0; i < gonc_array_list_get_size(array_list); i++)
    {
        int x;
        gonc_array_list_get(array_list, i, &x);
        printf("%d\n", x);
    }
    printf("\n");
    gonc_array_list_remove(array_list, 2, &p);
    printf("p: %d\n", p);
    for(int i = 0; i < gonc_array_list_get_size(array_list); i++)
    {
        int x;
        gonc_array_list_get(array_list, i, &x);
        printf("%d\n", x);
    }
    gonc_array_list_destroy(array_list);

}
