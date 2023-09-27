#include <stdio.h>
#include "fifo.h"

int main(void)
{
    fifo_init();
    printf("FIFO Initialized...\n");
    printf("FIFO Size: %d\n", fifo_get_size());


    printf("Adding Items...\n");

    fifo_put(10);
    fifo_put(87);
    fifo_put(3);

    printf("3 Items Added: [10,87,3]\n");

    uint32_t size = fifo_get_size();

    printf("FIFO Size: %d\n", size);

    fifo_data_t data;
    fifo_get(&data);
    printf("Item Removed...\n");

    printf("Data: %d\n", data);

    size = fifo_get_size();

    printf("FIFO Size: %d\n", size);

    return 0;
}