#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// get key
// use int main(int argc, string argv[])
// validate key
// check key length
// check for non-alphabetic characters
// check for repeated characters (case-insensitive)
// get plaintext
// use get_string
// encipher
// for each character, determine what letter it maps to
// preserve case
// leave non-alphabetic characters as is
// print ciphertext

string plain_text;
int text;
// string number[];
string alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                     "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
string alphabetl[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
                      "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main(int argc, string argv[])
{
    if (argc == 2)
    {

        for (int i = 0; i < 26; i++)
        {
            if (isalpha(argv[1][i]) == false)
            {
                printf("Provide alphabetic characters\n");
                return 1;
            }

            else if (strlen(argv[1]) != 26)
            {
                printf("Provide 26 alphabetic characters\n");
                return 1;
            }
            for (int k = i + 1; k < 26; k++)
            {
                if (argv[1][i] == argv[1][k])
                {
                    printf("Don't repeat characters!\n");
                    return 1;
                }
            }
        }
        plain_text = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int f = 0, p = strlen(plain_text); f < p; f++)
        {
            if (ispunct(plain_text[f]))
            {
                printf("%c", plain_text[f]);
            }
            if (isblank(plain_text[f]))
            {
                printf("%c", plain_text[f]);
            }
            if (isdigit(plain_text[f]))
            {
                printf("%c", plain_text[f]);
            }
            if (islower(plain_text[f]))
            {
                // tolower(argv[1]);
                text = plain_text[f] - 'a';
                printf("%c", tolower(argv[1][text]));
            }
            if (isupper(plain_text[f]))
            {
                // toupper(argv[1]);
                text = plain_text[f] - 'A';
                printf("%c", toupper(argv[1][text]));
            }
        }
        // printf("cyphertext: %s\n", number[argv[1][text]]);
        printf("\n");
        return 0;
    }
    else
    {
        printf("Provide 1 command-line argument\n");
        return 1;
    }
}
