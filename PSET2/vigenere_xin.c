#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

bool charIsCapital(char c)
{
    return (c - 'a') < 0;
}

int main(int argc, string argv[])
{
    // Error checking
    if (argc != 2)
    {
        printf("Unexpected number of command-line arguments. Expected 2, got %d instead.", argc);
        return 1;
    }

    char* keyword = argv[1];
    const size_t keywordLen = strlen(argv[1]);

    for (size_t i = 0; i < keywordLen; ++i)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Keyword needs to be alphabetical.");
            return 1;
        }
        else
        {
            // Convert letter to number.
            keyword[i] = charIsCapital(keyword[i]) ? keyword[i] - 'A' : keyword[i] - 'a';
        }
    }

    printf("plaintext: ");
    char* plaintext = get_string();
    const size_t plaintextLen = strlen(plaintext);

    size_t keywordCursor = 0;
    for (size_t i = 0; i < plaintextLen; ++i)
    {
        if (isalpha(plaintext[i]))
        {
            const int offset = charIsCapital(plaintext[i]) ? 'A' : 'a';

            // Handle wraparound.
            plaintext[i] = ((plaintext[i] + keyword[keywordCursor] - offset) % 26) + offset;
            keywordCursor = (keywordCursor + 1) % keywordLen;
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}