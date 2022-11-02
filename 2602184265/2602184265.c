#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

char carryD(char a, char b){
  return a & b;
}

char carryE(char a, char b){
  return a ^ b;
}
char carryF(char a, char b, char cin){
    return a ^ b ^ cin;
}

char calcBN(char a, char b, char cin){
    return carryD(a, b) | (carryE(a,b) & cin);
}


void CLA(char x[], char y[], unsigned int N, char *sout){
  
    char cin = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = carryF(x[i-1],y[i-1],cin);
        cin = calcBN(x[i-1],y[i-1],cin);
    }

    sout[0] = cin;
}