#include <cs50.h>

#include <stdio.h>

int main(void)

{

    int i;

    do

    {

        i = get_int("Start population: ");

    }

    while (i < 9);

    int j;

    do

    {

        j = get_int("End population: ");

    }

    while (j < i);

    int years = 0;

    while (i < j)

    {

        i = i + (i / 3) - (i / 4);

        years++;

    }

    printf("Years: %d\n", years);

}