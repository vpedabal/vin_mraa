#include <util.h>
#include <setpwm.h>

#define Tperiod (unsigned long)21500000
#define Tmin    (unsigned long)360000
#define Tmax    (unsigned long)1900000

void pwm_exec(char **argv, int argc)
{
  int pwm_ch;
  unsigned long duty_cycle, tperiod;
  printf("Set PWM Exec\n");
  if((argc >= 1) && (*argv != NULL)) {
    if(0 == strcmp(*argv,"help")) {
      printf("PWM Help menu\n");
      printf("./prog pwm <pwm channel> <duty cycle in nSec> [<period in nSec>]\n");
      printf("Default period will be :%lu\n",Tperiod);
      return;
    }
    else if (argc == 3){
      printf("PWM Channel selected : %s\n",*argv);
      printf("PWM Thigh selected   : %s\n",*(argv+1));
      printf("PWM period selected  : %s\n",*(argv+2));
    } else {
      printf("Illegal PWM Parameters passed\n");
      return;
    }
  } else {
    printf("Illegal PWM Parameters passed\n");
    return;
  }

  pwm_ch = strtol(*argv,NULL,10);
  duty_cycle = strtol(*(argv+1),NULL,10);
  tperiod     = Tperiod; /* Ignore user passed period for now */
  set_pwm(pwm_ch,duty_cycle,tperiod);
}

void set_pwm(int pwm_channel, unsigned long duty_cycle, unsigned long period)
{
  printf("Request for setting pwm output\n");
  printf("PWM Channel : %d\n", pwm_channel);
  printf("duty_cycle  : %lu\n", duty_cycle);
  printf("Period      : %lu\n", period);
  return;
}
