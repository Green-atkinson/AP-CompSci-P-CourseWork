#include <stdio.h>
#include <cs50.h>

int get_response(void);
void ask_question(string question, string option1, string option2,
                  string option3, string option4);
int main(void)
{
//starting scores for each sport

    int bowl = 0, swim = 0, foot = 0, soft = 0;
    int response;

//run the quiz

//question1
    printf("How comfortable are you running?\n");
    printf("1 - I love running!\n");
    printf("2 - EW\n");
    printf("3 - I enjoy moving around, but not running.\n");
    printf("4 - I like running, but not a lot.\n");

    response = get_response();

    switch(response)
    {
        case 1: foot += 3; soft += 1; swim += 2; break;
        case 2: soft += 2; swim += 1; bowl += 3; break;
        case 3: foot += 1; soft += 0; swim += 3; bowl +=2; break;
        case 4: foot += 2; soft += 3; swim += 0; bowl += 1; break;
        default: printf("Something went wrong"); return 0;
    }


    printf("bowl = %i, foot = %i, soft = %i, swim = %i.\n", bowl, foot, soft, swim);
//question2
    ask_question("Would you like a helmet\n",
                 "1 - Yes, but only if it has a mask.\n",
                 "2 - Yes, but no mask.\n",
                 "3 - No, helmets don't do anything.\n",
                "4 - No, helmets are ugly.\n");

    response = get_response();

    //update values
    switch(response){
        case 1: bowl += -3; foot +=  3; soft +=  1; swim += -3; break;
        case 2: bowl += -3; foot +=  1; soft +=  2; swim += -3; break;
        case 3: bowl +=  2; foot += -3; soft += -1; swim +=  3; break;
        case 4: bowl +=  3; foot += -2; soft += -1; swim +=  2; break;
        default: printf("Something went wrong. \n"); return 0;

    }
printf("bowl = %i, foot = %i, soft = %i, swim = %i.\n", bowl, foot, soft, swim);


if (bowl > foot && bowl > soft && bowl > swim)
{
   printf("The sport you should pick is bowling.\n");
}
else if ( foot > soft && foot > swim)
{
    printf("The sport you should pick is football.\n");
}
else if ( swim > soft )
{
   printf("The sport you should pick is swimming.\n");
}
else
{
   printf("The sport you should pick is softball.\n");
}





//update values
//..
//ask the last question
//update values

//figure out which sport
//tell them which sport

}

//gets a user response, an int from 1 to 4.
int get_response(void)
{
    int user_input = 0;
    do
    {
        user_input = get_int("");
    }
    while (user_input < 1 || user_input > 4);

    return user_input;
}

void ask_question(string question, string option1, string option2,
                  string option3, string option4)
{
    printf("%s", question);
    printf("%s", option1);
    printf("%s", option2);
    printf("%s", option3);
    printf("%s", option4);
}