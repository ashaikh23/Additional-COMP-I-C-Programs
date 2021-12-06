#include <stdio.h>

int main(int argc, char* argv[])
{
    int x = 42;
    int *p;

    p = &x;

    printf("The value of x is %d\n", x);
    printf("The address of x is %p\n", &x);
    printf("The value of p is %p\n", p);
    printf("Dereference p is %d\n", *p);
    *p = 107;

    printf("The value of x is %d\n", x);


    return 0;
}
