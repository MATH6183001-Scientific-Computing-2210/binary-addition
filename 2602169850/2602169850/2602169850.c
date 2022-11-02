#include <stdio.h>

char calculateG(char x, char y){
    return x & y;
}

char calculateP(char x, char y){
    return x ^ y;
}

char calculateS(char x, char y, char cin){
    return x ^ y ^ cin;
}

char calccout(char x, char y, char cin){
    return calculateG(x, y) | (calculateP(x, y) & cin);
}

void CLA(char a[], char b[], unsigned int bitLength, char *output){
    
    char cin = '0';
    
    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calculateS(a[i-1], b[i-1], cin);
        cin = calccout(a[i-1], b[i-1], cin);
    }

    output[0] = cin;
}