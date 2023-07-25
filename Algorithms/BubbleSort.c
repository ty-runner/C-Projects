#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    /* code */
    FILE* fp = fopen("argv[1]", "r");
    if(fp == NULL){
        return 1;
    }
    char text[250];
    printf("gets tehre\n");
    while(fgets(text, sizeof(text), fp))
    {
        
    }
    printf("%s\n", text);
    return 0;
}

//vscode wont compile?