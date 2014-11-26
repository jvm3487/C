#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t * countArray = malloc(sizeof(counts_t));
  countArray->ArrayLength = 0;
  countArray->unknownCount = 0;
  countArray->array = malloc(sizeof(one_count_t*));
  return countArray;

}
void storeNew (counts_t *countArray, const char * name){
  countArray->ArrayLength++;
  countArray->array = realloc(countArray->array, (countArray->ArrayLength)*sizeof(one_count_t*));
  countArray->array[(countArray->ArrayLength)-1] = malloc(sizeof(one_count_t));
  countArray->array[(countArray->ArrayLength)-1]->countName = name;
  countArray->array[(countArray->ArrayLength)-1]->countNumber = 1;
  return;
}

void addCount(counts_t * c, const char * name) {
  if (c->ArrayLength == 0 && name != NULL){
    storeNew(c, name);
    return;
  }
  else{
    if (name == NULL){
      c->unknownCount++;
    }
    else{
      int writeOccur = 0;
      for (int i=0; i < c->ArrayLength; i++){
	if (strcmp(name,c->array[i]->countName)==0){
	  c->array[i]->countNumber++;
	  writeOccur = 1;
	} 
      }
      if (writeOccur == 0){
	storeNew(c, name);
      }
    }
  }
  return;
}

void printCounts(counts_t * c, FILE * outFile) {
  for(int i=0; i < c->ArrayLength; i++){
    fprintf(outFile, "%s: %d\n", c->array[i]->countName, c->array[i]->countNumber);
  }
  if (c->unknownCount != 0){
    fprintf(outFile, "<unknown>: %d\n", c->unknownCount);
  }
  return;
}

void freeCounts(counts_t * c) {
  for(int i =0; i < c->ArrayLength; i++){
    free(c->array[i]);
  }
  free(c->array);
  free(c);
  return;
}
