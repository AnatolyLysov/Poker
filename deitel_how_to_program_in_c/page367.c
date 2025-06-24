#include <stdio.h>
int foo (int);
 

int main(){
   int (*fooPtr)(int);
   fooPtr = foo;
   printf("%p\n",fooPtr);
   return 0;
}

   int foo(int x){
    return 0;
   }


