#include <stdio.h>
#include <cs50.h>

int first_two_digits(long long num);

int main(void)
{
    printf("first_two_digits(378282246310005) should be 37: %i\n", first_two_digits(378282246310005));
    printf("first_two_digits(40002156) should be 40: %i\n", first_two_digits(40002156));
}

//Precondition:  num is a long long greater than 99.
//Postcondition: returns a 2 digit number, the first two
//               digits of num
int first_two_digits(long long num)
{
    //TODO
}