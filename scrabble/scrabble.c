#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // string letters[] =
    // {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int point1 = 0;
    int point2 = 0;

    string getInput1 = get_string("Player 1: ");
    string getInput2 = get_string("Player 2: ");

    /*for (int i = 0; i < 26; i++)
    {
        letters[i] = points[i];
        printf("%c\n", letters[i]);
    }*/

    for (int i = 0, n = strlen(getInput1); i < n; i++)
    {
        int f = toupper(getInput1[i]) - 65;
        point1 = point1 + points[f];
    }

    for (int i = 0, n = strlen(getInput2); i < n; i++)
    {
        int j = toupper(getInput2[i]) - 65;
        point2 = point2 + points[j];
    }

    if (point2 > point1)
    {
        printf("Player 2 wins!\n");
    }
    else if (point1 > point2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
