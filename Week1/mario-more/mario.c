#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        printf("Height: ");
        scanf("%d", &n);
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++) // i = row | j = space | k = column
    {
        printf("\n");
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
    }
    printf("\n");
}
