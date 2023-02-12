# README.md

Hello, again!
In Hello you were asked to write a program that very simply printed the message hello, world\n to the screen when run. It’s not too much of a leap to extend this program to say hello to a specific person by asking for the user to type a name at the prompt instead, so the program behaves like this.

~/chapter2/friends $ ./hello
Your name: Zamyla
hello, Zamyla
In fact, the distro you downloaded contains a file, hello.c, with exactly this behavior. What we want, though, is a program that has this behavior instead:

~/chapter2/friends $ ./hello Zamyla
hello, Zamyla
See the slight difference? Instead of prompting the user for information after the program has started running, we collect the desired information from the user before they run the program, and then use that information once the program has started. How do we do so?

Recall that our programs are capable of knowing information about what the user typed at the command line by modifying the way we write the start of our main function. Instead of

int main(void)
if we start main off by typing

int main(int argc, string argv[])
we then have access to two special variables that we can use inside of main. First is argc, which is an integer variable that tells us how many things the user typed in at the command line, and second is argv, which is an array of strings representing exactly what the user typed.

Knowing this, and from the information in Doug’s short, can you now modify hello.c so that it prints out the name provided at the command line, instead of collecting a string from the user after the program has started?

One more wrinkle. How do you make sure the user in fact did provide you with one (and only one) additional argument, so that you can print it out? Well remember that’s what our new friend argc can manage for us. If the user doesn’t supply a command-line argument, best to terminate the program and have them try again. One way to accomplish this might be to have this near the top of our code:

if (argc != 2)
{
    printf("Usage: ./hello <name>\n");
    return 1;
}
Note what this accomplishes? We check to make sure that the user has supplied the proper number of command-line arguments (2). If not, we tell the user how they should run the program, and then we return 1;, which is our way of indicating that our program finished running, but not successfully. We use nonzero return values from main, also known as exit codes, to report back to the system that something went awry.

Testing
Correctness

If you’d like to check the correctness of your program with check50, you may execute the below.

check50 cs50/problems/2019/ap/friends/hello
Style

style50 hello.c
Staff Solution
If you’d like to play with the staff’s own implementation of hello, you may execute the below.

~cs50/chapter1/hello
Chill Out
In Fahrenheit you were asked to write a program that asked the user for a temperature in Celsius (which they provided via get_float) and which then printed out the equivalent temperature on the Fahrenheit scale.

~/chapter2/friends $ ./fahrenheit
C: 0
F: 32.0
In fahrenheit.c you will find a fully-functioning version of the code you were tasked with writing in that problem. Convert that program so that it accepts the Celsius temperature from the command line instead.

~/chapter2/friends $ ./fahrenheit 0
F: 32.0
There’s a catch, though.

Just because the user types a real number at the prompt, that doesn’t mean their input will be automatically stored in a float. Actually, it will be stored as a string that just so happens to look like an float; after all, remember the data type of argv? It’s an array where each element is a string! And so you’ll need to convert that string to an actual float. As luck would have it, a function, atof, exists for exactly that purpose! Here’s how you might use it:

float celsius = atof(argv[1]);
Notice, this time, we’ve declared celsius as an actual float so that you can do some arithmetic with it. Incidentally, you can assume that the user will only type real numbers at the command line.

Because atof is declared in stdlib.h, you’ll want to #include that header file atop your own code. And, as with hello.c earlier, you’ll want to make sure the user provides exactly the correct number of command-line arguments to your program before doing any calculations, returning 1 should they fail to.

Testing
Correctness

If you’d like to check the correctness of your program with check50, you may execute the below.

check50 cs50/problems/2019/ap/friends/fahrenheit
Style

style50 fahrenheit.c
Staff Solution
If you’d like to play with the staff’s own implementation of fahrenheit, you may execute the below.

~cs50/chapter1/fahrenheit
Makin' Bank
In Pennies you were asked to write a program that demonstrated the power of exponentiation by showing how much money you would have if a person gave you x pennies on a particular day, and then doubled the amount they gave you every day for a period of y days.

~/chapter2/friends $ ./pennies
Days in month: 31
Pennies on first day: 1
$21474836.47
As you might expect, we’d now like the program to work as follows.

~/chapter2/friends $ ./pennies 31 1
$21474836.47
Notice a few differences with this program from the previous two. How many command line arguments does this one accept? Be sure to modify your check against argc accordingly. And also know that in stdlib.h alongside of the function atof exists another, atoi, that converts a string to an int in much the same way that atof converts a string to a float.

Incidentally, you can assume that the user will only type integers at the command line; there’s no need for you to anticipate a rogue user this time around!

Testing
Correctness

If you’d like to check the correctness of your program with check50, you may execute the below.

check50 cs50/problems/2019/ap/friends/pennies
Style

style50 pennies.c
Staff Solution
If you’d like to play with the staff’s own implementation of pennies, you may execute the below.

~cs50/chapter1/pennies
How to Submit
Step 1 of 2

Recall that you were asked to create the files below:

hello.c

fahrenheit.c

pennies.c

Be sure that each of your files is in ~/chapter2/friends, as with:

cd ~/chapter2/friends
ls
If any file is not in ~/chapter2/friends, move it into that directory, as via mv (or via CS50 IDE’s lefthand file browser).

Step 2 of 2

To submit hello, execute

cd ~/chapter2/friends
submit50 cs50/problems/2019/ap/friends/hello
inputting your GitHub username and GitHub password as prompted.

To submit fahrenheit, execute

cd ~/chapter2/friends
submit50 cs50/problems/2019/ap/friends/fahrenheit
inputting your GitHub username and GitHub password as prompted.

To submit pennies, execute

cd ~/chapter2/friends
submit50 cs50/problems/2019/ap/friends/pennies
inputting your GitHub username and GitHub password as prompted.

If you run into any trouble, email sysadmins@cs50.harvard.edu!

You may resubmit any problem as many times as you’d like.

Your submission should be graded for correctness within 2 minutes, at which point your score will appear at submit.cs50.io!

This was Old Friends.