#ifndef _SETPWM_H_
#define _SETPWM_H_

#include "util.h"
#define Tmax
#define Tmin
#define Tperiod

void set_pwm_channel(int pwm_channel, unsigned long duty_cycle, unsigned long period);
#endif

