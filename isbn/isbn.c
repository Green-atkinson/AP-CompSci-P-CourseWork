#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //gets the ISBN number from the user
    long long ISBN = get_long("ISBN: ");
    long long copy_of_ISBN = ISBN;

    //declare value to add up calculation of ISBN
    long long calculate = 0;

    //use for loop, go from 9-1,  to calculate ISBN
    for (int i = 10; i >= 0; i--)
    {
        //mode isbn, multiply by I, and add to calculate
        calculate += (copy_of_ISBN % 10) * i;

        //take off last digit of ISBN
        copy_of_ISBN /= 10;
    }

    //divide declared value by 11, check if that is equal to last # of ISBN
    if (calculate % 11 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}