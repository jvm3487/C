#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

long power_help(long x, long y, long product){
  product = product * x;
  if (y == 1){
    return product;
  }
  return power_help(x, y-1, product);
}

long power(long x, long y) {
  if (y < 0){
    return 0;
  }
  if (y == 0){
    return 1;
  }
  return power_help(x, y, 1);
}

int main(void) {
  char * input = NULL;
  size_t bytes = 0;
  char * checkInput = NULL;
  char * checkInput2 = NULL;
  while (getline(&input, &bytes, stdin) != EOF){
    long int firstInt = strtol(input, &checkInput, 10);
    if ((firstInt == 0) && (input[0] != 48)){
      fprintf(stderr, "Format is strictly number^number\n");
    }
    else{
      if(checkInput[0] != '^'){
	 fprintf(stderr, "Format is strictly number^number\n");
      }
      else{
	long int secondInt = strtol((checkInput + 1), &checkInput2, 10);
	if ((secondInt == 0) && (checkInput[1] != 48)){
	  fprintf(stderr, "Format is strictly number^number\n");
	}
	else{
	  if(checkInput2[0] != '\n'){
	    fprintf(stderr, "Format is strictly number^number\n");
	  }
	  else{
	    long int result = power(firstInt, secondInt);
	    printf("%ld\n", result);
	  }
	}
      }
    }
  }
  return EXIT_SUCCESS;
}
