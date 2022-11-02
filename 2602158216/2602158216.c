char oper1(char x , char y){
return x & y;
}
char oper2(char x , char y){
    return x ^ y ;
}
char oper3(char x , char y , char z){
    return oper1(x,y) ^ (oper2(x,y)&z);
}
char oper4(char x , char y , char z){
    return x ^ y ^ z;
}
void CLA(char x[] , char y[] , int A , char *output ){
    char B[A + 1];
    B[A] = '0';
    for(int i = A ; i > 0; i--){
        output[i] = oper4(x[i-1],y[i-1],B[i]);
        B[i - 1] = oper3(x[i-1],y[i-1], B[i]);
    }
    output[0] = B[0];
}