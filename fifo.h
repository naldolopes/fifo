#ifndef __FIFO_H__
#define __FIFO_H__

#define FIFO_SIZE 1024
#define FIFO_FAIL 0
#define FIFO_SUCCESS 1

#include <stdint.h>


typedef char fifo_data_t;

void fifo_init(void);
uint8_t fifo_put(fifo_data_t data);
uint8_t fifo_get(fifo_data_t *data);
uint32_t fifo_get_size(void);


#endif // __FIFO_H__
