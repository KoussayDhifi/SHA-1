#include <stdio.h>
#include <stdlib.h>
#include "../include/encode.h"

#define FIRST_PADDING 1
#define LATER_PADDING 0
#define LENGTHMSG 64
 




void padding (int* codedMsg, size_t codedMsgSize ,int* paddedMsg, size_t paddedMsgSize) {
  
  int binary[LENGTHMSG];
  number2Binary(codedMsgSize, binary, LENGTHMSG);

  int j = 0; 
  for (int i = 0; i<paddedMsgSize; i++) {

    if (i < codedMsgSize) {
      *(paddedMsg + i) = *(codedMsg+i);
    }else if (i == codedMsgSize) {
      *(paddedMsg + i) = FIRST_PADDING;
    }else if (i < paddedMsgSize-LENGTHMSG-1) {
      *(paddedMsg + i) = LATER_PADDING;
    } else { 
      *(paddedMsg + i) = *(binary + j);
      j++;
    }
  }
}
