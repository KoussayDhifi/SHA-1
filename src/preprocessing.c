#include "../include/preprocessing.h"
#include <stdio.h>
#include <string.h>

void preprocessing(char* msg) {
    long size = strlen(msg);
    char[8][size] newMsg;
    
    for (int i = 0; i<size; i++) {
    newMsg[i] = char2Binary(*(msg+i));
  }
  
  free(msg);
  msg = newMsg;

}


char* char2Binary (char c) {
  int number = c;
  char[8] res = {'0'};

  for (int i = 0; i<8; i++) {
    res[i] = (number % 2)-'0';
    number /= 2;
  }
  
  char aux;

  for (int i = 0; i<4; i++) {
    aux = res[i];
    res[i] = res[7-i];
    res[7-i] = aux;
  }
  
  return res;
  


}

