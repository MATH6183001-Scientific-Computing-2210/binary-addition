

char carryGen(char x, char y)
{ // A AND B
    return x & y;
}

char carryProp(char x, char y)
{ // A XOR B
    return x ^ y;
}

void CLA(char x[], char y[], unsigned int bitLength, char *output)
{

    char tmpCarry = '0';
    for (unsigned int n = bitLength; n > 0; n--){

        if (n == bitLength){
        output[n] = x[n-1] ^ y[n-1] ^ '0';
        tmpCarry = carryGen(x[n-1], y[n-1]) + (carryProp(x[n-1], y[n-1]) & '0');
        } else {
        output[n] = x[n-1] ^ y[n-1] ^ tmpCarry;
        tmpCarry = carryGen(x[n-1], y[n-1]) + (carryProp(x[n-1], y[n-1]) & tmpCarry);
        }
    }

    output[0] = tmpCarry;
}
