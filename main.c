#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "utils/myutils.h"
#include "my_cra/my_cra.h"

void DecToBin(unsigned int x, unsigned int bitLength, char *output){

    for(int i=0;i < bitLength;i++){
        output[bitLength-1-i] = (x%2==1) ? '1':'0';
        x = x/2; 
    }
    
}

int main(void){

    const int NUM_BITS = 10;
    
    char *operand1 = (char*) malloc(NUM_BITS * sizeof(char)); 
    char *operand2 = (char*) malloc(NUM_BITS * sizeof(char)); 
    char *output = (char *) malloc((NUM_BITS+1) * sizeof(char));
    
    if (operand1 == NULL || operand2 == NULL || output == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {

        bool isStop = false;
        float startTime = (float)clock()/CLOCKS_PER_SEC;
        for (unsigned int i = 0; i < pow(2,NUM_BITS); i++){
            for (unsigned int j = 0; j < pow(2,NUM_BITS); j++){
                DecToBin(i,NUM_BITS,operand1);
                DecToBin(j,NUM_BITS,operand2);
                CRA(operand1,operand2,NUM_BITS,output);

                if (i+j != StrToUint(output,NUM_BITS+1)){
                    printf("[ERROR] i=%d + j=%d = %d\n",i,j,StrToUint(output,NUM_BITS+1));
                    isStop = true;
                }
                if (isStop) break;
            }
            if (isStop) break;
        }
        float endTime  = (float)clock()/CLOCKS_PER_SEC;
        printf("Time elapsed: %f s\n",endTime - startTime);

        free(operand1);
        free(operand2);
        free(output);
    }

    return 0;
}