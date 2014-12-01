#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <sys/time.h>
#include <string.h>
typedef struct {
    unsigned long int days;
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    unsigned int msec;
} duration_t;

duration_t convert_to_days(double seconds);
int get_board_info();
#endif
