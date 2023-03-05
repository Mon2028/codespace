#include <cs50.h>
#include <stdio.h>

int main(void)
{
int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize <= 9);

    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize <= startSize);

    for(int n = 1; ; n++)
    {
            int x; // current population
            x = startSize + (startSize / 3) - (startSize / 4);
            printf("%d\n", x);
    }
}
}
