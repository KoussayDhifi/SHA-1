#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readingInput.h"
#include "../include/encode.h"
#include "../include/decode.h"
#include "../include/calcPaddedSize.h"
#include "../include/padding.h"
#include "../include/functions.h"

void showArray (int* T, int n) {
  printf("T: \n");
  for (int i = 0; i<n; i++) {
    printf("%d",T[i]);
  }
}




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


  
  int x[32]; 
  int y[32];
  int z[32];
  int var;
  int* res = (int*) malloc(32 * sizeof(int));

  for (int i = 0; i<3; i++) {
    for (int j = 0; j<32; j++) {
      var = rand()%2;
      switch (i) {
        case 0:
          x[j] = var;
          break;
        case 1:
          y[j] = var;
          break;
        case 2:
          z[j] = var;
          break;
        default:
          break;
      }
    }
  }
  
  showArray(x,32);
  ROTL(x, 5, res);
  showArray(res,32);
    
    
 

}
