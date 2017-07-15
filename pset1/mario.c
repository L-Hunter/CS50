# include <cs50.h>
# include <stdio.h>

void mario(int);

int main(void)
{
    int h;
    
    do 
    {
        printf("Height: ");
        h = get_int();
    }
    while (h < 0 || h > 23);
    mario(h);
}

void mario(int h)
{
    string s = " ";
    string p = "#";
    int hash = 1;
    int spaces = h - 1;
    for (int i = 0; i < h; i++)
    {
        for (int r = spaces; r > 0; r--)
        {
            printf("%s", s);
        }
        hash += 1;
        for (int j = 0; j < hash; j++)
        {
            printf("%s", p);
        }
        printf("\n");
        spaces -= 1;  
    }
}