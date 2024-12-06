#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readingInput.h"
#include "../include/encode.h"
#include "../include/decode.h"

void main (int argc, char** argv) {
	char* msg;
  readingInput(argc, argv, &msg);
  
  const size_t msgLength = strlen(msg);
  const size_t msgLengthInBits = 8*strlen(msg);


  printf("%s\n",msg);

  char* codedMsg = (char*) malloc((msgLengthInBits+1)*sizeof(char));
  encode(msg, codedMsg);

  char* newMsg = (char*) malloc(msgLength*sizeof(char));
  
  printf("%s", codedMsg);

  decode(codedMsg, newMsg, msgLengthInBits);

  printf("This is the decoded MSG: %s\n",newMsg);


}
