#ifndef _I2CIO_H_
#define _I2CIO_H_

#include <util.h>

void set_io(unsigned char out);
void i2c_exec(char **argv, int argc);
#endif

