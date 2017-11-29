#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++ )
        {
            if (isalpha(argv[1][i]) == false)
            {
                printf("ERROR: %s - the key must be a single word", argv[1]);
                return 1;
            }
        }
        printf("plaintext: ");
        string s = get_string();
        string key = argv[1];
        int arrayOfKey[strlen(key)];

        //convert key characters into an array of ASCII numbers
        for (int i = 0; i < strlen(key); i++ )
        {
            // converting A - Z to 0 - 25
            arrayOfKey[i] = (int) key[i];
            if (key[i] <= 'Z' && key[i] >= 'A')
            {
                arrayOfKey[i] -= 65;
            }
            // converting a - z to 0 - 25
            else if (key[i] <= 'z' && key[i] >= 'a')
            {
                arrayOfKey[i] -= 97;
            }
        }

        // ciphertext results
        printf("ciphertext: ");
        for (int i = 0; i < strlen(s); i++)
        {
            // filtering out only alphabetic letters
            for (int j = 0; j < strlen(key); j++)
            {
                int newCharacter = (int) s[i] + arrayOfKey[j];
                if (isalpha(s[i]))
                {
                    // checking if newcharacter turns into a weird character. if so, need to loop it through
                    if (s[i] >= 'A' && s[i] <= 'Z' )
                    {
                        // filters only if the original string letter is a uppercase character
                        if (newCharacter > 'Z' || newCharacter < 'A')
                        {
                            newCharacter = (int) 'A' + ((newCharacter % 'Z') - 1);
                        }
                    }
                    else if (s[i] >= 'a' && s[i] <= 'z')
                    {
                        // filters only if the original string letter is a lowercase character
                        if (newCharacter > 'z' || newCharacter < 'a')
                        {
                            newCharacter = (int) 'a' + ((newCharacter % 'z') - 1);
                            //printf("newCharacter is %i\n", newCharacter);
                        }
                    }
                }
                // not alphabetic characters; sets the newCharacter int and moves J back so it doesnt count non-alphabet letters
                else
                {
                    newCharacter = s[i];
                    j = j - 1;
                }

                // when the loop reaches the end of the plaintext string
                if (i == (strlen(s) - 1))
                {
                    printf("%c\n",  newCharacter);
                    return 0;
                }
                // when the loop reaches the end of the key turned into numbers, should loop it back to 0.
                // for now, setting j = -1 cause it needs to j++ at the start of the new loop
                else if (j == (strlen(key) - 1))
                {
                    printf("%c",  newCharacter);
                    j = -1;
                    i++;
                }
                // when its not at the end of a string, or at the end of the key array
                else
                {
                    printf("%c",  newCharacter);
                    i++;
                }
            }
        }
    }
    else
    {
        printf("Error, wrong number of arguments");
        return 1;
    }
}