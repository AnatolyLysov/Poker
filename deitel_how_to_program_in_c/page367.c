#include <stdio.h>
  int f (int);
 

int main(){
   int foo(int x){
    return 0;
   }
   int (*)(int) fooPtr = foo;
   printf("%p",fooPtr);
   return 0;
}

