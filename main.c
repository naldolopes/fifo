#include <stdio.h>
#include "fifo.h"

int main(void)
{
    fifo_init();

    fifo_put(1);
    fifo_put(2);
    fifo_put(3);


    uint32_t size = fifo_get_size();

    printf("Size: %d\n", size);

    fifo_data_t data;
    fifo_get(&data);

    printf("Data: %d\n", data);

    size = fifo_get_size();

    printf("Size: %d\n", size);

    return 0;
}