#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    char ch = 'a';
    setlocale(LC_ALL, "Russian.UTF-8");
    printf("Привет мир! %c\n", ch);
    return 0;
}
