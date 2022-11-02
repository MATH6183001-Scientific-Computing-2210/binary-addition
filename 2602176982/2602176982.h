void CLA(char x[], char y[], unsigned int N, char *sout){
     char cin = '0';

    for(unsigned int i = N; i > 0; i--){
        sout[i] = carryF(x[i-1],y[i-1],cin);
        cin = calcBN(x[i-1],y[i-1],cin);
}