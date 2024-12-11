#include <stdio.h>
#include <stdlib.h>
#include "../include/functions.h"
#include "../include/logicalOperators.h"

#define BLOCKSIZE 32

void CH (int* x, int* y, int* z, int* res) {
  res = logicalXOR(logicalAND(x,y), logicalAND(logicalNOT(x), z));
}

void PARITY (int* x, int* y, int* z, int* res) {
  res = logicalXOR(logicalXOR(x,y), z);
}

void MAJ (int* x, int* y, int* z, int* res) {
  res = logicalXOR( logicalXOR( logicalAND(x,y), logicalAND(x,z) ), logicalAND(y,z) );
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


