#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countString(char * str){ //returns string count not including the null character
  const char * pointCounter = strrchr(str, '\0');
  long int stringLength = pointCounter - str;
  return stringLength;
}

void reverse(char * str) {
  int stringLength=countString(str);
  int backward = stringLength-1; //used to count backward
  char strHolder[stringLength];
  for (int i = 0; i < ((stringLength+1)/2); i++){
    strHolder[i]=str[i];
    str[i]= str[backward];
    str[backward]=strHolder[i];
    backward-- ;
  }
  return;
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
