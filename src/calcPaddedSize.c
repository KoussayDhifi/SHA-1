#include <stdio.h>

int calcPaddedSize (int codedMsgLength) {
  int k = ( 512 - ( (codedMsgLength + 65) % 512) ) % 512;
  return codedMsgLength+65+k;
}

