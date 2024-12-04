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
  *(res+8) = '\0'; 

}




void encode (char* msg, char** codedMsg) {
  
  size_t sizeMsg = strlen(msg);

  for (int i = 0; i<sizeMsg; i++) {
    
    char* res = (char*) malloc(9*sizeof(char));
    char2Binary(*(msg+i), res); 
    *(codedMsg+i) = res;
  
  }
  
  *(codedMsg+sizeMsg) = NULL;

}
