#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validateKey(string key, int length);
void generateCiphertext(string key, string plaintext, char ciphertext[], int plaintextLength);

int main(int argc, string argv[])
{
    // 1. Get Key
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string key = argv[1];
    int length = strlen(key);

    // 2. Validate Key
    if (validateKey(key, length) == 1)
    {
        return 1;
    };

    // 3. Get plaintext.
    string plaintext = get_string("plaintext: ");

    // 4. Encipher
    int plaintextLength = strlen(plaintext);
    char ciphertext[plaintextLength + 1];
    generateCiphertext(key, plaintext, ciphertext, plaintextLength);

    // 5. Print ciphertext.
    printf("ciphertext: %s\n", ciphertext);
}

int validateKey(string key, int length)
{
    // a. Check key length
    if (length < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        // b. Check for non-apha characters
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        // c. Check for repeated characters
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    };

    return 0;
};

void generateCiphertext(string key, string plaintext, char ciphertext[], int plaintextLength)
{

    for (int i = 0; i < plaintextLength; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            // Leave non-alphabetic characters as-is.
            ciphertext[i] = plaintext[i];
        }
        else if (islower(plaintext[i]))
        {
            // Preserve case.
            char uppertext = toupper(plaintext[i]);
            int index = uppertext - 65;
            ciphertext[i] = tolower(key[index]);
        }
        else
        {
            int index = plaintext[i] - 65;
            ciphertext[i] = toupper(key[index]);
        };
    }
    ciphertext[plaintextLength] = '\0';

    return;
};
