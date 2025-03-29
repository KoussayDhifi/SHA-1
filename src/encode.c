#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../include/encode.h"
#include "../include/functions.h"

#define NUMBEROFBITS 8



int hexLength(unsigned int num) {
    return (num == 0) ? 1 : (int)(log(num) / log(16)) + 1;
}

int allLength (char* array, int size) {
  int res = 0;
  for (int i = 0; i<size; i++) {
    res += hexLength( *(array + i) );
  }
  return res;
}

void number2Binary(uintmax_t number, int* binary, int n) {
  
  for (int i = 0; i<n; i++) {
    *(binary+n-1-i) = (number % 2 == 1);
    number /= 2;
  }
  
  

}


void char2Binary (char c, int* res) {
  int charValue = c;
  
  for (int i = 0; i<NUMBEROFBITS; i++) {
    *(res+NUMBEROFBITS-1-i) = (charValue % 2 == 1);
    charValue /= 2;
  } 

}

void char2Hex (char c, char* res, int lengthResult) {
  int charValue = c;
  
  for (int i = 0; i<lengthResult; i++) {
    int remainder = charValue % 16;
    
    if (remainder < 10) {
      *(res+lengthResult-1-i) = '0' + remainder; 
    }else {
      *(res+lengthResult-1-i) = 'a' + (remainder - 10);
    }

    charValue /= 16;
  } 

}

void word2Hex (char* word, char* codedMsg, int lengthWord, int lengthCodedMsg) {
  
  int j = 0;

  for (int i = 0; i<lengthWord; i++) {

    int lengthOfHex = hexLength( *(word + i) );
    char* aux = (char*) malloc(lengthOfHex * sizeof(char));
    char2Hex (*(word + i), aux, lengthOfHex);
    
    for (int k = 0; k<lengthOfHex; k++) {
      *(codedMsg + j) = *(aux + k);
      j++;
    }

    free(aux);

  }
    
  

}


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
