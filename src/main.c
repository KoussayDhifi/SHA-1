#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readingInput.h"
#include "../include/encode.h"


void main (int argc, char** argv) {
	char* msg;
  readingInput(argc, argv, &msg);
  
  char** codedMsg = (char**) malloc((strlen(msg)+1)*sizeof(char*));
  encode(msg, codedMsg);




}
