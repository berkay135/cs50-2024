#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    bool amex = false, mastercard = false, visa = false, invalid = false;
    long long number;
    int digitNumber;
    do
    {
        number = get_long_long("Enter credit number here:");
        digitNumber = (int) floor(log10(number) + 1);
        // printf("%d",digitNumber);
        if (digitNumber == 15) // amex
        {
            int firstTwoDigitsA = number / 10000000000000; // Calculate the first two digits

            if (firstTwoDigitsA == 34 || firstTwoDigitsA == 37)
            {
                amex = true;
                break;
            }
        }
        else if (digitNumber == 16) // mastercard and visa
        {
            int firstTwoDigitsB = number / 100000000000000; // Calculate the first two digits

            if (firstTwoDigitsB >= 51 && firstTwoDigitsB <= 55)
            {
                mastercard = true;
                break;
            }
            else
            {
                int firstOneDigitsA = number / 1000000000000000;
                if (firstOneDigitsA == 4)
                {
                    visa = true;
                    break;
                }
            }
        }
        else if (digitNumber == 13) // visa but only 13 digitnumber
        {
            int firstOneDigitsB = number / 1000000000000;
            if (firstOneDigitsB == 4)
            {
                visa = true;
                break;
            }
            // break;
        }
        else
        {
            invalid = true;
        }
        break;
    }
    while (true);
    // luhn's algorithm
    int sum1 = 0;
    int count = 0;
    while (number > 0)
    {
        int digit = number % 10;
        number /= 10;
        count++;

        if (count % 2 == 0)
        { // Every second digit from the right
            digit *= 2;
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10; // Add the digits of the double-digit number
            }
        }
        sum1 += digit;
    }

    if (amex && (sum1 % 10) == 0)
    {
        printf("AMEX\n");
    }
    else if (mastercard && (sum1 % 10) == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (visa && (sum1 % 10) == 0)
    {
        printf("VISA\n");
    }
    else if (invalid)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
