#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string argument);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    int length = strlen(plaintext);
    char cyphertext[length];

    for (int i = 0; i < length; i++)
    {
        cyphertext[i] = rotate(plaintext[i], key);
    }
    cyphertext[length] = '\0';

    printf("ciphertext: %s\n", cyphertext);
}

bool only_digits(string argument)
{
    for (int i = 0; i < strlen(argument); i++)
    {
        if (!isdigit(argument[i]))
        {
            return false;
        }
    }
    return true;
};

char rotate(char letter, int key)
{
    if (!isalpha(letter))
    {
        return letter;
    };

    int letterASCII = letter + key;

    if (isupper(letter))
    {

        while (letterASCII > 90)
        {
            letterASCII = letterASCII - 26;
        }
        return letterASCII;
    };

    if (islower(letter))
    {

        while (letterASCII > 122)
        {
            letterASCII = letterASCII - 26;
        }

        return letterASCII;
    }

    return letter;
}
