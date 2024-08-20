#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts the user for the pyramid's height.
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Prints out the pyramid.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int h = height - 1;

            if (j >= h - i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
