#include <util.h>
#include "i2cio.h"
#include <mraa.h>

mraa_i2c_context i2c;
#define I2C_IO_EXPANDER_ADDR 0x20

void set_io(unsigned char out)
{
  int ret = 0;
  char buf[5];
  i2c = mraa_i2c_init(6);
  mraa_i2c_address(i2c, I2C_IO_EXPANDER_ADDR);

  if(MRAA_SUCCESS != (ret=mraa_i2c_write_byte(i2c,out)))
  {
    printf("i2c set error: %x\n",ret);
  }

}

void i2c_exec(char **argv, int argc)
{
  int input_data;

  printf("argc: %d\n", argc);

  if(!strcmp(*argv,"w"))
  {
    printf("io set command : %s\n", *argv);
    input_data = strtol(*(argv+1),NULL,0);
    if(!(input_data >=0 && input_data <= 255))
    {
      printf("Invalid output data: %d\n",input_data);
    } else {
      set_io(input_data&0xff);
    }
  } else if (!strcmp(*argv, "r")) {
    printf("io get command : %s\n", *argv);
  } else {
    printf("Unknown command\n");
  }
}
