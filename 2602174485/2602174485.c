char calcR(char x , char y){
return x & y;
}
char calcH(char x , char y){
    return x ^ y ;
}
char calcI(char x , char y , char z){
    return calcR(x,y) ^ (calcH(x,y)&z);
}
char calcA(char x , char y , char z){
    return x ^ y ^ z;
}
void CLA(char x[] , char y[] , int bitLength , char *output ){
    char M[bitLength + 1];
    M[bitLength] = '0';
    for(int i = bitLength ; i > 0; i--){
        output[i] = calcA(x[i-1],y[i-1],M[i]);
        M[i - 1] = calcI(x[i-1],y[i-1], M[i]);
    }
    output[0] = M[0];
}