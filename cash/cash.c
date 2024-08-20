#include <cs50.h>
#include <stdio.h>

int getChange(int money);

int main(void)
{
    int changeOwed;
    do
    {
        changeOwed = get_int("Change owed: ");
    }
    while (changeOwed < 0);

    int result = getChange(changeOwed);
    printf("%i\n", result);
}

int getChange(int money)
{
    int numberOfCoins = 0;
    int remainders = money;

    do
    {
        if (remainders >= 25)
        {
            numberOfCoins = numberOfCoins + remainders / 25;
            remainders = remainders % 25;
        }
        if (remainders >= 10)
        {
            numberOfCoins = numberOfCoins + remainders / 10;
            remainders = remainders % 10;
        }
        if (remainders >= 5)
        {
            numberOfCoins = numberOfCoins + remainders / 5;
            remainders = remainders % 5;
        }

        numberOfCoins = numberOfCoins + remainders;
    }
    while (remainders < 0);

    return numberOfCoins;
}

