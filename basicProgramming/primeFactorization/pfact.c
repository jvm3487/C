#include <stdio.h>
#include <stdlib.h>

int primeFactor(int a){
  for (int i=2; i<a; i++){
    if (a%i==0){
      return i;
    }
  }
  return 0;
}

int isPrime(int b){
  for (int i=2; i<b; i++){
    if (b%i==0){
      return 0;
    }
  }
  return 1;
}

void printFactors(int n) {
  int primeStatus = 0;
  int smallestPrime = 0;
  if (n <= 1){
    printf("\n");
    return;
  }
  primeStatus = isPrime(n);
  while (primeStatus == 0){
    smallestPrime = primeFactor(n);
    printf("%d * ",smallestPrime);
    n = n / smallestPrime;
    primeStatus = isPrime(n);
  }
  printf("%d\n",n);
  return;
}


int main(void) {
  printf("Factorization of 1:\n");
  printFactors(1);
  printf("Factorization of 60:\n");
  printFactors(60);
  printf("Factorization of 132:\n");
  printFactors(132);
  printf("Factorization of 11726:\n");
  printFactors(11726);
  printf("Factorization of 2169720:\n");
  printFactors(2169720);
  printf("Factorization of 1789220887:\n");
  printFactors(1789220887);
  return EXIT_SUCCESS;
}
