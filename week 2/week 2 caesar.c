#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rotate(char c, int i);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");//数组大于2错误
        return 1;
    }
    else
    {
        for (int q = 0, w = strlen(argv[1]); q < w; q++)
        {
            if (isdigit(argv[1][q]))
            {
            }
            else
            {
                printf("Usage: ./caesar key\n");//数组出现非数字，错误
                return 1;
            }
        }
    }
    int key = atoi(argv[1]);
    string pt = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, len = strlen(pt); i < len; i++)
    {
        char cph = rotate(pt[i], key);
        printf("%c", cph);
    }
    printf("\n");
}

char rotate(char c, int i)
{
    char cd = c;
    int rk = i % 26;
    if (isupper(c))
    {
        if (c + rk > 90)
        {
            cd = c - (26 - rk);//若相加大于ASCII中Z所在的90，则减去对应值。
        }
        else
        {
            cd = c + rk;
        }
    }
    else if (islower(c))
    {
        if (c + rk > 122)
        {
            cd = c - (26 - rk);
        }
        else
        {
            cd = c + rk;
        }
    }
    else
    {
        cd = c;
    }
    return cd;
}
