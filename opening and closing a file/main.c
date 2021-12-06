#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    char filename[] = "main.c";
    char c;
    int i;
    int noc;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open %s for reading.\n", filename);
        exit(1);
    }
    //work
    noc = fscanf(fp, "%c", &c); //try
    while(noc == 1) //check
    {                
        printf("%c", c);//do
        noc = fscanf(fp, "%c", &c); //try
        //start next time with the story of the two boys on a cliff...
    }


    fclose(fp);



    return 0;
}
