//a program to implement addition and subtraction of floats
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    //ensure user put in correct number of args
    if (argc != 4)
    {
        printf("I'll need 3 args\n");
        return 1;
    }
    //read in the two nums to memory
    float num1 = atof(argv[1]);
    float num2 = atof(argv[3]);

    //read in the operator to memory
    char op = argv[2][0];

    //based on the operator, print
    switch (op)
    {
        case '+':
        case '@':
            printf("%f\n", num1 + num2);
        case '-':
            printf("%f\n", num1 - num2);
            break;

        //make multiplication, devision, and mode
        case '*':
        case 'x':
            printf("%f\n", num1 * num2);
            break;
        case '/':
            printf("%f\n", num1 / num2);
            break;
        case '%':
            printf("%f\n", num1 - (int)(num1 / num2) * num2);
            break;
        //if you didn't hit any other case statements,
        default:
            printf("default case.\n");
            return 1;
    }
}