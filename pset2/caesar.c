# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

int main (int argc, string argv[])
{
    if (argc != 2)
        {
            printf("ERROR");
            return 1;
        }
    else
    {
        int i = atoi(argv[1]);

        printf("plaintext: ");
        string plainText = get_string();

        int k = strlen(plainText);

        //loop to iterate through plaintext and rotate letter by i
        printf("ciphertext:");
        for (int j = 0; j < k; j++){
            if (isalpha(plainText[j]))
            {
                if (isupper(plainText[j]))
                {
                    printf("%c", (((plainText[j] + i) -65) % 26) + 65);
                }
                else
                {
                    printf("%c", (((plainText[j] + i) - 97) % 26) + 97);
                }
            }
            else
            {
                printf("%c", plainText[j]);
            }
        }
        printf("\n");
        return 0;
    }
}