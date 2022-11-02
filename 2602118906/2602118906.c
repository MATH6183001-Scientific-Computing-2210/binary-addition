#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

char carryG(char a, char b){
  return a & b;
}

char carryP(char a, char b){
  return a ^ b;
}

char carryS(char a, char b, char cin){
  return a ^ b ^ cin;
}

char calc(char a, char b, char cin){
  return carryG(a, b) | carryP(a,b) & cin;
}

void CLA(char x[], char y[], unsigned int N, char *sout){

    char cin = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = carryS(x[i-1],y[i-1],cin);
        cin = calc(x[i-1],y[i-1],cin);
    }

    sout[0] = cin;
}