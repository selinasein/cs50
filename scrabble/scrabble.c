#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getPlayersValue(void);
int getPlayersScores(void);

string players[2];
int playersScores[2];
const int scores[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    getPlayersValue();
    getPlayersScores();

    if (playersScores[0] > playersScores[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (playersScores[0] < playersScores[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    };
}

int getPlayersValue(void)
{
    for (int i = 0; i < 2; i++)
    {
        string value = get_string("Player %i: ", i + 1);

        int n = 0;
        while (value[n] != '\0')
        {
            if (islower(value[n]))
            {
                value[n] = toupper(value[n]);
            }

            n++;
        }
        players[i] = value;
    };
    return 0;
}

int getPlayersScores(void)
{
    for (int i = 0; i < 2; i++)
    {
        int n = 0;
        int playerScore = 0;
        while (players[i][n] != '\0')
        {
            int index = players[i][n] - 65;
            playerScore = playerScore + scores[index];
            n++;
        }
        playersScores[i] = playerScore;
    };

    return 0;
};
