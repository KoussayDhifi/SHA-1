#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/readingInput.h"
#include "../include/encode.h"
#include "../include/decode.h"
#include "../include/calcPaddedSize.h"
#include "../include/padding.h"
#include "../include/functions.h"
#include "../include/hashComputation.h"


#define H0 "67452301"
#define H1 "efcdab89"
#define H2 "98badcfe"
#define H3 "10325476"
#define H4 "c3d2e1f0"

#define LENGTHHEXADEC 40
#define LENGOFHASH 160
#define LENGTHWORKINGVARIABLES 8
#define LENGTHWORKINGVARIABLESCONVERSION 32

void showArray (int* T, int n) {
  
  for (int i = 0; i<n; i++) {
    printf("%d",T[i]);
  }
}

void showArrayChar (char* T, int n) {
  
  for (int i = 0; i<n; i++) {
    printf("%c",T[i]);
  }

}




void main (int argc, char** argv) {
	char* msg;
  readingInput(argc, argv, &msg);
  
  const size_t msgLength = strlen(msg);
  const size_t msgLengthInBits = 8*strlen(msg);

int* codedMsg = (int*) malloc((msgLengthInBits+1)*sizeof(int));
  encode(msg, codedMsg);
  printf("CODEDMSG: \n");
  showArray(codedMsg, msgLengthInBits);
  printf("\n--------------------------------------------\n");

  const size_t paddedMsgSize = calcPaddedSize(msgLengthInBits);
  int* paddedMsg = (int*) malloc((paddedMsgSize+1)*sizeof(int));

  padding(codedMsg, msgLengthInBits, paddedMsg, paddedMsgSize);
  printf("SIZE_PADDED_MSG: %d", paddedMsgSize); 
  int numberOfBlocks = paddedMsgSize/512;
  int resultOfHash[LENGOFHASH];
  int workingVariables [5][32];
  int codedMsgOne [32];
  int codedMsgTwo [32];
  int codedMsgThree [32];
  int codedMsgFour [32];
  int codedMsgFive [32];

  hex2Binary (H0, LENGTHWORKINGVARIABLES,codedMsgOne, LENGTHWORKINGVARIABLESCONVERSION);
  hex2Binary (H1, LENGTHWORKINGVARIABLES,codedMsgTwo, LENGTHWORKINGVARIABLESCONVERSION);
  hex2Binary (H2, LENGTHWORKINGVARIABLES,codedMsgThree, LENGTHWORKINGVARIABLESCONVERSION);
  hex2Binary (H3, LENGTHWORKINGVARIABLES,codedMsgFour, LENGTHWORKINGVARIABLESCONVERSION);
  hex2Binary (H4, LENGTHWORKINGVARIABLES,codedMsgFive, LENGTHWORKINGVARIABLESCONVERSION);

  copyArray (codedMsgOne, workingVariables[0], 32);
  copyArray (codedMsgTwo, workingVariables[1], 32);
  copyArray (codedMsgThree, workingVariables[2], 32);
  copyArray (codedMsgFour, workingVariables[3], 32);
  copyArray (codedMsgFive, workingVariables[4], 32);


  hashComputation (numberOfBlocks, paddedMsg, paddedMsgSize, resultOfHash , LENGOFHASH, workingVariables);  
  
 
  
  char hexaDecimalResult [LENGTHHEXADEC];
  binary2Hex (resultOfHash, LENGOFHASH, hexaDecimalResult, LENGTHHEXADEC);
  printf("\nSHA1 = ");
  showArrayChar(hexaDecimalResult, LENGTHHEXADEC);
  printf("\n");
  showArray(resultOfHash, LENGOFHASH);

  
  
  //free (msg);
  //free (codedMsg);
  //free (paddedMsg);
}
