#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validateCard(long);

int main(void)
{

    long cardNumber = get_long("Number: ");
    validateCard(cardNumber);
}

int getDoubled(long num)
{
    int doubled = 0;
    do
    {
        num /= 10;

        int secondLastDigit = num % 10;

        if (secondLastDigit * 2 > 9)
        {
            doubled += secondLastDigit * 2 - 9;
        }
        else
        {
            doubled += secondLastDigit * 2;
        }

        num /= 10;
    }
    while (num > 0);

    return doubled;
}

int getTotal(long num, int doubled)
{
    int sumOfTotal = 0;

    do
    {
        sumOfTotal += num % 10;
        num /= 100;
    }
    while (num > 0);

    sumOfTotal += doubled;
    sumOfTotal %= 10;

    return (int) sumOfTotal;
}

int firstTwoDigits(long num)
{
    long twoDigits = num;

    do
    {
        twoDigits /= 100;
    }
    while (twoDigits > 1000);

    if (twoDigits > 100)
    {
        twoDigits /= 10;
    }

    return (int) twoDigits;
}

void validateCard(long num)
{
    int sumOfDoubled = getDoubled(num);
    int sumOfTotal = getTotal(num, sumOfDoubled);
    int twoDigits = firstTwoDigits(num);

    if (sumOfTotal != 0)
    {
        printf("INVALID\n");
        return;
    }

    switch (twoDigits)
    {
        case 34:
        case 37:
            if (num >= 1e14 && num < 1e15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            if (num >= 1e15 && num < 1e16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        default:
            if (twoDigits / 10 == 4)
            {
                if ((num < 1e13 && num >= 1e12) || (num >= 1e15 && num < 1e16))
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
            break;
    }
}
