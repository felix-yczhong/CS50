#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <crypt.h>

#define salt_len 2
#define key_len 6
#define hash_len 13
#define select_list_len 55

char salt[salt_len];
char key[key_len];
char select_list_end = '\0';
char select_list[select_list_len] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char hash[hash_len];
char **g_argv;
int found = 0;

void validate_key()
{
    int counter = 0;
    for (int index = 0; index < hash_len; index++)
    {
        if (hash[index] == g_argv[1][index])
        {
            counter++;
        }
        else
        {
            break;
        }
    }
    
    if (counter == 13)
    {
        printf("%s\n", key);
        found = 1;
    }
}

void generate_key(int index)
{
    if (index != -1)
    {
        for (int index_select = 0; index_select < select_list_len; index_select++)
        {
            if (found == 1)
            {
                break;
            }
            if (index_select == 0)
            {
                key[index] = select_list_end;
            }
            else
            {
                key[index] = select_list[index_select - 1];
            }
            generate_key(index - 1);
        }
    }
    else
    {
        //printf("%s\n", key);
        strcpy(hash, crypt(key, salt));
        validate_key();
    }
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    g_argv = argv;
    
    //generate salt
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    
    //printf("%s", salt);
    
    key[5] = '\0';
    //generate a key eg
    generate_key(5);

    return 0;
}
