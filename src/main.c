#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readingInput.h"
#include "../include/encode.h"
#include "../include/decode.h"
#include "../include/calcPaddedSize.h"
#include "../include/padding.h"
#include "../include/functions.h"

void main (int argc, char** argv) {
	char* msg;
  readingInput(argc, argv, &msg);
  
  const size_t msgLength = strlen(msg);
  const size_t msgLengthInBits = 8*strlen(msg);

  int* codedMsg = (int*) malloc((msgLengthInBits+1)*sizeof(int));
  encode(msg, codedMsg);


  const size_t paddedMsgSize = calcPaddedSize(msgLengthInBits);
  int* paddedMsg = (int*) malloc((paddedMsgSize+1)*sizeof(int));

  padding(codedMsg, msgLengthInBits, paddedMsg, paddedMsgSize);

  for (int i = 0; i<paddedMsgSize; i++) {
    printf("%d",paddedMsg[i]);
  }
 

}
