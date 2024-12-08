#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/encode.h"


void char2Binary (char c, int* res) {
  int charValue = c;
  
  for (int i = 0; i<8; i++) {
    *(res+7-i) = (charValue % 2 == 1);
    charValue /= 2;
  } 

}




void encode (char* msg, int* codedMsg) {
  
  size_t sizeMsg = strlen(msg);
  int j = 0;
  int res[8];
  for (int i = 0; i<sizeMsg; i++) {
    
    
    char2Binary(*(msg+i), res); 
    for (int k = 0; k<8; k++) {
      *(codedMsg + j) = *(res + k);
      j++;
    }
    
  }

  
  


}
