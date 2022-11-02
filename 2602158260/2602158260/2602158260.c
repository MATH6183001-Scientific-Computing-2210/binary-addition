#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils/myutils.h"


char calcS(char s, char cin){

    return s ^ cin;
}

char gen(char a, char b){
    return a & b;
}

void CLA(char x[], char y[], unsigned int bitLength, char *output){

    assert(CheckProperBinValue(x,bitLength));
    assert(CheckProperBinValue(y,bitLength));

    char carry[bitLength + 1];
    carry[bitLength] = '0';
    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calcS(x[i - 1] ^ y[i - 1],carry[i]);
        if (x[i - 1] == y[i - 1]){
            carry[i - 1] = gen(x[i - 1], y[i - 1]);
        }
        else {
            carry[i - 1] = carry[i];
        }
    }

    output[0] = carry[0];
}