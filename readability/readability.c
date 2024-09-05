#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float getLetters(string text);
float getWords(string text);
float getSentences(string text);
int getIndex(float letters, float words, float sentences);

int main(void)
{
    string text = get_string("Text: ");

    float letters = getLetters(text);
    float words = getWords(text);
    float sentences = getSentences(text);
    int index = getIndex(letters, words, sentences);

    printf("Index is currently: %i\n", index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

float getLetters(string text)
{
    float letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {

        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

float getWords(string text)
{
    float words = 1;
    for (int i = 0; i < strlen(text); i++)
    {

        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

float getSentences(string text)
{
    float sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentences++;
        }
    }
    return sentences;
}

int getIndex(float letters, float words, float sentences)
{
    float averageLettersPerWord = letters / words;
    float L = averageLettersPerWord * 100;

    float averageSentencesPerWord = sentences / words;
    float S = averageSentencesPerWord * 100;

    // Coleman-Liau
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
