#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        return 1;
    }
    int digit;
    do
    {
        //*text += fgetc(fp);
        digit = fgetc(fp);
        if(feof(fp)){
            break;
        }
        if(digit != 32 || digit != -1){
            //printf("%c\n", digit);
        }
    }while(1);
    printf("%c\n", digit);
    return 0;
}

//gcc compile
//./a TEXTFILE