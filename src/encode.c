#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "../include/encode.h"
#include "../include/decode.h"
#include "../include/functions.h"

#define NUMBEROFBITS 8
#define LENGTHOFCONVERSION 4



/*int allLength (char* array, int size) {
  int res = 0;
  for (int i = 0; i<size; i++) {
    res += hexLength( *(array + i) );
  }
  return res;
}*/

void number2Binary(uintmax_t number, int* binary, int n) {
  
  for (int i = 0; i<n; i++) {
    *(binary+n-1-i) = (number % 2 == 1);
    number /= 2;
  }
  
  

}

int correspondingNumberHex (char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }else {
    return c - 'a' + 10;  
  }
}

void hex2Binary (char* hexArray, int lengthOfHex, int* binaryArray, int lengthOfBinaryArray) {
  
  int binaryFormat [LENGTHOFCONVERSION] = {0};
  int binaryArrayIndex = 0;

  for (int i = 0; i<lengthOfHex; i++) {
    int decimalNumber = correspondingNumberHex(* (hexArray + i));
    number2Binary(decimalNumber, binaryFormat, LENGTHOFCONVERSION);

    for (int j = 0; j<LENGTHOFCONVERSION; j++) {
      *(binaryArray + binaryArrayIndex ++) = * (binaryFormat + j);
    }

  }


}



void char2Binary (char c, int* res) {
  int charValue = c;
  
  for (int i = 0; i<NUMBEROFBITS; i++) {
    *(res+NUMBEROFBITS-1-i) = (charValue % 2 == 1);
    charValue /= 2;
  } 

}

/*void word2Hex (char* word, char* codedMsg, int lengthWord, int lengthCodedMsg) {
  
  int j = 0;

  for (int i = 0; i<lengthWord; i++) {

    int lengthOfHex = hexLength( *(word + i) );
    char* aux = (char*) malloc(lengthOfHex * sizeof(char));
    char2Hex (*(word + i), aux, lengthOfHex);
    printf("char[%d] = %s\n",i, aux);
    
    for (int k = 0; k<lengthOfHex; k++) {
      *(codedMsg + j) = *(aux + k);
      j++;
    }

    free(aux);

  }
    
  

}*/


void encode (char* msg, int* codedMsg) {
  
  size_t sizeMsg = strlen(msg);
  int j = 0;
  int res[NUMBEROFBITS];
  for (int i = 0; i<sizeMsg; i++) {
    
    
    char2Binary(*(msg+i), res); 
    for (int k = 0; k<NUMBEROFBITS; k++) {
      *(codedMsg + j) = *(res + k);
      j++;
    }
    
  }

  
  


}
