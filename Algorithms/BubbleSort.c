#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        return 1;
    }
    int digit[10];
    int digit_count=0;
    int sum=0;
    do
    {
        digit[digit_count++] = fgetc(fp);
        // printf("Count: %d\n", digit_count);
        // printf("Digit: %c\n", digit[digit_count-1]);
        if(feof(fp)){
            break;
        }
        if(digit[digit_count-1] == 32){
            for(int i = 0; i<digit_count-1;i++){
                sum += (digit[i]-48)*(pow(10,(digit_count-2-i)));
            }
            printf("SUM: %d\n", sum);
            //write sum to array
            //sort
            digit_count = 0;
            sum = 0;
        }
    }while(1);
    return 0;
}

//gcc compile
//./a TEXTFILE