#include <cs50.h>
#include <stdio.h>

int get_input(void) {
    int input;
    do {
       input = get_int("Height: ");     
    } while (input > 8 || input < 1);
    return input;
}

void print_pyramid(int height) {
    for (int index = 1; index <= height; index++) {
        for (int index_whitespace = height - index; index_whitespace > 0; index_whitespace--) {
            printf(" ");
        }
        for (int index_hash = 0; index_hash < index; index_hash++) {
            printf("#");
        }
        
        printf("  ");
        
        for (int index_hash = 0; index_hash < index; index_hash++) {
            printf("#");
        }

        printf("\n");
    }
}
int main(void)
{
    int height = get_input();
    print_pyramid(height);
}
