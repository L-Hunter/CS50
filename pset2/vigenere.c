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
        string k = argv[1];
        int kLen = strlen(k);
        
        for (int x = 0; x < kLen; x++)
        {
            if (isalpha(k[x]) == false)
            {
                printf("ERROR");
                return 1;
            }
        }
        
        printf("plaintext: ");
        string p = get_string();
        int pLen = strlen(p);
        
        printf("ciphertext:");
        for (int i = 0, j = 0; i < pLen; i++)
        {
            char key = k[(j) % kLen];
            if (isalpha(p[i]))
            {
                if (isupper(key)){
                    key -= 65;
                }
                else if (islower(key)){
                    key -= 97;
                }
                if (isupper(p[i]))
                {
                    char c = (((p[i] + key) -65) % 26) + 65;
                    printf("%c", c);
                    j++;
                }
                else
                {
                    char c = (((p[i] + key) -97) % 26) + 97;
                    printf("%c", c);
                    j++;
                }
            }
            else
            {
                printf("%c", p[i]);
            }
        } 
        printf("\n");
        return 0;
    }
}