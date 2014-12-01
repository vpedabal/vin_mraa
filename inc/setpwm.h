#ifndef _SETPWM_H_
#define _SETPWM_H_

#include <util.h>

void set_pwm_channel(int pwm_channel, unsigned long duty_cycle, unsigned long period);
void pwm_exec(char **argv, int argc);
#endif

