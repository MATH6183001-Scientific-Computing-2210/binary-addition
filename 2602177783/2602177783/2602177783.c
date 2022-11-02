#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils/myutils.h"


char calcS(char a, char b, char cin){

    return a ^ b ^ cin;
}

char calcC(char a, char b, char cin){

    if (a == b) {
        return a & b;
    }
    else {
        return cin;
    }
}

void CLA(char x[], char y[], unsigned int bitLength, char *output){

    assert(CheckProperBinValue(x, bitLength));
    assert(CheckProperBinValue(y, bitLength));

    char carry[bitLength + 1];
    carry[bitLength] = '0';

    for(unsigned int i = bitLength; i > 0; i--){
        carry[i - 1] = calcC(x[i - 1], y[i - 1], carry[i]);
    }

    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calcS(x[i - 1], y[i - 1], carry[i]);
    }

    output[0] = carry[0];
}