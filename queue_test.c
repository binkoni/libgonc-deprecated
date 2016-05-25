#include <stdio.h>
#include "gonc_queue.h"

int main()
{
    struct gonc_queue* queue = gonc_queue_create();
    int p = 280;
    gonc_queue_push_back(queue, (void*)&p, sizeof(int));
    p = 190;
    gonc_queue_push_back(queue, (void*)&p, sizeof(int));

    int output;
    gonc_queue_pop_front(queue, (void*)&output, sizeof(int));
    printf("%d %d\n", output, gonc_queue_get_size(queue));
    gonc_queue_peek_front(queue, (void*)&output, sizeof(int));
    printf("%d %d\n", output, gonc_queue_get_size(queue));
    gonc_queue_pop_front(queue, (void*)&output, sizeof(int));
    printf("%d %d\n", output, gonc_queue_get_size(queue));
    printf("%d\n", gonc_queue_pop_front(queue, (void*)&output, sizeof(int)));
 
    gonc_queue_destroy(queue);


}
