#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void help_reverse(char * str, int n){
  printf("%c", str[n-1]);
  if (n > 1){
    help_reverse(str, n-1);
  }
  return;
}

void reverse(char * str){
  int stringLength;
  if (strchr(str, '\n') != NULL){
    stringLength = (strchr(str, '\n') - str);
  }
  else{
    stringLength = strchr(str, '\0') - str;
  }
  help_reverse(str, stringLength);
  printf("\n");
  return;
}

int main(void){
  char c[500];
  while (fgets(c, 500, stdin) != NULL){
    reverse(c);
  }
  return EXIT_SUCCESS;
}
