#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temp_Points [] = {};


int compute_score(string word);


int main(void)
{

string word1 = get_string("Player 1: ");
string word2 = get_string("Player 2: ");


int score1 = compute_score(word1);
int score2 = compute_score(word2);

if (score1 > score2)

{

    printf("Player 1 wins\n");

}

else if (score2 > score1)

{

    printf("Player 2 wins\n");

}

else

{

    printf("Tie\n");

}

}


int compute_score(string word)
{
int score = 0;

for (int n = 0; n < strlen(word); n++)

{

if (isupper(word[n]))

{

for (int m = 0; m < sizeof(capital_letters); m++)

{

if (word[n] == capital_letters[m])

{

temp_Points[n] = POINTS[m];
score += temp_Points[n];

}

}

}

else if (islower(word[n]))

{

for (int m = 0; m < sizeof(small_letters); m++)

{

if (word[n] == small_letters[m])

{

temp_Points[n] = POINTS[m];

score += temp_Points[n];

}

}

}

else

{

n += 1;

}

}

return score;

}

