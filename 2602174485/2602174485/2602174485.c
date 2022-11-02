
char calcR(char x , char y){
return x & y;
}
char calcH(char x , char y){
    return x ^ y ;
}
char calcI(char x , char y , char z){
    return calcR(x,y) ^ calcH(x,y)&z;
}
char calcA(char x , char y , char z){
    return x ^ y ^ z;
}
void CLA(char x[] , char y[] , int K , char *output ){
    char M[K + 1];
    M[K] = '0';
    char z = 0;
    for(int i = K ; i > 0; i--){
        output[i] = calcA(x[i-1],y[i-1],M[i]);
        M[i - 1] = calcI(x[i-1],y[i-1], M[i]);
    }
    output[0] = M[0];
}
int K = 5;