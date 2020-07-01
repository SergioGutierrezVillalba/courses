#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    const char *hashtag = "#";

    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // prints left-side
        for (int j = 1; j <= i; j++)
        {
            printf("%s", hashtag);
        }

        // prints space between
        printf("  ");

        // prints right-side
        for (int j = 1; j <= i; j++)
        {
            printf("%s", hashtag);
        }

        printf("\n");
    }

}