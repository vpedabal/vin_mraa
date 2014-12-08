#include <stdio.h>

#include "util.h"
#include <mraa.h>
#include "setpwm.h"
#include "i2cio.h"

int main(int argc, char **argv)
{
  printf("HWLOC Test Application\n");
  if(argc <=1) {
    printf("Enter valid parameters!\n");
  } else {
    printf("Parameter: %s\n", *(argv+1));
    if (strncasecmp("board", *(argv+1), sizeof("mem")) == 0) {
      get_board_info();
    } else if (strncasecmp("pwm", *(argv+1), sizeof("net")) == 0) {
      pwm_exec(argv+2,argc-2);  
    } else if (strncasecmp("i2cio", *(argv+1), sizeof("net")) == 0) {
      i2c_exec(argv+2,argc-2);
    } else if (strncasecmp("gpio", *(argv+1), sizeof("net")) == 0) {
    } else if (strncasecmp("led", *(argv+1), sizeof("net")) == 0) {
    } else if (strncasecmp("help", *(argv+1), sizeof("help")) == 0) {
      printf("SIGAR Test Application\n");
      printf("board\n");
    } else {
      printf("Invalid parameter passed\n");
    }
  }
  return 0;
}
