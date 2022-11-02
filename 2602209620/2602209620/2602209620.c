#include <stdio.h>

char calcG(char a, char b){
    return a & b;
}

char calcP(char a, char b){
    return a ^ b;
}

char calcS(char a, char b, char Cin){
    return a ^ b ^ Cin;
}

char calcCout(char a, char b, char Cin){
    return calcG(a, b) | (calcP(a, b) & Cin);
}

void CLA(char c[], char d[], unsigned int bitLength, char *output){
    
    char Cin = '0';
    
    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calcS(c[i-1], d[i-1], Cin);
        cin = calcCout(c[i-1], d[i-1], Cin);
    }

    output[0] = Cin;
}