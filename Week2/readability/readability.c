#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = round((float) letters / (float) words * 100.0);
    float s = round((float) sentences / (float) words * 100.0);

    // Compute the Coleman-Liau index
    float index = (0.0588 * l) - (0.296 * s) - 15.8;

    // Print the grade level
    /*printf("Letters: %d\n", count_letters(text));
    printf("Words: %d\n", count_words(text));
    printf("Sentences: %d\n", count_sentences(text));*/

    if (index >= 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %0.f\n", round(index - 0.05));
}

int count_letters(string text)
{
    // Return the number of letters in text(harf)
    int counter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
            counter++;
    }

    return counter;
}

int count_words(string text)
{
    int counter = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            counter += 1;
        }
    }

    return counter;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int counter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter += 1;
        }
    }
    return counter;
}
