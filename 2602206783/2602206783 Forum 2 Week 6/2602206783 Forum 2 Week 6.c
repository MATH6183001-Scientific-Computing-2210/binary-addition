char calc_G(char a, char b){
  return a & b;
}

char calc_P(char  a, char b){
  return a ^ b;
}
char calc_S(char a, char b, char cin){
    return a ^ b ^ cin;
}

char calc_Cout(char a, char b, char cin){
    return calc_G(a, b) | (calc_P(a,b) & cin);
}

void CLA(char x[], char y[], unsigned int N, char *sout){
  
    char cin = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = calc_S(x[i-1],y[i-1],cin);
        cin = calc_Cout(x[i-1],y[i-1],cin);
    }
    
    sout[0] = cin;
}