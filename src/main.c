#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readingInput.h"
#include "../include/encode.h"
#include "../include/decode.h"
#include "../include/calcPaddedSize.h"
#include "../include/padding.h"

void main (int argc, char** argv) {
	char* msg;
  readingInput(argc, argv, &msg);
  
  const size_t msgLength = strlen(msg);
  const size_t msgLengthInBits = 8*strlen(msg);

  char* codedMsg = (char*) malloc((msgLengthInBits+1)*sizeof(char));
  encode(msg, codedMsg);


  const size_t paddedMsgSize = calcPaddedSize(msgLengthInBits);
  char* paddedMsg = (char*) malloc((paddedMsgSize+1)*sizeof(char));

  padding(codedMsg, msgLengthInBits, paddedMsg, paddedMsgSize);

  printf("PaddedMsg: %s \n", paddedMsg);
  

}
