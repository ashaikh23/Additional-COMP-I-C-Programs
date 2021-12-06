#include <stdio.h>

int main(int argc, char* argv[])
{
        const int y = 100;
        int x = 42;
        int z = 99;
        int i;
        int *p;
        p = &x;

        printf("The value of x is %d\n", x);
        printf("The address of x is %p\n", &x);
        printf("The value of p is %p\n", p);
        printf("The dereferenced value of p is %d\n", *p);
        *p = 107;
        printf("The value of x is %d\n", x);
        p[0] = 9001;
        printf("The value of x is %d\n", x);
        for (i = -9 ; i < 10; i++)
        {
            printf("The value of p[%d] = %d\n", i, *(p + i));
        }
        printf("The value of y is %d\n", y);
        p[3] = -7;
        *(p + 3) = -7;
        printf("The value of y is %d\n", y);
    return 0;
}
