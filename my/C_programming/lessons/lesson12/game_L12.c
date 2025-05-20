#include <stdio.h>
#include <stdlib.h>

int main(void)
    {
        // This program creates a 10x20 array of characters and fills it with a border of '#' characters.
        char mas[10][21];
        int x = 10, y = 5;
        char key;
do{
            // Fill the borders and empty space
            sprintf(mas[0], "####################");

            for (int i = 1; i < 9; i++) {
                sprintf(mas[i], "#                  #");
            }

            sprintf(mas[9], "####################");

            // Place the player character '@' at the current position
            mas[y][x] = '@';

            // Print the array
            for (int i = 0; i < 10; i++) {
                printf("%s\n", mas[i]);
            }

            key = getchar();

            // Remove the player character from the current position
            //mas[y][x] = ' ';

             if (key == 'w') {
                y--;
            } else if (key == 's') {
                y++;
            } else if (key == 'a') {
                x--;
            } else if (key == 'd') {
                x++;
            }
            // Ensure the player stays within bounds
            if (x < 1) x = 1;
            if (x > 18) x = 18;
            if (y < 1) y = 1;
            if (y > 8) y = 8; 
            // Clear the input buffer
            //while (getchar() != '\n');
            // Clear the screen
            //printf("\033[H\033[J");
            for (int i = 1; i < 9; i++) {
                sprintf(mas[i], "#                  #");
            }


}
while(getchar() != 'q'); // Continue until 'q' is pressed

        // Free the allocated memory
        //free(mas);
        // Return success
        //return 0;
    return 0;
    }
/*You are getting two errors:
1.	Implicit declaration of function ‘getch’:
The compiler does not know about the getch() function because its declaration is missing or the required header is not included.
2.	Undefined reference to ‘getch’:
The linker cannot find the implementation of getch(). On Linux, getch() is not part of the standard C library. It is available in conio.h (which is for DOS/Windows), but not on Linux.
Solution:
On Linux, you can use getchar() instead of getch(), or use libraries like ncurses for similar functionality.
To use getchar(), replace getch() with getchar() in your code.
If you need getch()-like behavior (no Enter key required), install and use ncurses:
sudo apt-get install libncurses5-dev
gcc -Wall -g -o game_L12 game_L12.c -lncurses
•	
•	
•	
Replace getch() with getch() from ncurses and include <ncurses.h> in your code.
Text to replace:
•	{getch}: Replace with getchar() or use ncurses's getch()
•	{#include <conio.h>}: Replace with #include <ncurses.h> if using ncurses
*/