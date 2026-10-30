#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// calculate the number of letters                           +
// calculate the number of words                             +
// calculate the number of sentences                         +
// find the average number of letters per 100 words          +
// find the average number of sentences per 100 words        +
// do the Coleman-Liau index                                 +
// print output as int so it rounds it                       +
// if output less than 1, print "Before Grade 1"             +
// if output greater than 16, print "Grade 16+"              +
// else print "Grade X" (X is the grade number)              +

/*float numberOfLetters(string letters);
float numberOfWords(string words);
float numberOfSentences(string sentences);

float averageLetter();
float averagesentence();*/

string input;
float c = 0;
float j = 0;
float f = 0;

int main(void)
{
    input = get_string("Text: ");
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) == 0)
        {
        }
        else
        {
            c = c + 1;
        }
    }
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isblank(input[i]) == true)
        {
            j = j + 1;
        }
    }
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            f = f + 1;
        }
    }
    float index = 0.0588 * ((c / (j + 1)) * 100) - 0.296 * ((f / (j + 1)) * 100) - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}

/*float numberOfLetters(string letters)
{
    for (int i = 0, n = strlen(letters); i < n; i++)
    {
        if (isalpha(letters[i]) == 0){}
        else
        {
            c = c+1;
        }
    }
    return c;
}

float numberOfWords(string words)
{
    for (int i = 0, n = strlen(words); i < n; i++)
    {
        if (isblank(words[i]) == true)
        {
            j = j+1;
        }
    }
    return j + 1;
}

float numberOfSentences(string sentences)
{
    for (int i = 0, n = strlen(sentences); i < n; i++)
    {
        if (sentences[i] == '.' || sentences[i] == '!' || sentences[i] == '?')
        {
            f = f + 1;
        }
    }
    return f;
}

float averageLetter()
{
    float avLetter = (numberOfLetters(input) / numberOfWords(input));
    return avLetter;
}

float averagesentence()
{
    float avSentence = (numberOfLetters(input) / numberOfWords(input));
    return avSentence;
}*/
