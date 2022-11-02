
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include<stdlib.h>
#include <assert.h>





char sum(char g, char p, char cin){
    //

    return g ^ p ^ cin;
}

char cout(char g, char p, char cin){

    return(g^p|(cin));
    //c+1=G xor P.cin
}
void CLA(char x[], char y[], unsigned int bitLength, char *output){

    assert(CheckProperBinValue(x,bitLength));
    assert(CheckProperBinValue(y,bitLength));

    char inputcarrier =0;
     
  



 for(unsigned int i = bitLength-1; i >=0; i++){ 
        output[i] =  (x[i-1]^ (y[i-1])^(inputcarrier));
       inputcarrier= (x[i-1]+ y[i-1]+(x[i-1] ^ (y[i-1]+inputcarrier)));
    }

    output[0] = inputcarrier;
}

void DecToBin(unsigned int x, unsigned int bitLength, char *output){

    for(int i=0; i < bitLength-1; i++){
        output[bitLength-1-i] = (x%2==1) ? '1':'0';
        x = x/2; 
    }
    
}

int main(void){

    const int BITS = 10;
   
    
    char *operand1 = (char*)malloc(BITS * sizeof(char)); 
    char *operand2 = (char*)malloc(BITS * sizeof(char)); 
    char *output = (char *) malloc((BITS+1) * sizeof(char));


    
if (operand1 == NULL || operand2 == NULL || output == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {bool isStop = false;
    //Time complexity
        float startTime = (float)clock()/CLOCKS_PER_SEC;
        for (unsigned int i = 0; i < BITS; i++){
            for (unsigned int j = 0; j < BITS; j++ ){
                DecToBin(i,BITS,operand1);
                DecToBin(j,BITS,operand2);
                CLA(operand1,operand2,BITS,output); 
            if (i+j != StrToUint(output,BITS)){
                    printf("[Opps!!] i=%d + j=%d = %d\n",i,j,StrToUint(output,BITS));
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