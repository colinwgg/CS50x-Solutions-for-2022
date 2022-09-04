#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height= "); 
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf(" ");
        }
        for (int m = 8 - n + i + 1; m > 8 - n; m--)
        {
            printf("#");
        }
        printf("  ");
        for (int q = 8 - n + i + 1; q > 8 - n; q--)
        {
            printf("#");
        }
        printf("\n");
    }
}