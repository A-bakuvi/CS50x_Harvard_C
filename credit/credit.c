#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Prompt input
// calculate checksum
// check for card length and starting digits
// print AMEX, MASTERCARD, VISA or INVALID

// 2223016768739313
// 5555555555554444
// 5105105105105100
// 371449635398431
// 4111111111111111

long input;

int main(void)
{
    input = get_long("Number: ");

    int modulo1 = input % 10;
    int modulo2 = ((input / 10) % 10) * 2 % 10 + ((((input / 10) % 10) * 2) / 10) % 10;
    int modulo3 = (input / 100) % 10;
    int modulo4 = ((input / 1000) % 10) * 2 % 10 + ((((input / 1000) % 10) * 2) / 10) % 10;
    int modulo5 = (input / 10000) % 10;
    int modulo6 = ((input / 100000) % 10) * 2 % 10 + ((((input / 100000) % 10) * 2) / 10) % 10;
    int modulo7 = (input / 1000000) % 10;
    int modulo8 = ((input / 10000000) % 10) * 2 % 10 + ((((input / 10000000) % 10) * 2) / 10) % 10;
    int modulo9 = (input / 100000000) % 10;
    int modulo10 =
        ((input / 1000000000) % 10) * 2 % 10 + ((((input / 1000000000) % 10) * 2) / 10) % 10;
    int modulo11 = (input / 10000000000) % 10;
    int modulo12 =
        ((input / 100000000000) % 10) * 2 % 10 + ((((input / 100000000000) % 10) * 2) / 10) % 10;
    int modulo13 = (input / 1000000000000) % 10;
    int modulo14 = ((input / 10000000000000) % 10) * 2 % 10 +
                   ((((input / 10000000000000) % 10) * 2) / 10) % 10;
    int modulo15 = (input / 100000000000000) % 10;
    int modulo16 = ((input / 1000000000000000) % 10) * 2 % 10 +
                   ((((input / 1000000000000000) % 10) * 2) / 10) % 10;

    int totalMasterVisa =
        modulo2 + modulo4 + modulo6 + modulo8 + modulo10 + modulo12 + modulo14 + modulo16;
    int restMasterVisa =
        modulo1 + modulo3 + modulo5 + modulo7 + modulo9 + modulo11 + modulo13 + modulo15;
    int totalVisa13 = modulo2 + modulo4 + modulo6 + modulo8 + modulo10 + modulo12;
    int restVisa13 = modulo1 + modulo3 + modulo5 + modulo7 + modulo9 + modulo11 + modulo13;
    int totalAmex = modulo2 + modulo4 + modulo6 + modulo8 + modulo10 + modulo12 + modulo14;
    int restAmex = modulo1 + modulo3 + modulo5 + modulo7 + modulo9 + modulo11 + modulo13 + modulo15;

    if ((totalMasterVisa + restMasterVisa) % 10 == 0)
    {
        if ((input / 1000000000000000) % 10 == 4)
        {
            printf("VISA\n");
        }
        else if ((input / 1000000000000000) % 10 == 5 &&
                 (modulo15 == 1 || modulo15 == 2 || modulo15 == 3 || modulo15 == 4 ||
                  modulo15 == 5))
        {
            printf("MASTERCARD\n");
        }
        else if ((totalVisa13 + restVisa13) % 10 == 0)
        {
            if (modulo13 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if ((totalAmex + restAmex) % 10 == 0)
        {
            if (modulo15 == 3 &&
                ((input / 10000000000000) % 10 == 4 || (input / 10000000000000) % 10 == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
