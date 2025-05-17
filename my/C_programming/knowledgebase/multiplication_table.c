#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m[9][9];
    int i, j;
for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (j ==0) 
                m[i][j] = i;
            else if (i == 0)
                m[i][j] = j;
            else
                m[i][j] = m[i][0] * m[0][j];
            printf("%d \t", m[i][j] );
        }
        printf("\n");
    }
         return 0;
    }