#include <stdio.h>

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

enum choice { FAHRENHEIT_TO_CELSIUS, CELSIUS_TO_FAHRENHEIT, QUIT };
typedef enum choice Choice;

Boolean user_wishes_to_do_a_temperature_conversion(void);
Boolean user_wishes_to_continue(void);
void clear_keyboard_buffer(void);

Choice get_choice(void);

void do_a_conversion_from_fahrenheit_to_celsius(void);
void do_a_conversion_from_celsius_to_fahrenheit(void);


double get_temperature(void);
double convert_f_to_c(double degrees_fahrenheit);
void display_f_to_c(double degrees_fahrenheit, double degrees_celsius);

double convert_c_to_f(double degrees_celsius);
void display_c_to_f(double degrees_celsius, double degrees_fahrenheit);

int main(int argc, char* argv[])
{
    while (user_wishes_to_do_a_temperature_conversion());

	
	return 0;
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

Boolean user_wishes_to_do_a_temperature_conversion(void)
{
    Choice choice;

    choice = get_choice();

    switch (choice)
    {
    case FAHRENHEIT_TO_CELSIUS:
        do_a_conversion_from_fahrenheit_to_celsius();
        break;
    case CELSIUS_TO_FAHRENHEIT:
        do_a_conversion_from_celsius_to_fahrenheit();
        break;
    }

    return choice != QUIT;
}

Choice get_choice(void)
{
    char answer;

    do
    {       
        printf("Please select from the following menu options:\n");
        printf("1) Convert from Fahrenheit to Celsius.\n");
        printf("2) Convert from Celsius to Fahrenheit.\n");
        printf("     0) QUIT\n");
        printf("Your choice: ");
        scanf(" %c", &answer);
        clear_keyboard_buffer();
        if (answer != '1' && answer != '2'&& answer != '0')
        {
            printf("I'm sorry but I do not understand.\n");
        }
    } while (answer != '1' && answer != '2' && answer != '0');

    switch (answer)
    {
    case '1':
        return FAHRENHEIT_TO_CELSIUS;
    case '2':
        return CELSIUS_TO_FAHRENHEIT;
    default:
        return QUIT;
    }
}

void do_a_conversion_from_fahrenheit_to_celsius(void)
{
    double degrees_fahrenheit;
    double degrees_celsius;
  
    printf("Please enter a temperature in degrees Fahrenheit.\n");
    degrees_fahrenheit = get_temperature();
  
    degrees_celsius = convert_f_to_c(degrees_fahrenheit);
  
    display_f_to_c(degrees_fahrenheit, degrees_celsius);
}
void do_a_conversion_from_celsius_to_fahrenheit(void)
{
    double degrees_fahrenheit;
    double degrees_celsius;

    printf("Please enter a temperature in degrees Celsius.\n");
    degrees_celsius = get_temperature();

    degrees_fahrenheit = convert_c_to_f(degrees_celsius);

    display_c_to_f(degrees_celsius, degrees_fahrenheit);
}

double get_temperature(void)
{
    double temp;
    int noc;
    printf("Enter temperature: ");
    noc = scanf("%lf", &temp);
    clear_keyboard_buffer();
    while (noc != 1)
    {
        printf("I'm sorry but I do not understand.\n");
        printf("Enter temperature: ");
        noc = scanf("%lf", &temp);
        clear_keyboard_buffer();
    }
    return temp;
}
double convert_f_to_c(double degrees_fahrenheit)
{
    return (degrees_fahrenheit - 32) * 5 / 9.0;
}
void display_f_to_c(double degrees_fahrenheit, double degrees_celsius)
{
    printf("\n%.1f degrees Fahrenheit converts to\n", degrees_fahrenheit);
    printf("%.1f degrees Celsius.\n\n", degrees_celsius);
}

double convert_c_to_f(double degrees_celsius)
{
    return (degrees_celsius * 9 / 5.0) + 32;
}

void display_c_to_f(double degrees_celsius, double degrees_fahrenheit)
{
    printf("\n%.1f degrees Celsius converts to\n", degrees_celsius);
    printf("%.1f degrees Fahrenheit.\n\n", degrees_fahrenheit);
}
