#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool checkChar(string key);

int main(int argc, string argv[])
{
    int k;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!checkChar(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    int lenght = strlen(plain);
    for (int i = 0; i < lenght; i++)
    {
        if (isupper(plain[i]))
        {
            plain[i] -= 65;
            k = plain[i];
            printf("%c", argv[1][k]);

        }
        else if (islower(plain[i]))
        {
            plain[i] -= 97;
            k = plain[i];
            argv[1][k] = tolower(argv[1][k]);
            printf("%c", argv[1][k]);
            argv[1][k] = toupper(argv[1][k]);
        }
        else if (isalnum(plain[i]) || isblank(plain[i]) || ispunct(plain[i]))
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}
/*
function for checking command line input and converst all key to upper case.
 1.Should be 26 unique characters
 2.Should not be a duplicate
*/
bool checkChar(string key)
{
    int lenght = strlen(key);

    if (lenght != 26)
    {
        return false;
    }
    for (int i = 0; i < lenght; i++)
    {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < lenght; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        //checks if is there duplicate
        for (int j = i + 1; j < lenght; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }

    return true;
}
