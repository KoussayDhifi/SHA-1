#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "../include/functions.h"
#include "../include/logicalOperators.h"
#include "../include/decode.h"
#include "../include/encode.h"

#define WORDSIZE 32
#define BLOCKSIZE 512
#define ZERO 0
#define ITERATIONS 80
#define NUMBEROFSHIFTS 1




void leftShift(int* x, int n, int* res) {
  
  for (int i = n; i<WORDSIZE+n; i++) {
    if (i < WORDSIZE) {
    *(res + (i-n) ) = *(x + i); 
    
    }else {
      
      *(res + (i-n)) = ZERO;

    }
  }

}


void rightShift(int* x, int n, int* res) {

  for (int i = 0; i<WORDSIZE; i++) {
    
    if (i < n) {
      *(res + i) = ZERO;
    
    }else {
      
      *(res + i) = *(x + i);
    

    }
  }
}




void ROTL (int* x, int n, int* res) {
  
  int* xLeftShifted = (int*) malloc(WORDSIZE * sizeof(int));
  leftShift(x, n, xLeftShifted);
  
  printf("left: \n");
  

  int* xRightShifted = (int*) malloc(WORDSIZE * sizeof(int));
  rightShift(x, WORDSIZE - n, xRightShifted);
  
  int* leftOrRight = logicalOR(xLeftShifted, xRightShifted);

  for (int i = 0; i<WORDSIZE; i++) {
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

  for (int i = 0; i<WORDSIZE; i++) {
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

  for (int i = 0; i<WORDSIZE; i++) {
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
  
  
  for (int i = 0; i<WORDSIZE; i++) {
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
  
  uintmax_t X = binary2Number(x, WORDSIZE);
  uintmax_t Y = binary2Number(y, WORDSIZE);
  
  uintmax_t Z = (X + Y) % (1ULL << w);
  
  
  
  number2Binary(Z, res, WORDSIZE);

}



/*
   The function blockDivider extracts
   The t-th word in the block of number numberOfBlock from paddedMsg
   and that word is stored in the int* res
*/
void blockDivider (int* paddedMsg, int* res, int t, int numberOfBlock) {
  
  int startingOfBlock = (numberOfBlock-1)*BLOCKSIZE;
  int block[BLOCKSIZE];

  for (int i = startingOfBlock; i<startingOfBlock+BLOCKSIZE; i++) {
    *(block + (i-startingOfBlock)) = *(paddedMsg + i);
  }
  
  int startingOfWord = t * WORDSIZE;

  for (int i = startingOfWord; i<startingOfWord+WORDSIZE; i++) {
    *(res + (i-startingOfWord)) = *(block + i);
  }

}


void messageScheduler (int* paddedMsg, int* res, int t, int n) {
  
  if (paddedMsg == NULL | res == NULL) printf("INVALID");

  static int wCache [ITERATIONS][WORDSIZE];
   
  if (t >= 0 && t <= 15) {

    blockDivider(paddedMsg, res, t, n);
    
    for (int i = 0; i<WORDSIZE; i++) {
      wCache[t][i] = res[i];
    }

  }else {
   
    
    int* XorOne = logicalXOR(wCache[t-3], wCache[t-8]);
    int* XorTwo = logicalXOR(wCache[t-14], wCache[t-16]);
    int* finalXOR = logicalXOR(XorOne, XorTwo);
   

    ROTL(finalXOR, NUMBEROFSHIFTS, res);
    
    free (XorOne);
    free (XorTwo);
    free (finalXOR);
  }


}


void copyArray (int* sourceArray, int* destArray, int length) {


  for (int i = 0; i<length; i++) {

    * (destArray + i) = * (sourceArray + i);

  }

}


