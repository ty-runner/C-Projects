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

void bubblesort(int* arr, int count){
    int i, j;
    bool swapped;
    for (i = 0; i < count - 1; i++) {
        swapped = false;
        for (j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
  
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

int main(int argc, char const *argv[])
{
    int num_count = num_of_ints(argv[1]);
    int* arr = (int*) malloc(num_count*sizeof(int));
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        return 1;
    }
    int digit[10];
    int digit_count=0;
    int sum=0;
    int index = 0;
    //maybe in the future I make this a seperate function
    do
    {
        digit[digit_count++] = fgetc(fp);
        if(feof(fp)){
            break;
        }
        if(digit[digit_count-1] == 32){
            for(int i = 0; i<digit_count-1;i++){
                sum += (digit[i]-48)*(pow(10,(digit_count-2-i)));
            }
            printf("SUM: %d\n", sum);
            arr[index++] = sum;
            digit_count = 0;
            sum = 0;
        }
    }while(1);
    bubblesort(arr, num_count);
    fclose(fp);
    write_to_file(arr);
    free(arr);
    return 0;
}

//gcc compile
//./a TEXTFILE