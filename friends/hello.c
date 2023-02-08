// Greets a user by their name

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Correct usage is ./hello <firstName> <lastName>\n");
        return 1;
    }
    // Collect a string from the user, then print their name
    string firstName = argv[1];
    string lastName = argv[2];
    printf("Hello, %s %s!\n", firstName, lastName);
}
