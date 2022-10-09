#include <cs50.h>
#include <stdio.h>

long check(long num);
long check1(long num);
int main(void)
{
    long num;
    do
    {
        num = get_long("What's your credit card number?\n");
    }
    while (num <= 0);
    long num1 = num;
    long sum1 = 0;
    long sum2 = 0;
    do
    {
        long a = num1 % 10;
        num1 = num1 / 100;
        sum1 = sum1 + a;
    }
    while (num1 >= 1);

    long num2 = num / 10;

    do
    {
        long b = num2 % 10;
        num2 = num2 / 100;
        b = 2 * b;
        if (b < 10)
        {
            sum2 = sum2 + b;
        }
        else
        {
            sum2 = sum2 + 1 + (b % 10);
        }
    }
    while (num2 >= 1);
    long sum;
    sum = (sum1 + sum2) % 10;
    if (sum == 0)
    {
        long n = check(num);
        long i = check1(num);
        if ((n == 34 || n == 37) && i == 15)
        {
            printf("AMEX\n");
        }
        else if (n == 4 && (i == 13 || i == 16))
        {
            printf("VISA\n");
        }
        else if ((n >= 51 && n <= 55) && i == 16)
        {
            printf("MASTERCARD\n");
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
long check(long k)
{
    do
    {
        k = k / 10;
    }
    while (k >= 100);
    return k;
}
long check1(long num)
{
    int i = 0;
    do
    {
        i = i + 1;
        num = num / 10;
    }
    while (num >= 1);
    return i;
}
