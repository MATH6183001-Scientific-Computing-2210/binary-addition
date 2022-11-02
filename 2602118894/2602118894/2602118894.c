
char calcG (char a, char b){
    return a & b;
}

char calcP (char a, char b){
    return a ^ b;
}


void CLA(char x[], char y[], unsigned int bitLength, char *output){


    char tmpCarry = '0';

    for (unsigned int i = bitLength; i > 0; i--)
    {
        output[i] = (calcP(x[i-1], y[i-1])) ^ (tmpCarry);
        tmpCarry = (calcG(x[i-1], y[i-1])) | (calcP(x[i-1], y[i-1]) & tmpCarry);
    }
    output[0] = tmpCarry;
}