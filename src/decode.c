#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/decode.h"

void binary2Char(char* binary, char* c) {
  int power = 7;
  *c = 0;
  for (int i = 0; i<=8; i++) {
    *c += (*(binary+i) == '1')? (1 << power) : 0;
    power--;
  }


}


void decode (char** codedMsg, char* decodedMsg, size_t sizeCodedMsg) {
  
  for (int i = 0; i<sizeCodedMsg; i++) {
    binary2Char(*(codedMsg+i), decodedMsg+i);
  }

}
