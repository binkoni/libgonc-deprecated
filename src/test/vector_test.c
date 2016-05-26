#include <stdio.h>
#include "../main/gonc_vector.h"

int main()
{
    struct gonc_vector* vector = gonc_vector_create(5, sizeof(int));
    int p;
    p = 100;
    gonc_vector_append(vector, &p);
    p = 200;
    gonc_vector_append(vector, &p);
    p = 300;
    gonc_vector_append(vector, &p);
    p = 400;
    gonc_vector_append(vector, &p);
    p = 500;
    gonc_vector_append(vector, &p);
    p = 600;
    gonc_vector_insert(vector, 2, &p);
    
    printf("%d\n", gonc_vector_get_size(vector));
    printf("%d\n", gonc_vector_get_capacity(vector));
    for(int i = 0; i < gonc_vector_get_size(vector); i++)
    {
        int x;
        gonc_vector_get(vector, i, &x);
        printf("%d\n", x);
    }
    printf("\n");
    gonc_vector_remove(vector, 2, &p);
    printf("p: %d\n", p);
    for(int i = 0; i < gonc_vector_get_size(vector); i++)
    {
        int x;
        gonc_vector_get(vector, i, &x);
        printf("%d\n", x);
    }
    gonc_vector_destroy(vector);

}
