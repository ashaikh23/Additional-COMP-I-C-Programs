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
    if (pDate != NULL)
    {
        pDate->month = 1;
        pDate->day = 1;
        pDate->year = 1970;
    }
    return (DATE)pDate;
}

void date_output(DATE hDate)
{
    Date* pDate = (Date*)hDate; //cast to the known type
    printf("%d/%d/%d", (*pDate).month, pDate->day, pDate[0].year);
}

int date_get_month(DATE hDate)
{
    Date* pDate = (Date*)hDate;
    return pDate->month;
}
int date_get_day(DATE hDate)
{
    Date* pDate = (Date*)hDate;
    return pDate->day;
}
int date_get_year(DATE hDate)
{
    Date* pDate = (Date*)hDate;
    return pDate->year;
}
char* date_get_month_name(DATE hDate)
{
    Date* pDate = (Date*)hDate;
    switch (pDate->month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 12:
        return "December";
    default:
        return "Invalid month name";
    }
    return NULL; //stub
}

Status date_set_month(DATE hDate, int month)
{
    Date* pDate = (Date*)hDate;
    if (month < 1 || month > 12)
    {
        return FAILURE;
    }
    pDate->month = month;
    return SUCCESS;
}

Status date_set_day(DATE hDate, int day)
{
    Date* pDate = (Date*)hDate;
    if (day < 1 || day > 31)
    {
        return FAILURE;
    }
    pDate->day = day;
    return SUCCESS;
}

Status date_set_year(DATE hDate, int year)
{
    Date* pDate = (Date*)hDate;
    if (year < 1)
    {
        return FAILURE;
    }
    pDate->year = year;
    return SUCCESS;
}

void date_destroy(DATE* phDate)
{
    Date* pDate = (Date*)*phDate;

    //clean up anything that the object is responsible for...in this case nothing.
    free(pDate);
    *phDate = NULL;
}
