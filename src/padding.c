#include <stdio.h>
#include <stdlib.h>

#define FIRST_PADDING '1'
#define LATER_PADDING '0'

void number2Binary(int number, char* binary) {
  
  for (int i = 0; i<64; i++) {
    *(binary+63-i) = (number % 2 == 0)? '0' : '1';
    number /= 2;
  }
  
  *(binary+64) = '\0';

}
 




void padding (char* codedMsg, size_t codedMsgSize ,char* paddedMsg, size_t paddedMsgSize) {
  
  char* binary = (char*) malloc(64*sizeof(char));
  number2Binary(codedMsgSize, binary);

  int j = 0; 
  for (int i = 0; i<paddedMsgSize; i++) {

    if (i < codedMsgSize) {
      *(paddedMsg + i) = *(codedMsg+i);
    }else if (i == codedMsgSize) {
      *(paddedMsg + i) = FIRST_PADDING;
    }else if (i < paddedMsgSize-64) {
      *(paddedMsg + i) = LATER_PADDING;
    } else { 
      *(paddedMsg + i) = *(binary + j);
      j++;
    }
  }


}
