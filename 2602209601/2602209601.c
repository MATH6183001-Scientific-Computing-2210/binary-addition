#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils/myutils.h"


char calcS(char a, char b, char cin){

    // S = a xor b xor cin
    return a ^ b ^ cin;
}

char calcCout(char a, char b, char cin){

    return (~a & b & cin) | (a & ~b & cin) | (a & b & ~cin) | (a & b & cin);
}

void CLA(char x[], char y[], unsigned int bitLength, char *output){

    assert(CheckProperBinValue(x,bitLength));
    assert(CheckProperBinValue(y,bitLength));

    char tmpCarry = '0';

    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calcS(x[i-1],y[i-1],tmpCarry);
        tmpCarry = calcCout(x[i-1],y[i-1],tmpCarry);
    }

    output[0] = tmpCarry;
}
