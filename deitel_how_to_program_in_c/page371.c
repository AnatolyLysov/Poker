#include <stdio.h>


int main(){
    char *ptr = {"Hello world!"};
    printf("%p\n", ptr);
    while (*ptr !='\0')
    {
        printf("%c\n",*ptr);
        ptr++;
    }
    return 0;
}
 