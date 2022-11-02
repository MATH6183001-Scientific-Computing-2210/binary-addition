#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils/myutils.h"



char calcG(char x, char y){
  return x & y;
}

char calcP (char  x, char y){
  return x ^ y;
}
char calcS(char x, char y, char cin){

    // S = x xor y xor cin
    return x ^ y ^ cin;
}

char calcCout(char x, char y, char cin){
    // calculateG(x,y) or (calculateP(x,y) and Cin)
    return calcG(x, y) | (calcP(x,y) & cin);
}


void CLA(char x[], char y[], unsigned int N, char *sout){
  
    char cin = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = calcS(x[i-1],y[i-1],cin);
        cin = calcCout(x[i-1],y[i-1],cin);
    }

    sout[0] = cin;
}