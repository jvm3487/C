#include <stdlib.h>
#include <stdio.h>

int fib(int n){
  int secondPrev = 0;
  int firstPrev = 1;
  int fibNumber = 0;
  if (n <= 1){
    if (n <= 0){
      return fibNumber;
    }
    else{
      return 1;
    }
  }
  for (int i=0; n > (i+1); i++){
    fibNumber = secondPrev + firstPrev;
    secondPrev = firstPrev;
    firstPrev = fibNumber;
  }
  return fibNumber;
}

int main(void){
  int dis = 0;
  for (int i = -2; i<31; i++){
    dis = fib(i);
    printf("fib(%d) = %d\n",i,dis);
  }
  return EXIT_SUCCESS;
}
      
