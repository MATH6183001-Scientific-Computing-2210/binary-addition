#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

char calcG(char x , char y){
return x & y;
}
char calcP(char x , char y){
    return x ^ y ;
}

char calcS(char x , char y , char z){
    return x ^ y ^ z;
}

char calcCout(char x , char y , char z){
    return calcG(x,y) ^ (calcP(x,y)&z);
}

void CLA(char x[] , char y[] , int K , char *output ){
    char M[K + 1];
    M[K] = '0';
    for(unsigned int i = K ; i > 0; i--){
        output[i] = calcS(x[i-1],y[i-1],M[i]);
        M[i - 1] = calcCout(x[i-1],y[i-1], M[i]);
    }
    output[0] = M[0];
}
