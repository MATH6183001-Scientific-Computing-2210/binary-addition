char G(char x, char y){
  return x & y;
}

char P(char x, char y){
  return x ^ y;
}
char S(char x, char y, char cin){

    // S = x xor y xor cin
    return x ^ y ^ cin;
}

char calcCout(char x, char y, char cin){
    // calculateG(x,y) or (calculateP(x,y) and Cin)
    return G(x, y) | (P(x,y) & cin);
}


void CLA(char a[], char b[], unsigned int N, char *sout){

    char cin = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = S(a[i-1],b[i-1],cin);
        cin = calcCout(a[i-1],b[i-1],cin);
    }

    sout[0] = cin;
}