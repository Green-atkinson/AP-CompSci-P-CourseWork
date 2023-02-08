#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int days = get_float("Days in a month: ");
    while (days < 28 || days > 31)
    {
        days = get_float("Days in a month: ");
    }

    int penny = get_float("Pennies on first day: ");
    while (penny < 1)
    {
        penny = get_float("Pennies on first day: ");
    }

    int penny1 = penny;
    long long total = 0;

    total = (penny1 * (1 - pow(2, days)) / -1);

    printf("$%.2f\n", ((double)(total / 100) + (double)(total % 100 * .01)));
}