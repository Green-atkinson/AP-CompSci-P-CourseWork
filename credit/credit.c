#include "credit.h"

int main(void)
{
    //get the value from the user
    long long card_num = get_long("Card Number: ");
    int first_two = first_two_digits(card_num);
    int digits = count_digits(card_num);

    //check whether it passes Luhn's
    if(!luhn(card_num))
    {
        printf("INVALID\n");
    }
    //otherwise
    else if(digits == 15 && (first_two == 34 || first_two == 37))
    {

        printf("AMEX\n");
    }
    else if((digits == 13 || digits == 16) && first_two/10 == 4)
    {
        printf("VISA\n");
    }
    else if(digits == 16 && first_two >= 50 && first_two <= 55)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }


}