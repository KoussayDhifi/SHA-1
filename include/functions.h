#ifndef FUNCTIONS
#define FUNCTIONS


void modulusAddition (int* x, int* y, int* res, int w);
void CH (int* x, int* y, int* z, int* res);
void PARITY (int* x, int* y, int* z, int* res);
void MAJ (int* x, int* y, int* z, int* res);
void ROTL (int* x, int n, int* res);


void functions(int* x, int* y, int* z, int t, int* res);

void messageScheduler (int* paddedMsg, int res[32], int t, int n, int paddedMsgSize, size_t resSize); 

void copyArray (int* sourceArray, int* destArray, int length);

#endif
