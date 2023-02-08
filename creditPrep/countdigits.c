#include <cs50.h>
#include <stdio.h>

int count_digits(long long num);

int main(void)
{
    printf("count_digits(378282246310005) should be 15: %i\n", count_digits(378282246310005));
    printf("count_digits(4567312) should be 7: %i\n", count_digits(4567312));
}

//Precondition:  num is a positive long long
//Postcondition: returns the number of digits
//               in num.
int count_digits(long long num)
{
    //TODO
}