#include <stdio.h>
#include <stdlib.h>

void checkLine(char * input){
  char * checkInput = NULL;
  char * checkInput2 = NULL;
  long int firstInt = strtol (input, &checkInput, 10);
  if ((firstInt == 0) && (input[0] != 48)){
    fprintf(stderr, "Format is strictly number,number\n");
    exit (EXIT_FAILURE);  
  }
  else{
    if(checkInput[0] != ','){
      fprintf(stderr, "Format is strictly number,number\n");
      exit (EXIT_FAILURE);
    }
    else{
      long int secondInt = strtol((checkInput + 1), &checkInput2, 10);
      if ((secondInt == 0) && (checkInput[1] != 48)){
	fprintf(stderr, "Format is strictly number,number\n");
	exit (EXIT_FAILURE);
      }
      else{
	if(checkInput2[0] != '\n'){
	  fprintf(stderr, "Format is strictly number,number\n");
	  exit (EXIT_FAILURE);
	}
      }
    }
  }
  return;
}

int checkAndCountCoordinates(FILE * f, char * input, size_t bytes, int lineCount){
  if (getline(&input, &bytes, f) != EOF){
    checkLine(input);
  }
  else{
    if (lineCount != 0){
      return lineCount;
    }
    else{
      fprintf(stderr, "Format is strictly number,number\n");
    }
  }
  return checkAndCountCoordinates(f, input, bytes, lineCount+1);
}

void buildArray(int startCoor[][2], int FileLength, char * input, size_t bytes, int counter, FILE * f){
  if (getline(&input, &bytes, f) != EOF){
    if (FileLength > counter){
      char * checkInput = NULL;
      long int firstInt = strtol(input, &checkInput, 10);
      long int secondInt = strtol((checkInput + 1), &checkInput, 10);
      startCoor[counter][0] = firstInt;
      startCoor[counter][1] = secondInt;
      buildArray(startCoor, FileLength, input,  bytes, counter+1, f);
    }
  }
  return;
}

void reverseArray(int finishCoor[][2], int startCoor[][2], int FileLength, int counter){
  if (FileLength > counter){
    finishCoor[counter][0] = startCoor[FileLength-1-counter][0];
    finishCoor[counter][1] = startCoor[FileLength-1-counter][1];
    reverseArray(finishCoor, startCoor, FileLength, counter+1);
  }
  return;
}

void printDirections(int Xsum, int Ysum, int finishCoor[][2], int counter, int FileLength){
  if (FileLength > counter){
    Xsum = Xsum - finishCoor[counter][0];
    Ysum = Ysum - finishCoor[counter][1];
    printf("Go to (%d,%d)\n", Xsum, Ysum);
    printDirections(Xsum, Ysum, finishCoor, counter+1, FileLength);
  }
  else{
    printf("Food at (%d,%d)\n", Xsum, Ysum);
  }
  return;
}

int main(int argc, char ** argv) {
  if (argc != 2){
    fprintf(stderr, "Please input a valid file.\n");
    exit (EXIT_FAILURE);
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    fprintf(stderr, "Please input a valid file.\n");
    exit (EXIT_FAILURE);
  }
  char * input = NULL;
  size_t bytes = 0;
  int FileLength = checkAndCountCoordinates(f, input, bytes, 0);
  rewind(f);
  input = NULL;
  bytes = 0;
  int startCoor[FileLength][2];
  buildArray(startCoor, FileLength, input, bytes, 0, f);
  int finishCoor[FileLength][2];
  reverseArray(finishCoor, startCoor, FileLength, 0);
  printDirections(0, 0, finishCoor, 0, FileLength);
  if (fclose(f) != 0){
    fprintf(stderr, "File failed to close!\n");
    exit (EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
