#include "fifo.h"

fifo_data_t static fifo[FIFO_SIZE];

volatile uint32_t put_itr;
volatile uint32_t get_itr;

void fifo_init(void)
{
    put_itr = 0;
    get_itr = 0;
}   


uint8_t fifo_put(fifo_data_t data)
{
    if ((put_itr - get_itr) & ~(FIFO_SIZE - 1))
    {
        return FIFO_FAIL;
    }

    fifo[put_itr & (FIFO_SIZE - 1)] = data;

    put_itr++;

    return FIFO_SUCCESS;
}

uint8_t fifo_get(fifo_data_t *data)
{
    if (put_itr == get_itr)
    {
        return FIFO_FAIL;
    }

    *data = fifo[get_itr & (FIFO_SIZE - 1)];

    get_itr++;

    return FIFO_SUCCESS;
}

uint32_t fifo_get_size(void)
{
    return put_itr - get_itr;
}