#include <stdio.h>
#include <cs50.h>

int digit_sum(int num);
_Bool luhn(long long num);

int main(void)
{
    printf("Luhn 378282246310005 should be 1: %i\n", luhn(378282246310005));
    printf("Luhn 378282246310006 should be 0: %i\n", luhn(378282246310006));
}
//Precondition:  num is a positive long long int
//Postcondition: returns 1 if num passes Luhn's algorithm,
//               otherwise returns 0.
_Bool luhn(long long num)
{
    //TODO
}

int digit_sum(int num)
{
    return num / 10 + num % 10;
}