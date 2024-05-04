#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int scrbbl(string player)
{

    for (int i = 0, n = strlen(player); i < n; i++)
    {
        player[i] = toupper(player[i]);
    }

    int sum = 0;
    for (int i = 0; i < strlen(player); i++)
    {
        if (isupper(player[i]))
        {
            sum = sum + POINTS[player[i] - 65];
        }
    }
    return sum;
}

int main(void)
{

    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    int score1 = scrbbl(player1);
    int score2 = scrbbl(player2);

    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}
