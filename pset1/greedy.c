# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main (void) 
{
    float n;
    
    do
    {
    printf("O hai! How much change is owed?\n");
    n = get_float();
    int cents = (int) round(n * 100);;
    int coins = 0;

        while (cents >= 25)
        {
            cents -= 25;
            coins += 1;
        }
        while (cents >= 10)
        {
            cents -= 10;
            coins += 1;
        } 
        while (cents >= 5)
        {
            cents -= 5;
            coins += 1;
        }
        while (cents >= 1)
        {
            cents -= 1;
            coins += 1;
        }
    printf("%i\n", coins);
    }
    while (n < 0);
}
