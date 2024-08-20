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
    printf("Method:getDoubled -> received %li to start\n", num);
    int doubled = 0;
    do
    {
        num /= 10;

        int secondLastDigit = num % 10;
        printf("Now secondLastDigit is: %i\n", secondLastDigit);

        doubled += secondLastDigit * 2;
        printf("Now doubled is: %i\n", doubled);

        num /= 10;
    }
    while (num > 0);

    return doubled;
}

int getTotal(long num, int doubled)
{
    int sumOfTotal = 0;

    printf("Method: getTotal -> It starts with num:%li, doubled:%i\n", num, doubled);
    do
    {
        printf("Now the digit is %li\n", num%10);

        sumOfTotal += num % 10;
        printf("Current sumOfTotal is: %i\n", sumOfTotal);
        num /= 100;
    }
    while (num > 0);

    sumOfTotal += doubled;
    printf("Added doubled and sumOfTotal is: %i\n", sumOfTotal);

    sumOfTotal %= 10;
    printf("Get the last digif of sumOfTotal is: %i\n", sumOfTotal);

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

    printf("sumOfDoubled: %i, sumOfTotal: %i, twoDigits: %i\n", sumOfDoubled, sumOfTotal,twoDigits);

    if (sumOfTotal != 0)
    {
        printf("INVALID\n");
        return;
    }

    switch (twoDigits)
    {
        case 34:
        case 37:
            printf("AMEX\n");
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            printf("MASTERCARD\n");
            break;
        default:
            if (twoDigits / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
    }
}
