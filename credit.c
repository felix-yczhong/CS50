#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

void debug_print_long(string s, long l)
{
    printf("%s: %ld", s, l);
}

void debug_print_int(string s, int i)
{
    printf("%s: %d\n", s, i);
}

long get_input(void)
{
    long credit_number = get_long("Number: ");
    //debug_print_long(credit_number);
    return credit_number;
}

int sum_every_2_digit(long credit_number)
{
    int sum = 0, check_num = 0;
    for (credit_number /= 10; credit_number != 0; credit_number /= 100)
    {
        check_num = credit_number % 10 * 2;
        //debug_print_int("check_num", check_num);
        if (check_num > 9)
        {
            sum += (check_num / 10) + (check_num % 10);
        } 
        else
        {
            sum += check_num;
        }
    }
    //debug_print_int("sum_every_2_digit", sum);
    return sum;
}

int sum_other_digit(long credit_number)
{
    int sum = 0;
    for (; credit_number != 0; credit_number /= 100)
    {
        //debug_print_int("check_num", credit_number % 10);
        sum += credit_number % 10;
    }
    //debug_print_int("sum_other_digit", sum);
    return sum;
}

string Luhns_algo(long credit_number)
{
    int sum = sum_every_2_digit(credit_number) + sum_other_digit(credit_number);
    //debug_print_int("total sum", sum);
    if (sum % 10 == 0)
    {
        return "VALID";
    } 
    else
    {
        return "INVALID";
    }
}

int check_digit(long credit_number)
{
    int counter = 0;
    while (credit_number > 0)
    {
        credit_number /= 10;
        counter++;
    }
    //debug_print_int("counter", counter);
    return counter;
}

string check_brand(long credit_number)
{
    int digit = check_digit(credit_number);
    while (credit_number > 99)
    {
        credit_number /= 10;
    }
    if ((credit_number == 34 || credit_number == 37) && digit == 15)
    {
        return "AMEX";
    } 
    else if (credit_number > 50 && credit_number < 56 && digit == 16)
    {
        return "MASTERCARD";
    } 
    else if (credit_number > 39 && credit_number < 50 && (digit == 13 || digit == 16))
    {
        return "VISA";
    } 
    else
    {
        return "INVALID";
    }
}

int main(void)
{
    long credit_number = get_input();
    string brand = check_brand(credit_number);
    //debug_print_int(brand, 0);
    if (strcmp(brand, "INVALID") == 0)
    {
        printf("INVALID\n");
    } 
    else
    {
        string validity = Luhns_algo(credit_number);
        //debug_print_int(validity, 0);
        if (strcmp(validity, "VALID") == 0)
        {
            printf("%s\n", brand);
        } 
        else
        {
            printf("INVALID\n");
        }
    }
    return 0;
}
