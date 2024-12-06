#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_FLAG "-f"
#define STRING_FLAG "-s"

 void readingInput (int argc, char** argv, char** msg) {
  
  if (argc != 3) {
    fprintf(stderr, "Uncompatible number of positional arguments expected 2 given %d.\n Hint: If you want to pass a string with spaces put it inside \"\"\n",argc-1);
    exit(EXIT_FAILURE);
  }
  

  if (strcmp(*(argv+1),STRING_FLAG) == 0) {

    *msg = *(argv+2);

  }else if (strcmp(*(argv+1),FILE_FLAG) == 0) {

      FILE* filePtr = fopen(*(argv+2),"r");
      
      if (filePtr == NULL) {
      fprintf(stderr,"File was not opened. Exiting ...\n");
      exit(EXIT_FAILURE);
      }
    
      if (fseek(filePtr,0,SEEK_END) != 0) {
      fprintf(stderr,"Could not determine the size of file. Exiting ...\n");
      fclose(filePtr);
      exit(EXIT_FAILURE);
      }
      long fileSize = ftell(filePtr);
      
      rewind(filePtr);
      *msg = (char*) malloc(fileSize+1);
      
      if (*msg == NULL) {
      fprintf(stderr,"MEMORY ALLOCATION FAILED \n");
      exit(EXIT_FAILURE);
      }else {
        size_t bytesRead = fread(*msg,1,fileSize,filePtr);
        if (bytesRead != fileSize) {
        fprintf(stderr, "Error reading file. Exiting ...\n");
        exit(EXIT_FAILURE);
      }
        *(*msg+fileSize) = '\0';
        fclose(filePtr);
    }
  }else {
      fprintf(stderr,"Unrecognized flag %s\n",*(argv+1));
      exit(EXIT_FAILURE);
    }
} 
