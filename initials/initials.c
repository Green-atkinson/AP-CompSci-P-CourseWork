#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

/* $ ./initials
Regulus Arcturus Black
RAB

get_string
assume only letters and spaces
assume only single space between letters*/

void initial(char* name);

int main(void)
{
    //get the user's name
    char* name = get_string("");
    initial(name);
}


//pre: takes in an array with a full name
//post: prints out the initials of that full name

void initial(char* name)
{
    //create an array for initials
    char initials[100];
    int i = 0;

    //make a counter
    int j = 1;

    //the first character should be your first initial
    initials[0] = toupper(name[0]);

    //go through 'name' array and find initials
    for (i = 1; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            //add to 'initials' array, make sure it takes upper & lower case letters
            initials[j] = toupper(name[i + 1]);
            j++;
        }
    }
    //end the initials array with a null terminater
    initials[j] = '\0';

    //print out initials
    printf("%s\n", initials);
}