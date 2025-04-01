#include <stdio.h>
#include <stdlib.h>
#include "../include/functions.h"
#include "../include/encode.h"

#define LENGTHWORKINGVAR 32
#define LENGTHWORKINGVARHEX 8
#define NUMBEROFCONSTANTS 4
#define NUMBEROFROTATIONSONE 5
#define NUMBEROFROTATIONSTWO 30
#define WORKINGVARIABLES 5
#define COMPUTATIONS 80
#define K0 "5a827999"
#define K1 "6ed9eba1"
#define K2 "8f1bbcdc"
#define K3 "ca62c1d6"
 

void generateArrayOfSHAConstants (int K[NUMBEROFCONSTANTS][LENGTHWORKINGVAR]) {
  hex2Binary(K0,LENGTHWORKINGVARHEX, K[0], LENGTHWORKINGVAR);
  
  hex2Binary(K1, LENGTHWORKINGVARHEX, K[1], LENGTHWORKINGVAR);
  hex2Binary(K2, LENGTHWORKINGVARHEX, K[2], LENGTHWORKINGVAR);
  hex2Binary(K3, LENGTHWORKINGVARHEX, K[3], LENGTHWORKINGVAR);
}



void hashComputation (int numberOfBlocks, int* paddedMsg, size_t paddedMsgSize, int* resultOfHash , size_t lengthOfHash, int workingVariables[5][32]) {
  
  int a[LENGTHWORKINGVAR] = {0};
  int b[LENGTHWORKINGVAR] = {0};
  int c[LENGTHWORKINGVAR] = {0};
  int d[LENGTHWORKINGVAR] = {0};
  int e[LENGTHWORKINGVAR] = {0};
  
  int K[NUMBEROFCONSTANTS][LENGTHWORKINGVAR];
  generateArrayOfSHAConstants(K);
  
  int modularSumOne[LENGTHWORKINGVAR] = {0};
  int modularSumTwo[LENGTHWORKINGVAR] = {0};
  int modularSumThree[LENGTHWORKINGVAR] = {0};
  int modularSumFour[LENGTHWORKINGVAR] = {0};
  int modularSumFive[LENGTHWORKINGVAR] = {0};
  int T[LENGTHWORKINGVAR] = {0};

  int rotationResult[LENGTHWORKINGVAR] = {0};
  int functionResult[LENGTHWORKINGVAR] = {0};
  int messageSchedulerResult[LENGTHWORKINGVAR] = {0};
  int indexOfK;
  for (int i = 0; i<numberOfBlocks; i++) {
    
    copyArray (workingVariables[0], a, LENGTHWORKINGVAR);
    copyArray (workingVariables[1], b, LENGTHWORKINGVAR);
    copyArray (workingVariables[2], c, LENGTHWORKINGVAR);
    copyArray (workingVariables[3], d, LENGTHWORKINGVAR);
    copyArray (workingVariables[4], e, LENGTHWORKINGVAR);
   
    for (int t = 0; t<COMPUTATIONS; t++) {

      if (t <= 19 && t >= 0) {
        indexOfK = 0;
      }else if (t >= 20 && t <= 39){
        indexOfK = 1;
      }else if (t >= 40 && t <= 59) {
        indexOfK = 2;
      }else {
        indexOfK = 3;
      }
      

      ROTL(a, NUMBEROFROTATIONSONE, rotationResult);
//printf("Calling messageScheduler for t=%d and i=%d",t,i);
      functions(b, c, d, t, functionResult);
     size_t size = sizeof(messageSchedulerResult); 
      
    
     messageScheduler(paddedMsg, messageSchedulerResult, t, i+1, paddedMsgSize, size);
    
      
      modulusAddition(rotationResult, functionResult, modularSumOne, LENGTHWORKINGVAR);
      modulusAddition(e, K[indexOfK], modularSumTwo, LENGTHWORKINGVAR);
      modulusAddition(modularSumOne, modularSumTwo, modularSumThree, LENGTHWORKINGVAR);

      modulusAddition (modularSumThree, messageSchedulerResult, T, LENGTHWORKINGVAR);
 
      
      copyArray (d, e, LENGTHWORKINGVAR);

      copyArray (c, d , LENGTHWORKINGVAR);
      ROTL (b, NUMBEROFROTATIONSTWO, rotationResult);
      copyArray (rotationResult, c, LENGTHWORKINGVAR);
      copyArray (a, b, LENGTHWORKINGVAR);
      copyArray (T, a, LENGTHWORKINGVAR);
    
    }
    
    modulusAddition(a, workingVariables[0], modularSumOne, LENGTHWORKINGVAR);
    modulusAddition(b, workingVariables[1], modularSumTwo, LENGTHWORKINGVAR);
    modulusAddition(c, workingVariables[2], modularSumThree, LENGTHWORKINGVAR);
    modulusAddition(d, workingVariables[3], modularSumFour, LENGTHWORKINGVAR);
    modulusAddition(e, workingVariables[4], modularSumFive, LENGTHWORKINGVAR);
    
    copyArray (modularSumOne, workingVariables[0], LENGTHWORKINGVAR);
    copyArray (modularSumTwo, workingVariables[1], LENGTHWORKINGVAR);
    copyArray (modularSumThree, workingVariables[2], LENGTHWORKINGVAR);
    copyArray (modularSumFour, workingVariables[3], LENGTHWORKINGVAR);
    copyArray (modularSumFive, workingVariables[4], LENGTHWORKINGVAR);

    
    
  }
  
  int k = 0;
  for (int i = 0; i<WORKINGVARIABLES; i++) {
    for (int j = 0; j<LENGTHWORKINGVAR; j++) {
      * (resultOfHash + k) = workingVariables[i][j];
      k++;
    }
  }
  
}


