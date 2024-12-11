#include <stdio.h>
#include <stdlib.h>
#include "../include/functions.h"
#include "../include/logicalOperators.h"

#define BLOCKSIZE 32

void CH (int* x, int* y, int* z, int* res) {

  int* logicalAnd = logicalAND(x,y);
  int* not = logicalNOT(x);
  int* logicalAndTwo = logicalAND(not, z);

  int* logicalxor = logicalXOR(logicalAnd, logicalAndTwo);

  for (int i = 0; i<BLOCKSIZE; i++) {
    *(res + i) = *(logicalxor + i); 
  }
  

  free(logicalxor);
  free (logicalAndTwo);
  free (logicalAnd);
  free (not);

}

void PARITY (int* x, int* y, int* z, int* res) {
  int* logicalxor = logicalXOR(x,y);

  int* logicalxorTwo = logicalXOR(logicalxor, z);

  for (int i = 0; i<BLOCKSIZE; i++) {
    *(res + i) = *(logicalxorTwo + i);
  }
  
  free (logicalxorTwo);
  free (logicalxor);
  
}

void MAJ (int* x, int* y, int* z, int* res) {

  int* logicalAndOne = logicalAND(x,y);
  int* logicalAndTwo = logicalAND(x,z);
  int* logicalAndThree = logicalAND(y,z);
  int* logicalxor = logicalXOR(logicalAndOne, logicalAndTwo);
  int* logicalxorTwo = logicalXOR( logicalXOR( logicalAND(x,y), logicalAND(x,z) ), logicalAND(y,z) );
  
  
  for (int i = 0; i<BLOCKSIZE; i++) {
    *(res + i) = *(logicalxorTwo + i);
  }

  free (logicalxorTwo);
  free(logicalxor);
  free (logicalAndOne);
  free (logicalAndTwo);
  free (logicalAndThree);

}


void functions (int* x, int* y, int* z, int t, int* res) {
    
    if (t >= 0 && t <= 19) {
      CH(x, y, z, res);
    }else if ( (t >= 20 && t <= 39) || ( t >= 60 && t <= 79) ) {
      PARITY(x, y, z, res);
    }else if (t >= 40 && t <= 59) {
      MAJ(x, y, z, res);
    }else {
    printf("PLEASE ENTER A VALID RANGE t in [0 .. 80[");
    exit(EXIT_FAILURE);
  }


}


