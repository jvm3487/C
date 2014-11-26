#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
  for (int i=0; i < count; i++){
    printf("%s", data[i]);
  }
}

void countFileLines(FILE * f){
  char * line = NULL;
  size_t bytes = 0;
  int counter = 0;
  char ** lineArray = malloc((counter+1)*sizeof(char*));
  while (getline(&line, &bytes, f) != EOF){
    lineArray = realloc(lineArray, (counter+1)*sizeof(char*));
    lineArray[counter] = line;
    line = NULL;
    counter++;
  }
  if (counter == 0){
    fprintf(stderr, "Please input a file that is not empty.\n");
    exit (EXIT_FAILURE);
  }
  sortData(lineArray, counter);
  for(int i=0; i<counter; i++){
    free(lineArray[i]);
  }
  free(lineArray);
  free(line);
  return;
}

int main(int argc, char ** argv) {
  if  (argc==1){
    countFileLines(stdin);
  }
  if (argc>1){
    FILE * f;
    for (int i = 1; i < argc; i++){
      f  = fopen(argv[i], "r" );
      if (f == NULL){
	fprintf(stderr, "This is not a valid file!\n");
	exit (EXIT_FAILURE);
      }
      countFileLines(f);
      if (fclose(f) != 0){
	fprintf(stderr, "File failed to close!\n");
      }
    }
  }
  return EXIT_SUCCESS;
}
