#include <stdio.h>

int menu(int);
int doItem1();
int doItem2();
int doItem3();

int main()
{
    int menuItem; 
    
    do
    {
        printf("Введите выбор пункта в виде целого числа: 1 либо 2 либо 3 или 0 для выхода ");
        scanf("%d",&menuItem);
        menu(menuItem);
    }while (menuItem != 0);
    
    return 0;
}

int menu(int menuItem){
    switch (menuItem)
    {
    case 1:
            (int)(*doItem1)();
            break;
    case 2:
            (int)(*doItem2)();
            break;
    case 3:
            (int)(*doItem3)();
    default:
            break;
    }

}

int doItem1(){
    printf("doItem1()\n");
    return 0;
}

int doItem2(){
    printf("doItem2()\n");
    return 0;
}

int doItem3(){
    printf("doItem3()\n");
    return 0;
}