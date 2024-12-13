#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "../include/functions.h"
#include "../include/logicalOperators.h"
#include "../include/decode.h"
#include "../include/encode.h"

#define BLOCKSIZE 32
#define ZERO 0





void leftShift(int* x, int n, int* res) {
  
  for (int i = n; i<BLOCKSIZE+n; i++) {
    if (i < BLOCKSIZE) {
    *(res + (i-n) ) = *(x + i); 
    
    }else {
      
      *(res + (i-n)) = ZERO;

    }
  }

}


void rightShift(int* x, int n, int* res) {

  for (int i = 0; i<BLOCKSIZE; i++) {
    
    if (i < n) {
      *(res + i) = ZERO;
    
    }else {
      
      *(res + i) = *(x + i);
    

    }
  }
}




void ROTL (int* x, int n, int* res) {
  
  int* xLeftShifted = (int*) malloc(BLOCKSIZE * sizeof(int));
  leftShift(x, n, xLeftShifted);
  
  printf("left: \n");
  

  int* xRightShifted = (int*) malloc(BLOCKSIZE * sizeof(int));
  rightShift(x, BLOCKSIZE - n, xRightShifted);
  
  int* leftOrRight = logicalOR(xLeftShifted, xRightShifted);

  for (int i = 0; i<BLOCKSIZE; i++) {
    *(res + i) = *(leftOrRight + i);
  }
  

  free (leftOrRight);
  free (xRightShifted);
  free (xLeftShifted);

} 


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



void modulusAddition (int* x, int* y, int* res, int w) {
  
  uintmax_t X = binary2Number(x, BLOCKSIZE);
  uintmax_t Y = binary2Number(y, BLOCKSIZE);
  
  uintmax_t Z = (X + Y) % (1ULL << w);
  
  
  
  number2Binary(Z, res, BLOCKSIZE);

}


