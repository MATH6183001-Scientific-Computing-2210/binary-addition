#include <stdio.h>

char calcSum(char a, char b, char cin){
    // sum = a XOR b XOR cin
    return a ^ b ^ cin;
}

char calcG(char a, char b){
    // G = a AND b
    return a & b;
}

char calcP(char a, char b){
    // P = a XOR B
    return a ^ b;
}

char calcCout(char a, char b, char cin){
    //calcG OR calcP AND cin
    return calcG(a,b) | (calcP(a,b) & cin);
}
void CLA(char x[], char y[], unsigned int bitLength, char *output){

    char tmpCarry = '0';

    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calcSum(x[i-1],y[i-1],tmpCarry);
        tmpCarry = calcCout(x[i-1],y[i-1],tmpCarry);
    }

    output[0] = tmpCarry;
}