#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

bool CheckProperBinValue(char str[], unsigned int bitLength){
    // How to use: e.g., CheckProperBinValue("10100",5)

    for (int i = 0; i < bitLength; i++){
        if (str[i] != '0' && str[i] != '1'){
            return false;
        }
    }

    return true;
}

unsigned int StrToUint(char str[], unsigned int bitLength){

    // make sure that we have a proper binary string
    assert(CheckProperBinValue(str,bitLength));

    unsigned int output = 0;
    for (int i = 0; i < bitLength; i++){
        
        // atoi accept string instead of a char
        char c[2] = {0};
        c[0] = str[i];
        
        // lefmost is MSB
        output += atoi(c)*pow(2, bitLength-1-i);
    }

    return output;
}

bool BinCharToBinBool(char binChar){
    // remember that in C, you use ' for a char
    assert(binChar == '0' || binChar == '1');

    return (binChar == '1') ? true:false;
}

char BinBoolToBinChar(bool binBool){
    
    return (binBool) ? '1':'0';

}

