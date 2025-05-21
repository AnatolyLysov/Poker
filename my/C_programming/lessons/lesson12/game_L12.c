#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
        int x = 10, y = 5;// initial position of dog: '@'
        int key;
        int cx, cy; // cursor position
        int ax = 5, ay = 3; // initial position of apple: '*'

        srand(time(NULL)); // seed for random number generation
        // Randomly place the apple in the array
        ax = rand() % 18 + 1; // random x position for apple
        ay = rand() % 8 + 1; // random y position for apple
        
        // Initialize the ncurses library 
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
            mas[ay][ax] = '*';

            clear();
            for (int i = 0; i < 10; i++) {
                printw("%s\n", mas[i]);
            }
            refresh();

            cx = x;
            cy = y;

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
            if(mas[y][x] == '#') {
                x = cx;
                y = cy;
            }
            if(mas[y][x] == '*') {
                // Apple collected
                ax = rand() % 18 + 1;
                ay = rand() % 8 + 1;
            }
        } while (key != 'q');

        endwin();
        return 0;
    }

