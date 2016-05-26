#include <stdio.h>
#include "../main/gonc_vector.h"

int main()
{
    struct gonc_vector* vector = gonc_vector_create(5, sizeof(int));
    int p = 3;
    gonc_vector_set(vector, 3, &p);
    p = 0;
    gonc_vector_get(vector, 3, &p);
    printf("%d\n", p);
    gonc_vector_destroy(vector);

}
