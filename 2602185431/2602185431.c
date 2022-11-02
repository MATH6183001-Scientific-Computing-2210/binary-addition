#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

char carryG(char a, char b){
  return a & b;
}

char carryP(char a, char b){
  return a ^ b;
}

void CLA(char x[], char y[], unsigned int N, char *sOut){
  
    char cIn = '0';

    for(int i = N; i > 0; i--){
        sOut[i] = x[i-1] ^ y[i-1] ^ cIn;
        cIn = carryG(x[i-1],y[i-1]) + (carryP(x[i-1],y[i-1]) & cIn);
    }

    sOut[0]=cIn;
}