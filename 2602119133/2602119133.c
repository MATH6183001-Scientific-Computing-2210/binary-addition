int main(){

char calcG(char x, char y){
  return x & y;
}

char calcP (char x, char y){
  return x ^ y;
}
char calcS(char x, char y, char z){
    return x ^ y ^ z;
}

char calcCout(char x, char y, char z){
    return calcG(x, y) | (calcP(x,y) & z);
}

void CLA(char aa[], char ab[], unsigned int N, char *sout){
  
    char z = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = calcS(aa[i-1],ab[i-1],z);
        z = calcCout(aa[i-1],ab[i-1],z);
    }

    sout[0] = z;
}
}
