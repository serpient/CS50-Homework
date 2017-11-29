#include <cs50.h>
#include <stdio.h>

void checker(long long ccNumber);
int length(long long ccNUmber);
void ccMFG(long long ccNumber);
int firstNumber(long long ccNUmber);

int main(void)
{
    printf("Number: ");
    long long ccNumber = get_long_long();
    checker(ccNumber);
    return 0;
}

void checker(long long ccNumber)
{
    int even = 0;
    int odd = 0;
    for (int i = length(ccNumber) - 1; i >= 0; i = i - 2)
    {
        even = even + (i * 2);
    }
    for (int i = length(ccNumber) - 2; i >= 0; i = i - 2)
    {
        odd = odd + (i * 2);
    }
    int sum = even + odd;
    if (sum % 10 == 0)
    {
        ccMFG(ccNumber);
    }
    else
    {
        printf("INVALID\n");
    }
}

void ccMFG(long long ccNumber)
{
    if (length(ccNumber) == 15)
    {
        printf("AMEX\n");
    }
    else if (length(ccNumber) == 13)
    {
        printf("VISA\n");
    }
    else if (length(ccNumber) == 16 && firstNumber(ccNumber) == 4)
    {
        printf("VISA\n");
    }
    else if (length(ccNumber) == 16 && firstNumber(ccNumber) == 5)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int length(long long ccNUmber)
{
    int count = 0;
    while (ccNUmber != 0)
    {
        ccNUmber /= 10;
        ++ count;
    }
    return count;
}

int firstNumber(long long ccNUmber)
{
    long long first = ccNUmber;
    while (first >= 10)
    {
        first = first / 10;
    }
    return first;
}