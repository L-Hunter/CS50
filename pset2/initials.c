# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main (void)
{
    // printf("Hi! What's your name?\n");
    string s = get_string();
    const char space[2] = " ";
    char *token;
    token = strtok(s, space);
    while( token != NULL ) 
    {
      printf( "%c", toupper(token[0]));
      token = strtok(NULL, space);
    }
    printf("\n");
}