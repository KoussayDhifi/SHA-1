#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readingInput.h"
#include "../include/encode.h"
#include "../include/decode.h"

void main (int argc, char** argv) {
	char* msg;
  readingInput(argc, argv, &msg);
  
  printf("%s\n",msg);

  char** codedMsg = (char**) malloc((strlen(msg)+1)*sizeof(char*));
  encode(msg, codedMsg);

  char* newMsg = (char*) malloc(strlen(msg)*sizeof(char));
  
  for (int i = 0; i<strlen(msg); i++) {
    printf("%s",codedMsg[i]);
  }

  decode(codedMsg, newMsg, strlen(msg));

  printf("\n%s\n",newMsg);


}
