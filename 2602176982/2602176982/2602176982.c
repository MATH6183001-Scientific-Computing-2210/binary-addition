char carryA(char d, char e){
  return d & e;
}

char carryB(char d, char e){
  return d ^ e;
}
char carryC(char d, char e, char cin){
    return d ^ e ^ cin;
}

char calcBN(char d, char e, char cin){
    return carryA(d, e) | (carryB(d,e) & cin);
}


void CLA(char x[], char y[], unsigned int N, char *sout){
  
    char cin = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = carryF(x[i-1],y[i-1],cin);
        cin = calcBN(x[i-1],y[i-1],cin);
    }

    sout[0] = cin;
}