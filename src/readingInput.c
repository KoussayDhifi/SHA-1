#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 char* readingInput (int argc, char** argv) {

  if (strcmp(*(argv+1),"-s") == 0) {

    return *(argv+2);

  }else if (strcmp(*(argv+1),"-f") == 0) {

      FILE* filePtr = fopen(*(argv+2),"r");
      fseek(filePtr,0,SEEK_END);
      long fileSize = ftell(filePtr);
      rewind(filePtr);
      char* buffer = (char*) malloc(fileSize+1);
      
      if (buffer == NULL) {
      printf("MEMORY ALLOCATION FAILED");
      exit(1);
      }else {
        fread(buffer,1,fileSize,filePtr);
        buffer[fileSize] = '\0';
        return buffer;
    }
  }else {
      printf("Unrecognized flag %s\n",*(argv+1));
      exit(1);
    }
} 
