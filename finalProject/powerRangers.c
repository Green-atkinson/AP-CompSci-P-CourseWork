#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("I'll need a base and a power.\n");
        return 1;
    }
    int base = atoi(argv[1]);
    int power = atoi(argv[2]);
    int product = 1;

    for(int i = 0; i < power; i++)
    {
        product *= base;
    }

    printf("\n");
    printf(". . . %i!\n", product);
    printf("\n");
    printf("Go, go, Power Rangers!\n");

}