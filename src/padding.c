#include <stdio.h>
#include <stdlib.h>

#define FIRST_PADDING 1
#define LATER_PADDING 0

void number2Binary(int number, int* binary) {
  
  for (int i = 0; i<64; i++) {
    *(binary+63-i) = (number % 2 == 1);
    number /= 2;
  }
  
  

}
 




void padding (int* codedMsg, size_t codedMsgSize ,int* paddedMsg, size_t paddedMsgSize) {
  
  int binary[64];
  number2Binary(codedMsgSize, binary);

  int j = 0; 
  for (int i = 0; i<paddedMsgSize; i++) {

    if (i < codedMsgSize) {
      *(paddedMsg + i) = *(codedMsg+i);
    }else if (i == codedMsgSize) {
      *(paddedMsg + i) = FIRST_PADDING;
    }else if (i < paddedMsgSize-63) {
      *(paddedMsg + i) = LATER_PADDING;
    } else { 
      *(paddedMsg + i) = *(binary + j);
      j++;
    }
  }
}
