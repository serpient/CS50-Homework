#include <cs50.h>
#include <stdio.h>

void formatter(int number);
void whitespace(int number);
void hashes(int number);

int main(void)
{
    printf("Height: ");
    int i = get_int();
    if (i < 0 || i > 23)
    {
        return main();
    }
    else if  (i == 0)
    {
        printf("");
    }
    else if ( i > 0 && i <= 23)
    {
        formatter(i);
    }

}


void formatter(int number)
{
    if (number == 1)
    {
        printf("#  #\n");
    }
    else
    {
        for (int i = 0; i < number; i++)
        {
            whitespace(number - i);
            hashes(i);
            printf("  ");
            hashes(i);
            printf("\n");
        }
    }

}

void whitespace(int number)
{
    for (int i = 2; i <= number; i++)
    {
        printf(" ");
    }
}

void hashes(int number)
{
    for (int i = 0; i <= number; i++)
    {
        printf("#");
    }
}
