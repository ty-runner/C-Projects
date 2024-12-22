#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
void write_to_file(int* arr){
    FILE* fp = fopen("sorted.txt", "w");
    for(int i = 0; i < sizeof(arr)+1;i++){
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}
int num_of_ints(char const *file){
    FILE* fp = fopen(file, "r");
    int digit;
    int count = 0;
    if(fp == NULL){
        return 1;
    }
    do{
        digit = fgetc(fp);
        if(feof(fp)){
            break;
        }
        if(digit == 32){
            count++;
        }
    }while(1);
    fclose(fp);
    return count;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(int argc, char const *argv[])
{
    int num_count = num_of_ints(argv[1]);
    int* arr = (int*) malloc(num_count*sizeof(int));
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