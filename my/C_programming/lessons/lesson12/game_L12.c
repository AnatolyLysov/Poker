#include <stdio.h>
#include <stdlib.h>
    /*
        * This program creates a 10x20 array of characters and fills it with a border of '#' characters.
        * The player can move a character '@' around the array using the 'w', 'a', 's', and 'd' keys.
        * The program ends when the player presses 'q'.
        *
        * The program uses the ncurses library for handling keyboard input and screen output.
        * The array is displayed on the screen, and the player can move the '@' character around.
        * The program ensures that the player stays within the bounds of the array.
        * The screen is cleared and redrawn after each move.
        *
        * To compile:
        * gcc -Wall -g -o game_L12 game_L12.c -lncurses
        * To run:
        * ./game_L12
        *
        * Note: Make sure to install the ncurses library if it's not already installed on your system.
        * You can install it using the package manager of your Linux distribution.
        * For example, on Ubuntu, you can use:
        * sudo apt-get install libncurses5-dev
        *
        * This program is a simple demonstration of using arrays and keyboard input in C.
        * It can be extended to create more complex games or applications.
        * The program uses a 2D array to represent the game board, with '#' characters for walls and ' ' for empty spaces.
        * The player can move the '@' character around the board using the 'w', 'a', 's', and 'd' keys.
        * The program uses the ncurses library to handle keyboard input and screen output.
        * The program is designed to be simple and easy to understand, making it a good starting point
        * for learning about C programming and game development.
        * The program uses a 2D array to represent the game board, with '#' characters for walls and ' ' for empty spaces.
        * The player can move the '@' character around the board using the 'w', 'a', 's', and 'd' keys.
        * The program uses the ncurses library to handle keyboard input and screen output.
        * The program is designed to run in a terminal window, and it uses the ncurses library to create 
        * a simple text-based user interface.
        * The program is a simple demonstration of using arrays and keyboard input in C.
        * It can be extended to create more complex games or applications.
        * The program run in Linux environment (for example github codespaces My comment).
    */

    #include <ncurses.h>

    int main(void)
    {
        char mas[10][21];
        int x = 10, y = 5;
        int key;
        int cx, cy; // cursor position

        initscr();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);

        do {
            sprintf(mas[0], "####################");
            for (int i = 1; i < 9; i++) {
                sprintf(mas[i], "#                  #");
            }
            sprintf(mas[9], "####################");

            mas[y][x] = '@';

            clear();
            for (int i = 0; i < 10; i++) {
                printw("%s\n", mas[i]);
            }
            refresh();

            key = getch();

            if (key == 'w') {
                mas[y][x] = ' ';
                y--;
            } else if (key == 's') {
                mas[y][x] = ' ';
                y++;
            } else if (key == 'a') {
                mas[y][x] = ' ';
                x--;
            } else if (key == 'd') {
                mas[y][x] = ' ';
                x++;
            }

            if (x < 1) x = 1;
            if (x > 18) x = 18;
            if (y < 1) y = 1;
            if (y > 8) y = 8;

        } while (key != 'q');

        endwin();
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