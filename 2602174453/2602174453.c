#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils/myutils.h"
#include "my_cra/my_cra.h"

char calcG(char x, char y) {
    return x & y;
}

char calcP(char x, char y) {
    return x ^ y;
}

char Cout(char x, char y, char Cin) {
    return calcG(x,y) | (calcP(x,y) & Cin);
}

char calcS(char a, char b, char cin){

    // S = a xor b xor cin
    return a ^ b ^ cin;
}

void CLA(char a[], char b[], unsigned int bitLength, char *output) {
    char Cin = '0';
    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calcS(a[i-1],b[i-1],Cin);
        Cin = Cout(a[i-1],b[i-1],Cin);
    }

    output[0] = Cin;
}

