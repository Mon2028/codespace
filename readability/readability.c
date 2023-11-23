#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //getting use input
    string input = get_string("Text: ");
    int n = strlen(input);

    //count the number of letters, words, and sentences in the text
    int lettercount = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(input[i]))
        {
            lettercount++;
        }

    }
    int wordcount = 1;
    for (int i = 0; i < n; i++)
    {
        if (isspace(input[i]) && isgraph(input[i + 1]))
        {
            wordcount++;
        }
    }
    int sentcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(input[i]) && input[i + 1] == '.')
        {
            sentcount++;
        }
        else if (isalpha(input[i]) && input[i + 1] == '!')
        {
            sentcount++;
        }
        else if (isalpha(input[i]) && input[i + 1] == '?')
        {
            sentcount++;
        }
    }
    float l = (float) lettercount / wordcount * 100;
    float s = (float) sentcount / wordcount * 100;
    float grade = 0.0588 * l - 0.296 * s - 15.8;
    printf("%i %i %i\n", lettercount, wordcount, sentcount);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
         printf("Grade 16+\n");
    }
    else
    {

        printf("Grade 16+\n");

    }

}