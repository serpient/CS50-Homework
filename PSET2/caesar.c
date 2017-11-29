#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("plaintext: ");
        string plainText = get_string();
        printf("ciphertext: ");
        int key = atoi(argv[1]);
        // loops through the length of the plainText
        for (int i = 0, n = strlen(plainText); i < n; i++)
        {
            int letter = (int) plainText[i];
            int newCharacter = letter + key;
            // filters out only alphabetic letters to be converted
            if (isalpha(plainText[i]))
            {
                // filters out lowercase alphabetic letters
                if (plainText[i] >= 'a' && plainText[i] <= 'z')
                {
                    while (newCharacter > 'z' || newCharacter < 'a' )
                    {
                        newCharacter = (int) 'a' + ((newCharacter % 'z') - 1);
                    }
                }
                // filters out uppercase alphabetic letters
                else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
                {
                    while (newCharacter > 'Z' || newCharacter < 'A' )
                    {
                        newCharacter = (int) 'A' + ((newCharacter % 'Z') - 1);
                    }
                }
            }
            // all non-alphabetic letters will remain the same.
            else if (!isalpha(plainText[i]))
            {
                newCharacter = plainText[i];
            }
            printf("%c", newCharacter);
        }
    }
    else
    {
        printf("Error, this function requires another integer argument");
        return 1;
    }
    printf("\n");
    return 0;

}


