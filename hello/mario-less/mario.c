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