#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int* bubblesort(int* arr,int size){
    for(int i = 0; i < size; i++){

    }
}
void swap(int* arr, int first){
    int temp = arr[first];
    arr[first] = arr[first+1];
    arr[first+1] = temp;
}

int main(int argc, char const *argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        return 1;
    }
    int digit;
    int i = 0;
    int arr[5];
    do
    {
        digit = fgetc(fp);
        if(feof(fp)){
            break;
        }
        if(digit != 32){
            arr[i] = digit-48;
            i++;
        }
    }while(1);
    swap(arr, 2); //tested swapping
    for(int j = 0; j < 5; j++){
        printf("%d\n", arr[j]);
    }
    return 0;
}

//gcc compile
//./a TEXTFILE