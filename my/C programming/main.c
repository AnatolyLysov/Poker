#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    if (scanf("%d", &x) != 1) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    printf("%d",x);
    return 0;
}
