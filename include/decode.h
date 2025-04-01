#ifndef DECODE
#define DECODE
#endif
#ifndef BINARY2HEX
#define BINARY2HEX
#include <stdint.h>

uintmax_t binary2Number (int* x, int n);
void decode(int* codedMsg, size_t codedMsgSize,char* decodedMsg);
void binary2Hex (int* binaryArray, int lengthOfBinaryArray, char* hexConv, int lengthOfHex);

#endif // !
