#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

double square_root(double number);
Boolean user_wishes_to_continue(void);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    do
    {
        printf("Happy Birthday!\n");
    } while (user_wishes_to_continue());

    return 0;
}

double square_root(double number)
{
    double guess = 600000;
    double companion_number;
    int i;

    do
    {
        companion_number = number / guess;
        guess = (guess + companion_number) / 2;
    } while (fabs(guess - companion_number) > .0000000001);



    return guess;
}

Boolean user_wishes_to_continue(void)
{
    char answer;
    printf("Do you wish to continue? (y/n) : ");
    scanf(" %c", &answer);
    clear_keyboard_buffer();
    while (answer != 'y' && answer != 'Y' &&
        answer != 'n' && answer != 'N')
    {
        printf("I'm sorry but I do not understand.\n");
        printf("Do you wish to continue? (y/n) : ");
        scanf(" %c", &answer);
        clear_keyboard_buffer();
    }

    return answer == 'y' || answer == 'Y';
}

void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        scanf("%c", &c);
    }
}
