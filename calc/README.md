# README.md

Divide and Conquer
In this problem, you will be tasked with implementing a very simple command-line based calculator program. Your program will accept inputs like this (wherein underlined text represents user input):

~/chapter2/ $ ./calc 4 + 5
9.000000
or, indeed like this (allowing the user to perform some basic floating-point arithmetic)

~/chapter2/ $ ./calc 8.38 - 5.12
3.260000
such that the user can perform all five of the basic math operations that C permits — addition, subtraction, multiplication, division, and modulo.

Notice that unlike many other programs you’ve likely written up to this point, and just like Old Friends, users are not entering any information after the program has started running. Rather, they are providing all of their input to the program at the command line, before the program has begun.

Recall from Doug’s short that if we collect information from the user at the command line, we can use two special parameters passed into main (conventionally called argc and argv) which represent the number of arguments the user provided and the actual data the user provided, respectively. Given the example use case above, how many command-line arguments is the user expected to provide?

If they fail to provide the correct number, your program should exit (possibly printing out an error message that tells them how they should have run the program) and return 1; so that we can automate testing of your code.

Assuming we have the right number of command-line arguments, we’re well on our way. There’s a catch, though.

Just because the user types a real number at the command line, that doesn’t mean their input will be automatically stored in a float. Actually, it will be stored as a string that just so happens to look like an float; after all, remember the data type of argv? It’s an array where each element is a string! And so you’ll need to convert that string to an actual float. As luck would have it, a function, atof, exists for exactly that purpose! Here’s how you might use it:

float a = atof(argv[1]);
There are two values that need to be converted from a string to a float (argv[1] and argv[3], specifically). So that just leaves dealing with the operator. Recall from the shorts on arrays and strings that a string in C is really just an array of characters. And we can access individual elements of an array by using square bracket notation to index into that array.

string s = "Calculator";
printf("%c\n", s[0]); // prints 'C'
Similarly, if we have another string which just so happens to be called argv[2] can we index into its first element, which will be a single character (char).

printf("%c\n", argv[2][0]); // prints the first character of argv[2]
And that also means we can compare argv[2][0] against a variety of possible values (such as +, -, x, / or %, for example) and make certain decisions in our program based on what that character is, perhaps by making use of some Boolean expressions and conditional statements. (Of course, since there are only a small number of characters that we care about in argv[2][0], you might also find this a good opportunity to use a switch statement for perhaps the first time.)

Note above that we suggest using a lowercase x instead of the typical asterisk used to represent multiplication. The reason for that is that the asterisk means something special at the command line, and so ordinarily it will not be processed correctly. So just be sure when you encounter an x at the command line that you actually perform a multiplication!

Once you’ve performed the arithmetic, just print out the result to the user on its own line, so we can automate testing of your code. By default, C will print out floating point values to six decimal places. Might as well leave it that way, there’s plenty to do otherwise in this problem!

The Mod Squad
If you’re reading this section after you’ve already tried to implement modulo (%) in your calculator, you’ve likely noticed an error when compiling that looks something like the following:

error: invalid operands to binary expression ('float' and 'float')
Why are you seeing this? Well as it turns out, the modulo operator is not well-defined for floating point numbers. That is to say, there’s no defined value for an expression like:

10.7 % 3.28
Rather, it turns out that modulo is only defined (in C, anyway) for integers. How, then, can we implement the operator while still allowing the user to input floating point values at the command line? Seems like we’re going to have to do some extra work. After all, if modulo is really just the remainder after dividing the number on the left of the operator by the number on the right, a quick long division[1] will tell us that 10.7 % 3.28 should equal 0.86, the remainder after calculating 10.7 / 3.28.

That leads to a discussion of today’s Arithmetic Fun Fact™[2]. If

x % y = z
then that means that

x / y = q rem z
or put differently

q = (int) (x / y);
z = x - (y * q);
Perhaps best to illustrate this with an example, as the formulas are perhaps a bit on the intimidating side. Let’s return to our prior example of calculating 10.7 % 3.28.

q = (int) (10.7 / 3.28);
q = (int) 3.262195;
q = 3
mod = 10.7 - (3.28 * 3);
mod = 10.7 - 9.84
mod = 0.86
So that is one way to implement the modulo operator by using other operators that C has defined for floats. To be sure, there are others, but this one should do the trick!

Subtract the Confusion
To be clear, you may make the following assumptions with respect to your calculator.

argv[1], should it be present, is guaranteed to consist only of digit characters, possibly a decimal point, and possibly a negative sign. You do not need to check otherwise.

argv[2], should it be present, is not guaranteed to be +, -, x, / or %. Your program should respond somehow if the user provides an invalid operator and return 1;.

argv[3], should it be present, is guaranteed to consist only of digit characters, possibly a decimal point, and possibly a negative sign. You do not need to check otherwise.

You needn’t worry about floating-point imprecision with your calculator, and you needn’t print out the correct answer to more than six decimal places.

Testing
Correctness

If you’d like to check the correctness of your program with check50, you may execute the below.

check50 cs50/problems/2019/ap/calc
Style

style50 calc.c
Staff Solution
If you’d like to play with the staff’s own implementation of calc, you may execute the below.

~cs50/2019/ap/chapter2/calc
How to Submit
Step 1 of 2

Be sure that calc.c is in ~/chapter2/calc/, as with:

cd ~/chapter2/calc/
ls
Step 2 of 2

To submit calc, execute

cd ~/chapter2/calc/
submit50 cs50/problems/2019/ap/calc
inputting your GitHub username and GitHub password as prompted.

If you run into any trouble, email sysadmins@cs50.harvard.edu!

You may resubmit any problem as many times as you’d like.

Your submission should be graded for correctness within 2 minutes, at which point your score will appear at submit.cs50.io!

This was Calc.

1. Bet you didn’t think long division would come in handy again! And frankly, it probably didn’t. Likely, you just used Google. That’s thinking with portals!
2. We don’t actually hold a trademark on this term.