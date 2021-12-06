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

    date_set_year(hToday, 2021);
    date_set_month(hToday, 12);
    date_set_day(hToday, 31);
    date_set_month(hToday, 2);
    
    
    if (date_get_year(hToday) == 1970)
    {
        printf("The year of today is 1970!\n");
    }
    printf("Today's month name is %s\n", date_get_month_name(hToday));



    date_output(hToday);
    printf("\n");
    date_output(hTomorrow);
    printf("\n");


    //START HERE 
    date_destroy(&hToday); 
    date_destroy(&hTomorrow);

    return 0;
}
