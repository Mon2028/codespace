#include <cs50.h>
#include <stdio.h>

void build(int n);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    build(height);
}

void build(int n)
{
    for (int x = 1; x < (n + 1); x++)
    {
        for (int y = 1; y < (n + 1); y++)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
        printf("\n");
    }
}