#include <stdio.h>
#include "util.h"
#include <mraa.h>

duration_t convert_to_days(double seconds)
{
    duration_t duration;

    duration.msec = (seconds - (unsigned long int)seconds)*1000;
    duration.seconds= (unsigned long int)(seconds) % 60;
    seconds = seconds/60;
    duration.minutes= (unsigned long int)(seconds) % 60;
    seconds = seconds/60;
    duration.hours  = (unsigned long int)(seconds) % 24;
    seconds = seconds/24;
    duration.days   = (unsigned long int)(seconds);    
    return duration;
}

void get_board_info()
{
    char* board_name = mraa_get_platform_name();
    fprintf(stdout, "hello mraa\n Version: %s\n Running on %s\n", mraa_get_version(), board_name);
    mraa_deinit();
    return MRAA_SUCCESS;
}
