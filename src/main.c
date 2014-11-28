#include <stdio.h>

#include "util.h"
#include "mraa.h"

int main(int argc, char **argv)
{
    printf("HWLOC Test Application\n");
    if(argc <=1) {
        get_board_info();
    } else {
        printf("Parameter: %s\n", *(argv+1));
        if (strncasecmp("mem", *(argv+1), sizeof("mem")) == 0) {
        } else if (strncasecmp("net", *(argv+1), sizeof("net")) == 0) {
        } else if (strncasecmp("help", *(argv+1), sizeof("help")) == 0) {
            printf("SIGAR Test Application\n");
            printf("cpu mem sys disk net proc swap base\n");
        } else {
            printf("Invalid parameter passed\n");
        }
    }
    return 0;
}
