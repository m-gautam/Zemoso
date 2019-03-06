// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

int get_index(const char c);

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
node *root;

void unload2(node* root);

// For size of dictionary
int siz = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        // calculating size
        siz++;
        node *cursor = root;
        for (int i = 0, s = strlen(word); i < s; i++)
        {
            int k = get_index(word[i]);
            if (!cursor->children[k])
            {
                node *nnode = malloc(sizeof(node));
                nnode->is_word = false;
                for (int j = 0; j < N; j++)
                {
                    nnode->children[j] = NULL;
                }

                cursor->children[k] = nnode;
            }
            cursor = cursor->children[k];
        }
        cursor->is_word = true;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return siz;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = root;
    for (int i = 0, s = strlen(word); i<s; i++)
    {
        int k = get_index(word[i]);
        if (cursor->children[k] == NULL)
        {
            return false;
        }
        cursor = cursor->children[k];
    }

    // If word found in trie
    if (cursor->is_word == true && cursor != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // calling unload2 for unloading memory
    unload2(root);
    return true;
}


int get_index(const char c)
{
    int index;
    int comma = '\'';
    if (c == comma)
    {
        index = 26;
    }
    else
    {
        index = tolower(c) - 'a';
    }
    return index;
}

void unload2(node *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < N; i++)
    {
        unload2(root->children[i]);
    }
    free(root);
}
