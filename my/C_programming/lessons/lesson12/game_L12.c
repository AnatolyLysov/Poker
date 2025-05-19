#include <stdio.h>

int main(void)
    {
        // This program creates a 10x20 array of characters and fills it with a border of '#' characters.   
        char mas[10][21];
        int x = 10, y = 5;
         
        sprintf(mas[0], "####################");

        for (int i = 1; i < 9; i++) {
            sprintf(mas[i], "#                  #");
        }

        sprintf(mas[9], "####################");
    
        mas[y][x] = '@';
    
        // Print the array
        for (int i = 0; i < 10; i++) {
            printf("%s\n", mas[i]);
        }
        return 0;
    }
