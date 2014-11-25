#include <stdlib.h>
#include <stdio.h>

int divideEvenly(int currentCount, int grandNumber){
  if (grandNumber % currentCount == 0){
    return 1;
  }
  return 0;
}

int isPerfect(int n){
  int divisor;
  int perfectSum = 1;
  if (n < 3){
    return 0;
  }
  for (int i=2; i < n; i++){
    divisor = divideEvenly(i, n);
    if (divisor == 1){
      perfectSum = perfectSum + i;
    }
  }
  if (perfectSum == n){
    return 1;
  }
  return 0;
}

int main(void){
  int perfectCheck;
  for (int i=1; i < 10000; i++){
    perfectCheck = isPerfect(i);
    if (perfectCheck == 1){
      printf("%d is perfect!\n", i);
    }
  }
  return EXIT_SUCCESS;
}
