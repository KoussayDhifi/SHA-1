#include <stdio.h>
#include "../include/logicalOperators.h"


#define BLOCKSIZE 32

int* logicalNOT (int* binray) {
    
  int result[BLOCKSIZE];

  for (int i = 0; i<BLOCKSIZE; i++) {
    *(result + i) = ! *(binray + i);
  }
  return result;
}


int* logicalAND (int* x, int* y) {
    
  int result[BLOCKSIZE];
  
  for (int i = 0; i<BLOCKSIZE; i++) {
    *(result + i) = *(x + i) & *(y + i);
  }

  return result;
}


int* logicalXOR (int* x, int* y) {
    
  int result[BLOCKSIZE];
  
  for (int i = 0; i<BLOCKSIZE; i++) {
    *(result + i) = *(x + i) ^ *(y + i);
  }
  
  return result;

}
