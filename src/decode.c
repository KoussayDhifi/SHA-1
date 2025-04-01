#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "../include/decode.h"

#define LENGTHOFCONVERSION 4

uintmax_t binary2Number (int* x, int n) {
  int power = n-1;
  uintmax_t res = 0;
  

    for (int i = 0; i<n; i++) {
    
    res += (*(x + i))? (1 << power) : 0;
    power--;
  }
  

  return res;

}

char decimal2Hex (int decimal) {
  
  if (decimal < 10) {
    return '0' + decimal;
  }else {
    return 'a' + (decimal - 10);
  }


}

void binary2Hex (int* binaryArray, int lengthOfBinaryArray, char* hexConv,int lengthOfHex) {

  int aux [LENGTHOFCONVERSION];
  int j = 0;
  int hexCounter = lengthOfHex - 1;
  for (int i = lengthOfBinaryArray - 1; i >= 0; i--) {
    aux [LENGTHOFCONVERSION - 1 - j++] = * (binaryArray + i);
    if (i % 4 == 0) {
      int decimalValue = binary2Number (aux, LENGTHOFCONVERSION);
      *(hexConv + hexCounter--) = decimal2Hex(decimalValue);
      j = 0;
    }
  }

}

void binary2Char(int* binary, char* c) {
  int power = 7;
  *c = 0;
  for (int i = 0; i<8; i++) {
    *c += (*(binary+i))? (1 << power) : 0;
    power--;
  }
  

}


void decode (int* codedMsg, size_t codedMsgSize,char* decodedMsg) {

  int aux[8];
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
  //free(aux);

}
