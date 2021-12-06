#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct date //known type
{
    int month;
    int day;
    int year;
};

typedef struct date Date;

DATE date_init_default(void)
{
    Date* pDate;
    pDate = (Date*)malloc(sizeof(Date));
    if (pDate == NULL)
    {
        return NULL;
    }
    else
    {
        pDate->month = 1;
        pDate->day = 1;
        pDate->year = 1970;
    }
    return (DATE)pDate;
}

void date_output(DATE hDate)
{
    Date* pDate = (Date*)hDate;
    printf("%d/%d/%d", (*pDate).month, pDate->day, pDate[0].year);
}
