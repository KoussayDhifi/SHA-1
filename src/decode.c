#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/decode.h"

void binary2Char(char* binary, char* c) {
  int power = 7;
  *c = 0;
  for (int i = 0; i<8; i++) {
    *c += (*(binary+i) == '1')? (1 << power) : 0;
    power--;
  }
  

}


void decode (char* codedMsg, size_t codedMsgSize,char* decodedMsg) {

  char* aux = (char*) malloc(8*sizeof(char));
  int j = 0;
  int auxCounter = 0;
  for (int i = 0; i<codedMsgSize; i++) {
   
   *(aux + auxCounter) = *(codedMsg + i);
    auxCounter++; 

    if ( (i+1) % 8 == 0) {
     
      binary2Char(aux,decodedMsg+j);
      j++;
      auxCounter = 0;
    }
      
   

  }
  free(aux);

}
