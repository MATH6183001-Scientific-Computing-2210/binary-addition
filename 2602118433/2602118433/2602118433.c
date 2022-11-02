#include <assert.h>
#include <stdbool.h>
#include <stdio.h>


char calcG(char a, char b){
  return a & b;
}

char calcP (char a, char b){
  return a ^ b;
}
char calcS(char a, char b, char cin){

    // S = a xor b xor cin
    return a ^ b ^ cin;
}

char calcCout(char a, char b, char cin){
    // calculateG(x,y) or (calculateP(x,y) and Cin)
    return calcG(a, b) | (calcP(a,b) & cin);
}


void CLA(char x[], char y[], unsigned int N, char *sout){
  
    char cin = '0';

    for(int i = N; i > 0; i--){
        sout[i] = x[i-1] ^ y[i-1] ^ cin;
        cin = calcCout(x[i-1],y[i-1],cin);
    }

    sout[0] = cin;
}