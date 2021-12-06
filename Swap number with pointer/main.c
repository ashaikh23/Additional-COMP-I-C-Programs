#include <stdio.h>

void my_swap(int* pNum1, int* pNum2);

int main(int argc, char* argv[])
{
    int i;
    printf("argc stands for argument count and is currently %d\n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("The value of argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}

void my_swap(int* pNum1, int* pNum2)
{
    int temp;
    temp = pNum1[0];
    pNum1[0] = *pNum2;
    *pNum2 = temp;
}
