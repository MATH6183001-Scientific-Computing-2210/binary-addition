#include <stdio.h> // header file library

char calculateA(char x, char y){  //char = stores single characters
    return x & y;
} // A = x AND y 

char calculateB(char x, char y){
    return x ^ y;
} // B = X XOR y


char calculateC(char x, char y, char cin){ // cin = character input
    return x ^ y ^ cin; // C = x XOR y XOR cin
}

char calculateCout(char x, char y, char cin){  // calculateCout =  calculateA(x,y) OR (calculateB(x,y) AND Cin) 
    return calculateA(x, y) | (calculateB(x, y) & cin);
}

void CLA(char a[], char b[], unsigned int bitLength, char *output){
    
    char cin = '0';
    
    for(unsigned int i = bitLength; i > 0; i--){
        output[i] = calculateC(a[i-1], b[i-1], cin);
        cin = calculateCout(a[i-1], b[i-1], cin);
    }

    output[0] = cin;
}
