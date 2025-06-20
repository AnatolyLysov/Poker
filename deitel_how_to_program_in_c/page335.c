//intialize suit
//intialize rank
//intialize card
//intialize deck
//intialize player
//intialize computer
/* int suit = 0; // 0 for hearts, 1 for diamonds, 2 for clubs, 3 for spades
int rank = 0; // 0 to 12 for Ace to King
int card = 0; // Represents a single card in the deck
int deck[52]; // Array to hold the deck of cards
int player = 0; // Represents the player, could be an ID or index
int computer = 0; // Represents the computer, could be an ID or index
 */

#include <stdio.h>

int main() {
    char * suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char * face[] = {"Ace", "Deuce", "Three", "Fours", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int desk[4][13] = {0};
    int offset;
    for (offset = 0; offset <= 3; offset++)
    {
        printf("%s\n", *(suit + offset));
    }
    
    printf("\n");

    for (offset = 0; offset <= 12; offset++)
    {
        printf("%s\n", *(face + offset));
    }

}