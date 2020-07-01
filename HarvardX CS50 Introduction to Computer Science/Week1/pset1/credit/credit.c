#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

bool luhnAlgorithm(string numberCard, int sizeOfNumber);

int main(void)
{

    long cardNumber = 0;
    bool isNotValid = true;

    char str[256];

    while (isNotValid)
    {
        cardNumber = get_long("Number: ");
        if (cardNumber)
        {
            isNotValid = false;
        }
    }

    // long to string
    const int n = snprintf(NULL, 0, "%lu", cardNumber);
    char buf[n + 1];
    int sizeOfCardNumber = snprintf(buf, n + 1, "%lu", cardNumber);


    // check if has minimum length
    bool lessThanThirteenDigits = sizeOfCardNumber < 13;
    bool seventeenDigitsOrMore = sizeOfCardNumber >= 17;

    if (lessThanThirteenDigits || seventeenDigitsOrMore || !luhnAlgorithm(buf, sizeOfCardNumber))
    {
        printf("INVALID\n");
        return 0;
    }

    bool startsWithFour = buf[0] == '4';
    bool startsWith34or37 = buf[0] == '3' && (buf[1] == '7' || buf[1] == '4');
    bool startsWithFifties = buf[0] == '5' && (buf[1] == '1' || buf[1] == '2' || buf[1] == '3' || buf[1] == '4' || buf[1] == '5');

    if (sizeOfCardNumber == 13 && startsWithFour)
    {
        printf("VISA\n");
        return 0;
    }

    if (sizeOfCardNumber == 15 && startsWith34or37)
    {
        printf("AMEX\n");
        return 0;
    }

    if (sizeOfCardNumber == 16 && startsWithFour)
    {
        printf("VISA\n");
        return 0;
    }

    if (sizeOfCardNumber == 16 && startsWithFifties)
    {
        printf("MASTERCARD\n");
        return 0;
    }


    printf("INVALID\n");

}

int charToInt(char c)
{
    return c - '0';
}

bool luhnAlgorithm(string numberCard, int sizeOfNumber)
{
    int sum = 0;
    int intSize = 0;

    for (int i = 0; i < sizeOfNumber; i++)
    {

        if (i % 2 != 0)
        {
            // odd index
            sum += charToInt(numberCard[i]);
            continue;
        }

        if (charToInt(numberCard[i]) * 2 >= 10)
        {
            // int to string
            int length = snprintf(NULL, 0, "%d", charToInt(numberCard[i]) * 2);
            char *str = malloc(length + 1);
            snprintf(str, length + 1, "%d", charToInt(numberCard[i]) * 2);

            // two digits, separate and sum them
            sum += charToInt(str[0]) + charToInt(str[1]);

            free(str);
            continue;
        }

        // pair index
        sum += charToInt(numberCard[i]) * 2;
        continue;

    }

    return sum % 10 == 0;
}