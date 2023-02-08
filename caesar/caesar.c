#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //make sure only put in single number
    if (argc != 2)
    {
        printf("I'll need 2 arguments\n");
        return 1;
    }
    //convert key
    int key = atoi(argv[1]);

    //get the plaintext
    char* plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    //encrypt the plain text
    for (int i = 0; i < strlen(plaintext); i++)
    {
        //if it's uppercase, encrypt and print
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            int alpha_pos = plaintext[i] - 'A';
            int encrypted_pos = (alpha_pos + key) % 26;
            printf("%c", encrypted_pos + 'A');
        }
        //else if it's lowercase, encrypt and print
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            int alpha_pos = plaintext[i] - 'a';
            int encrypted_pos = (alpha_pos + key) % 26;
            printf("%c", encrypted_pos + 'a');
        }
        //if it's not a letter, print it
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}