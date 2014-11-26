#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

void readText(int * alphabetSoup, FILE * f){
  int c;
  while ((c = fgetc(f)) != EOF){
    if (isalpha(c)){
      c = tolower(c);
      c = c - 'a';
      c %= 26;
      alphabetSoup[c]++;
    }
  }
  return;
}

int determineLargestNum(int * alphabetSoup, int n){
  int greatestArrayElement = 0;
  int greatestArrayValue = 0;
  for (int i=0; i < n; i++){
    if (alphabetSoup[i] > greatestArrayValue){
      greatestArrayElement = i;
      greatestArrayValue = alphabetSoup[i];
    }
  }
  //following code used to check if more than one character has the greatest value (i.e. two letters of the alphabet with 10 characters each
  for (int j=0; j < n; j++){
    if (alphabetSoup[j] == alphabetSoup[greatestArrayElement] && j != greatestArrayElement){
      fprintf(stderr, "Two or more characters have an equivalent number of greatest values\n");
      exit (EXIT_FAILURE);
    } 
  }
  return greatestArrayElement;
}


int main(int argc, char ** argv){
  if (argc != 2){
    fprintf(stderr, "Please enter only one file name.\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    fprintf(stderr, "Please input a valid file.\n");
    return EXIT_FAILURE;
  }
  int alphabetSoup[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  readText(alphabetSoup, f); //reads all of the text in the file and modifies alphabetSoup in place
  int code = determineLargestNum(alphabetSoup, 26);
  code = ((code - 4) + 26)%26; //assumes greatest value is 'e'
  fprintf(stdout, "%d\n", code);
  if (fclose(f) != 0){
    fprintf(stderr, "Failed to close the input file.\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
