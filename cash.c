#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_input(void)
{
    float change_owed;
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while (round(change_owed * 100) < 1);
    return change_owed;
}

void debug_sum_change(int *count, int coin_num)
{
    printf("number of each coin: quarter, dime, nickel, penny\n");
    for (int index = 0; index < coin_num; index++)
    {
        printf("%d ", count[index]);
    }
    printf("\n");
}

int sum_change(float dividend)
{
    float coin[] = {0.25, 0.1, 0.05, 0.01};
    int coin_num = 4, sum = 0, count[coin_num];

    float remainder;
    for (int index = 0; index < coin_num; index++)
    {
        // dividend = divisor * quotient + remainder
        remainder = (float)((int)round(dividend * 100) % (int)round(coin[index] * 100)) / 100;
        count[index] = round((dividend - remainder) / coin[index]);
        dividend = remainder;
        sum += count[index];
    }
    // debug_sum_change(count, coin_num);
    return sum;
}

int main(void)
{
    printf("%d\n", sum_change(get_input()));
    return 0;
}
