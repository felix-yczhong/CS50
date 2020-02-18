// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
node *root;

int counter = 0;

int hash(char letter)
{
    if (letter == '\'')
    {
        return 26;
    }
    else
    {
        return tolower(letter) - 'a';
    }
}

void init_new_node(node *new_node)
{
    for (int index = 0; index < N; index++)
    {
        new_node->children[index] = NULL;
    }
    new_node->is_word = false;
}

void sub_load(const char *word, const int len, int index, node *this_node)
{
    int pos = hash(word[index]);
    if (this_node->children[pos] == NULL)
    {
        node *new_node = malloc(sizeof(node));
        init_new_node(new_node);
        this_node->children[pos] = new_node;
    }

    if (index < len - 1)
    {
        sub_load(word, len, ++index, this_node->children[pos]);
    }
    else
    {
        this_node->children[pos]->is_word = true;
        counter++;
    }
}

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
        sub_load(word, strlen(word), 0, root);
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

bool sub_check(const char *word, const int len, int index, node *this_node)
{
    int pos = hash(word[index]);
    if (index < len - 1)
    {
        if (this_node->children[pos] == NULL)
        {
            return false;
        }
        else
        {
            this_node = this_node->children[pos];
            return sub_check(word, len, ++index, this_node);
        }
    }
    else
    {
        if (this_node->children[pos] == NULL)
        {
            return false;
        }
        else if (this_node->children[pos]->is_word == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    return sub_check(word, strlen(word), 0, root);
}

void sub_unload(node *this_node)
{
    for (int index = 0; index < N; index++)
    {
        if (this_node->children[index] != NULL)
        {
            sub_unload(this_node->children[index]);
        }
    }

    free(this_node);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    sub_unload(root);
    return true;
}
