#include <stdio.h>
#include "../include/readingInput.h"


void main (int argc, char** argv) {
	char* msg = readingInput(argc, argv);
  printf("%s",msg);

}
