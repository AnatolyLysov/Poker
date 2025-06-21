#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int [][13]);
void deal(const int [][13],const char *[],const char *[][]);

int main(int argc, char const *argv[])
{
    char * suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char * face[13] = {"Ace", "Deuce", "Three", "Fours", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[4][13] = {0};
    srand(time(NULL));




    return 0;
}
