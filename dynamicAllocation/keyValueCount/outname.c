#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char * newFile = malloc(sizeof(char));
  int i = 0;
  while (inputName[i] != '\0'){
    newFile = realloc(newFile,(i+1)*sizeof(char));
    newFile[i] = inputName[i];
    i++;
  }
  newFile = realloc(newFile,(i+8)*sizeof(char));
  newFile[i] = '.';
  newFile[i+1] = 'c';
  newFile[i+2] = 'o';
  newFile[i+3] = 'u';
  newFile[i+4] = 'n';
  newFile[i+5] = 't';
  newFile[i+6] = 's';
  newFile[i+7] = '\0';
  return newFile;
}

