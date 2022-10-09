// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int hash_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int num = hash(word);
    node *cursor = table[num];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (toupper(word[0]) - 'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char words[LENGTH + 1];
    while (fscanf(file, "%s", words) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }
        strcpy(new->word, words);
        int hash_num = hash(words);
        new->next = table[hash_num];
        table[hash_num] = new;
        hash_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return hash_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor = NULL;
    node *tmp = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = tmp = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        if (i == N - 1)
        {
            return true;
        }
    }
    return false;
}