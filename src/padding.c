#include <stdio.h>
#include <stdlib.h>

#define FIRST_PADDING {'1','0','0','0','0','0','0','0'}
#define LATER_PADDING {'0','0','0','0','0','0','0','0'}

void number2Binary(int number, char** binary) {
  for (int i = 0; i<64; i++) {
    *(*binary+63-i) = (number % 2 == 0)? '0':'1';
    number /= 2;
  }
  *(binary+64) = NULL;
}
 




void padding (char** codedMsg, size_t msgSize ,char** paddedMsg, int paddedMsgSize) {

  size_t lengthInBits = msgSize*8;
  char** lengthInBinary = (char**) malloc(65*sizeof(char*));
  number2Binary(lengthInBits, lengthInBinary);
  int j = 0;

  for (int i = 0; i<paddedMsgSize; i++) {
    if (i < msgSize) {
      *(paddedMsg+i) = *(codedMsg+i);
    }else if (i == msgSize) {
      *(paddedMsg+i) = FIRST_PADDING;
    }else if (i<msgSize-7) {
      *(paddedMsg+i) = LATER_PADDING;
    }else {
      *(paddedMsg+i) = *(lengthInBinary+j);
      j++;
    }
  }


}
