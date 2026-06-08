#include <cs50.h>
#include <stdio.h>

int luhnalgo(long number);
void startingnums(long number, int counter);
int digitcount(long number);

int main(void)
{
    long number = get_long("Number: ");
    int check1 = luhnalgo(number);
    if (check1 == 0)
    {
        int counter = digitcount(number);
        if (counter == 13 || counter == 15 || counter == 16)
        {
            startingnums(number, counter);
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

int luhnalgo(long number)
{
    int odd = 0;
    int even = 0;
    int prev_place;
    while (number > 0)
    {
        odd = odd + (number % 10);
        prev_place = number % 10;
        number = (number - prev_place) / 10;
        if (((number % 10) * 2) > 9)
        {
            even = even + (((number % 10) * 2) % 10) + 1;
        }
        else
        {
            even = even + ((number % 10) * 2);
        }
        prev_place = number % 10;
        number = (number - prev_place) / 10;
    }
    int result = (even + odd) % 10;

    return result;
}

void startingnums(long number, int counter)
{
    while (number > 99)
    {
        number = number / 10;
    }
    if ((number < 56 && number > 50) && counter == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((number == 34 || number == 37) && counter == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        number = number / 10;
        if (number == 4 && (counter == 13 || counter == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int digitcount(long number)
{
    int counter = 0;
    while (number > 0)
    {
        counter += 1;
        number = number / 10;
    }
    return counter;
}
