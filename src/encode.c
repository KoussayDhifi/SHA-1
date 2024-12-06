#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/encode.h"


void char2Binary (char c, char* res) {
  int charValue = c;
  
  for (int i = 0; i<8; i++) {
    *(res+7-i) = (charValue % 2 == 0)? '0' : '1';
    charValue /= 2;
  } 

}




void encode (char* msg, char* codedMsg) {
  
  size_t sizeMsg = strlen(msg);
  int j = 0;
  for (int i = 0; i<sizeMsg; i++) {
    
    char* res = (char*) malloc(8*sizeof(char));
    char2Binary(*(msg+i), res); 
    for (int k = 0; k<8; k++) {
      *(codedMsg + j) = *(res + k);
      j++;
    }
    free(res);
  }

  
  
  *(codedMsg+j) = '\0';

}
