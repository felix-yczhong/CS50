#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //the program name itself is prepended at argv[0], hence argc always > 0
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int argv_strlen = strlen(argv[1]);
    for (int index = 0; index < argv_strlen; index++)
    {
        if (!isalpha(argv[1][index]))
        {
            printf("Usage: ./caesar keyword\n");
            return 1;
        }
    }
 
    int key[argv_strlen];
    for (int index = 0; index < argv_strlen; index++)
    {
        if (!isupper(argv[1][index]))
        {
            key[index] = argv[1][index] - 97;
        }
        else
        {
            key[index] = argv[1][index] - 65;
        }
    }
    
    string plaintext = get_string("plaintext:  ");
    int plaintext_len = strlen(plaintext);
    char ciphertext[plaintext_len + 1];
    for (int index = 0, index_key = 0; index < plaintext_len; index++)
    {
        if (!isalpha(plaintext[index]))
        {
            ciphertext[index] = plaintext[index];                
        }
        else
        {
            // 'A' = 65, 'a' = 97
            if (!isupper(plaintext[index]))
            {
                ciphertext[index] = 97 + (plaintext[index] - 97 + key[index_key % argv_strlen]) % 26;
            }
            else
            {
                ciphertext[index] = 65 + (plaintext[index] - 65 + key[index_key % argv_strlen]) % 26;
            }
            index_key++;
        }
    }
    ciphertext[plaintext_len] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    
    return 0;
}
