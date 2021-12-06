#include <stdio.h>

void print_array(int numbers[], int size);
int find_smallest(int numbers[], int size);
int sum_array(int numbers[], int size);
int out_of_order(int numbers[], int size);
void print_string(char word[]);

int main(int argc, char* argv[])
{
    int numbers[] = { 1,2,-56,4,5,6 };
    int number_of_elements = sizeof(numbers) / sizeof(numbers[0]);
    char word[] = "Happy";
    word[5] = '*';


    /*print_array(numbers, number_of_elements);
    printf("The index of the smallest element is %d\n", 
        find_smallest(numbers, number_of_elements));
    printf("The value of the smallest element is %d\n", 
        numbers[find_smallest(numbers, number_of_elements)]);
    printf("The sum of all the values is %d\n",
        sum_array(numbers, number_of_elements));
    printf("The first index where we detect it is out of order is %d\n",
        out_of_order(numbers, number_of_elements));*/
        
    print_string(word);
    printf("%s\n", word);
    return 0;
}

void print_array(int numbers[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\n", numbers[i]);
    }
}

int find_smallest(int numbers[], int size)
{
    int index_of_smallest = 0;
    int i;
    for (i = 1; i < size; i++)
    {
        if (numbers[i] < numbers[index_of_smallest])
        {
            index_of_smallest = i;
        }
    }
    return index_of_smallest;
}

int sum_array(int numbers[], int size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += numbers[i];
    }
    return sum;
}

int out_of_order(int numbers[], int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
        {
            return i;
        }
    }
    return -1;
}

void print_string(char word[])
{
    int i = 0;
    while (word[i] != '\0')
    {
        printf("%c", word[i]);
        i++;
    }
}
