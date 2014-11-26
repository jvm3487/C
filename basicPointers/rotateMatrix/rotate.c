#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void properInput(FILE * f){
  int c = 0;
  int lineCounter = 0;
  int characterCounter = 0;
  while (c != EOF && lineCounter != 10){
    characterCounter = 0;
    while ((c = fgetc(f)) != '\n' && c != EOF){
      characterCounter++;
    }
    if (characterCounter != 10){
      fprintf(stderr, "File does not contain a valid 10x10 Matrix.\n");
      exit (EXIT_FAILURE);
    }
    lineCounter++;
  }
  rewind(f);
  return;
}

void initializeMatrix(char matrix [][10], FILE * f){
  for (int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      matrix[i][j]=fgetc(f);
      if (matrix[i][j] == '\n'){
	matrix[i][j] = fgetc(f);
      }
    }
  }
}

void printNinetyDegree(char matrix [][10]){
  for (int i = 0; i < 10; i++){
    for (int j = 9; j > -1; j--){
      printf("%c",matrix[j][i]);
    }
    printf("\n");
  }
}

int main(int argc, char ** argv){
  if (argc != 2){
    fprintf(stderr, "Please enter one file only.\n");
    exit (EXIT_FAILURE);
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    fprintf(stderr, "Please enter a valid input file.\n");
    exit (EXIT_FAILURE);
  }
  properInput(f);
  char matrix[10][10];
  initializeMatrix(matrix,f);
  printNinetyDegree(matrix);
  if (fclose(f) != 0){
    fprintf(stderr, "Failed to close file.\n");
    exit (EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
