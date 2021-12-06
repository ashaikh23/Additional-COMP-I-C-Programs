#include <stdio.h>
#include <stdlib.h>
#include "date.h"



int main(int argc, char* argv[])
{
    DATE hToday;
    DATE hTomorrow;

    hToday = date_init_default();
    if (hToday == NULL)
    {
        printf("Failed to allocate space for hToday object.\n");
        exit(1);
    }
    hTomorrow = date_init_default();
    if (hTomorrow == NULL)
    {
        printf("Failed to allocate space for hTomorrow object.\n");
        exit(1);
    }
    



    date_output(hToday);
    printf("\n");
    date_output(hTomorrow);
    printf("\n");


    //START HERE 


    return 0;
}
