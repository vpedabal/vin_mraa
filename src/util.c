#include <mraa.h>
#include <stdio.h>
#include <stdlib.h>
#include <util.h>

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

int get_board_info()
{
    char* board_name = mraa_get_platform_name();
    char *output1;
    char *output2;
    int i,col=0;
    asprintf(&output1, "Version: %s|\n",mraa_get_version());
    asprintf(&output2, "Running on %s|\n", board_name);
    col = strlen(output1)-1;
    if(col < strlen(output2))
      col = strlen(output2);
    for(i=0;i<col;i++)
     fprintf(stdout,"-");
    fprintf(stdout,"|\n");
    fprintf(stdout,output1,"|\n");
    fprintf(stdout,output2,"|\n");
    for(i=0;i<col;i++)
      fprintf(stdout,"-");
    fprintf(stdout,"|\n");
    mraa_deinit();
    return MRAA_SUCCESS;
}
