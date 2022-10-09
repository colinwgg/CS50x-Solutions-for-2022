#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int q = 0, n = strlen(argv[1]); q < n; q++)
    {
        if (!isalpha(argv[1][q]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        else
        {
            char ch = argv[1][q];
            for (int check = 0; check < n; check++)
            {
                if (ch == argv[1][check] && check != q)
                {
                    printf("Key must not contain repeated characters.\n"); //当前字符与string中的所有字符比较，检查是否存在重复
                    return 1;
                }
            }
        }
    }
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, len = strlen(p); i < len; i++)
    {
        if (isupper(p[i]))
        {
            p[i] = toupper(argv[1][p[i] - 65]);//65即A在ASCII中对应值，下同。
        }
        else if (islower(p[i]))
        {
            p[i] = tolower(argv[1][p[i] - 97]);
        }
        else
        {
        }
        printf("%c", p[i]);
    }
    printf("\n");
}
//最难的部分不在于与密码一一对应并打印，而在于第一步的check。
