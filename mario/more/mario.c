#include <cs50.h>
#include <stdio.h>

// get user input  +
// print spaces
// print  left hashes
// print 2 spaces
// print right hashes +
// print all of them in 1 line

/*To print the result of a function between two strings in C, you can call the function within the
printf statement. For example:

printf("First string %d Second string\n", my_function());
Here, my_function() is called, and its return value is printed between "First string" and "Second
string". Make sure the format specifier matches the return type of your function.*/

int input;

void spaces(int input1);
void right_hashes(int inp);
void two_spaces();
void left_hashes(int l_hash);

int main(void)
{
    do
    {
        input = get_int("Height: ");
    }
    while (input > 8 || input < 1);

    for (int i = 0; i < input; i++)
    {
        // printf("%s\n" , right_hashes(i+1));
        spaces(i + 1);
        left_hashes(i + 1);
        two_spaces();
        right_hashes(i + 1);
    }
}

void right_hashes(int inp)
{
    for (int j = 0; j < inp; j++)
    {
        printf("#");
    }
    printf("\n");
}

void spaces(int input1)
{
    for (int b = input; b > input1; b--)
    {
        printf(" ");
    }
}

void two_spaces()
{
    printf("  ");
}

void left_hashes(int l_hash)
{
    for (int c = 0; c < l_hash; c++)
    {
        printf("#");
    }
}
