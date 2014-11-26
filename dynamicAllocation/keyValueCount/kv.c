#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

void buildArray(kvpair_t * current, int counter, kvarray_t * myArray){
  myArray->array = realloc(myArray->array, (counter+1)*sizeof(kvpair_t *));
  myArray->array[counter] = current;
  return;
}

kvpair_t * determineKeyValue(char * line){
  kvpair_t * current;
  if (line[0] == '='){
    fprintf(stderr, "Invalid input in file!");
  }
  current = malloc(2*sizeof(char *));
  current->key = malloc(sizeof(char));
  current->key[0] = line[0];
  int i = 1;
  while (line[i] != '='){
    if (line[i] == '\n' || line[i] == EOF){
      fprintf(stderr, "Invalid input in file!");
    }
    current->key = realloc(current->key, (i+1)*sizeof(char));
    current->key[i] = line[i];
    i++;
  }
  current->key = realloc(current->key, (i+1)*sizeof(char));
  current->key[i] = '\0';
  i++;
  int j = 0;
  current->value = malloc(sizeof(char));
  while (line[i] != '\n' && line[i] != EOF){
    current->value = realloc(current->value, (j+1)*sizeof(char));
    current->value[j] = line[i];
    j++;
    i++;
  }
  current->value = realloc(current->value, (j+1)*sizeof(char));
  current->value[j] = '\0';
  return current;
} 

kvarray_t * readFileAndStore(FILE * f, kvarray_t * myArray){
  char * line = NULL;
  size_t bytes = 0;
  kvpair_t * current;
  myArray->array = malloc(sizeof(kvpair_t*));
  int counter = 0;
  while (getline(&line, &bytes, f) != EOF){
    current = determineKeyValue(line);
    buildArray(current, counter, myArray);
    counter++;
  }  
  myArray->length = counter;
  free(line);
  return myArray;
}

kvarray_t * readKVs(const char * fname) {
  FILE * f = fopen(fname, "r");
  if (f == NULL){
    fprintf(stderr, "This is not a valid file!\n");
  }
  kvarray_t * myArray = malloc(sizeof(kvarray_t));
  myArray = readFileAndStore(f, myArray);
  if (fclose(f) != 0){
    fprintf(stderr, "File failed to close!\n");
  }
  return myArray;
}

void freeKVs(kvarray_t * pairs) {
  for(int i=0; i < pairs->length; i++){
    free(pairs->array[i]->key);
    free(pairs->array[i]->value);
    free(pairs->array[i]);
  }
  free(pairs->array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  for (int i = 0; i < pairs->length; i++){
    printf("key = '%s' value = '%s'\n", pairs->array[i]->key, pairs->array[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for (int i = 0; i < pairs->length; i++){
    if (strcmp(pairs->array[i]->key, key) == 0){
      return pairs->array[i]->value;
    } 
  }
  return NULL;
}
