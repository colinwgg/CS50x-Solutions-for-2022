#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    string t = get_string("TEXT: ");
    double a = count_letters(t);
    double b = count_words(t);
    double c = count_sentences(t);
    double L = a / b * 100.0;
    double S = c / b * 100.0;
    double index = 0.0588 * L - 0.296 * S - 15.8;   //全部使用浮点数以避免计算时的误差
    int i = (int) round(index);
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", i);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalnum(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}
int count_words(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words + 1;   //空格+1即为单词数
}
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }
    }
    return sentences;
}
