#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for (int j = 1; j <= h; j++)
    {
        for (int space = h - j; space > 0; space--)
        {
            printf(" ");
        }
        for (int brick = 0; brick < j; brick++)
        {
            printf("#");
        }
        printf("  ");
        for (int brick = 0; brick < j; brick++)
        {
            printf("#");
        }
        printf("\n");
    }

}
