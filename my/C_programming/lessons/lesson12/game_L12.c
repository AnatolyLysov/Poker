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
