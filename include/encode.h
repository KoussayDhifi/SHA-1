#ifndef ENCODE
#define ENCODE
#endif
#ifndef HEX2BINARY 
#define HEX2BINARY
#endif
#ifndef ALLLENGTH
#define ALLLENGTH


#include <stdint.h>

void number2Binary (uintmax_t x, int* binray, int n);
void encode (char* msg, int* codedMsg);
void hex2Binary (char* hexArray, int lengthOfHex, int* binaryArray, int lengthOfBinaryArray);
int allLength (char* array, int size);

#endif // !
