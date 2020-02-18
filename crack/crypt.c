#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <crypt.h>

#define salt_len 2
#define key_len 6
#define hash_len 14
#define select_list_len 55


int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./crypt salt key");
        return 1;
    }
    
    char hash[hash_len];
    strcpy(hash, crypt(argv[2], argv[1]));
    printf("%s", hash);
    return 0;
}
