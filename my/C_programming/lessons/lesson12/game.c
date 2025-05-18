#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Create a 2D array of characters
    // with 10 rows and 21 columns
    // The first and last rows and columns will be filled with '#'
    // and the rest will be filled with spaces
    // The last column of each row will be a null terminator
    // to make it a string
    // The array will be filled with '#' and ' ' characters
    // The array will be printed to the console
    char mas[10][21];

    for (int i = 0; i < 10; i++)
    {
       for (int j = 0; j < 20; j++)
       {
           if (j == 0 || j == 19 || i == 0 || i == 9) // border
               mas[i][j] = '#';
           else // inside
               mas[i][j] = ' ';
        }
    }
    for (int i = 0; i < 10; i++)
    {
       mas[i][20] = '\0';// end of string
       printf("%s\n", mas[i]);// print each row
    }
  // Free the allocated memory      
    return 0;
}