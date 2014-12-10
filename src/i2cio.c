#include <util.h>
#include "i2cio.h"
#include <mraa.h>
#include <stdbool.h>

mraa_i2c_context i2c;
#define I2C_IO_EXPANDER_ADDR 0x20
#define I2C_PORT 1
void set_io(unsigned char out)
{
  int ret = 0;
  i2c = mraa_i2c_init(I2C_PORT);
  mraa_i2c_address(i2c, I2C_IO_EXPANDER_ADDR);

  if(MRAA_SUCCESS != (ret=mraa_i2c_write_byte(i2c,out)))
  {
    printf("i2c set error: %x\n",ret);
  }

}

unsigned char get_io()
{
  i2c = mraa_i2c_init(I2C_PORT);
  mraa_i2c_address(i2c,I2C_IO_EXPANDER_ADDR);
  return mraa_i2c_read_byte(i2c);

}

void set_gpio(char gpio, bool gpio_state)
{
  int ret = 0;
  unsigned char cur_pinout;
  i2c = mraa_i2c_init(I2C_PORT);
  mraa_i2c_address(i2c,I2C_IO_EXPANDER_ADDR);
  cur_pinout = get_io();

  if(gpio_state)
  {
    cur_pinout = cur_pinout | i2c_gpio_out[(unsigned int)gpio];
  } else {
    cur_pinout = cur_pinout & (i2c_gpio_out[(unsigned int)gpio]^0xff);
  }
  
  if(MRAA_SUCCESS != (ret=mraa_i2c_write_byte(i2c,cur_pinout)))
  {
    printf("i2c set error: %x\n",ret);
  }

}
void i2c_exec(char **argv, int argc)
{
  int input_data;
  bool gpio_state;

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
    printf("io read : 0x%x\n", get_io());
    
  } else if (!strcmp(*argv, "gw")) {
    printf("GPIO Bit manipulation");
    input_data = strtol(*(argv+1),NULL,0);
    if(!(input_data > 0 && input_data <=7)) {
      printf("Invalid GPIO bit location\n");
    } else {
      if(strtol(*(argv+2),NULL,0))
        gpio_state = true;
      else
        gpio_state = false;
      set_gpio(input_data, gpio_state);
    }
  } else if (!strcmp(*argv, "help")) {
    printf("I2C IO Expander Pin manipulations\n");
    printf("bin/prog i2cio <r|w|gw|help> [NA|value to be written|GPIO to be updated] \n");
    printf("                             [NA|NA|Value to be set for the gpio]\n");
  }else {
    printf("Unknown command\n");
  }
}
