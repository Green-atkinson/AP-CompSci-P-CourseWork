#include <stdio.h>
#include <cs50.h>

int digit_sum(int num);

//Sidney Stewart
_Bool luhn(long long num)
{
    long long numcopy = num;
    int accumulation = 0;
    while(numcopy > 0)
    {
        numcopy /= 10;
        accumulation += digit_sum(numcopy % 10 * 2);
        numcopy /= 10;
    }

    int accumulation2 = 0;
    long long numcopy2 = num;
    while(numcopy2 > 0)
    {
        accumulation2 += numcopy2 % 10;
        numcopy2 /= 10;
        numcopy2 /= 10;
    }

    long long totalaccumulation = accumulation + accumulation2;
    if(totalaccumulation % 10 == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}

//Sidney Stewart
int digit_sum(int num)
{
    return num / 10 + num % 10;
}

//John Atkison
int first_two_digits(long long num)
{
    //go through the first two digits
    while (num > 99)
    {
        num /= 10;
    }

    //return a two digit number
    return num;
}

//Josh Siegel
int count_digits(long long num)
{
    long long count_digits = 0;
    if (num == 0)
    {
        count_digits += 1;
    }
    while (num > 0)
    {
        count_digits++;
        num /= 10;
    }
    return count_digits;
}