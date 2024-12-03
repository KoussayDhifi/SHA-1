#include <stdio.h>
#include "../include/readingInput.h"
#include "../include/preprocessing.h"

void main (int argc, char** argv) {
	char* msg;
  readingInput(argc, argv, &msg);
  printf("%s\n",msg);
}
