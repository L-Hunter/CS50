# include <stdio.h>
# include <cs50.h>

int main (void)
{
    printf("Minutes: ");
    int m = get_int();
    int b = m * 12;
    printf("Bottles: %i\n", b);
}