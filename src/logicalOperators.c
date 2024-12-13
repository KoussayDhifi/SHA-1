#include <stdio.h>
#include <stdlib.h>
#include "../include/logicalOperators.h"


#define BLOCKSIZE 32
#define DECLARE(result) int* result = NULL;
#define ALLOCATE(result)  \
result = (int*) malloc(BLOCKSIZE * sizeof(int)); \
if (result == NULL) { \
  fprintf(stderr, "Failed to allocate memory, aborting ... \n"); \
  exit(EXIT_FAILURE); \
  } \


int* logicalNOT (int* binray) {
    
  DECLARE(result);
  ALLOCATE (result);

  for (int i = 0; i<BLOCKSIZE; i++) {
    *(result + i) = ! *(binray + i);
  }
  return result;
}


int* logicalAND (int* x, int* y) {
    
  DECLARE(result);
  ALLOCATE (result);
  
  for (int i = 0; i<BLOCKSIZE; i++) {
    *(result + i) = *(x + i) & *(y + i);
  }

  return result;
}


int* logicalXOR (int* x, int* y) {
    
  DECLARE(result);
  ALLOCATE (result);
  
  
  for (int i = 0; i<BLOCKSIZE; i++) {
    *(result + i) = *(x + i) ^ *(y + i);
  }
  
  return result;

}

int* logicalOR (int* x, int* y) {
  DECLARE(result);
  ALLOCATE(result);
  
  for (int i = 0; i<BLOCKSIZE; i++) {

  *(result + i) = *(x + i) | *(y + i);
  }

  return result;

}




