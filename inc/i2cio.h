#ifndef _I2CIO_H_
#define _I2CIO_H_

#include <util.h>
#include <stdbool.h>

static unsigned char i2c_gpio_out[8]={0x01,0x02,0x04,0x08, 0x10,0x20,0x40,0x80};

void set_io(unsigned char out);
unsigned char get_io();
void set_gpio(char gpio, bool gpio_state);
void i2c_exec(char **argv, int argc);
#endif

