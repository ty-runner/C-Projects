#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "login.h"
int main(int argc, char const *argv[])
{
    /* code */
    //char* input_call();
    //input call, log-in?, change password?, new user?
    char* string = input_call();
    printf("Welcome %s!\n", string);
    free(string);
    return 0;
}
bool name_in_text(char* string){
    FILE* fp = fopen("login.txt", "r");
    if(fp == NULL){
        return false;
    }
    char text[1024];
    // char* extend = (char*) malloc(16);
    // strcat(extend, string);
    // strcat(extend, "|"); //MAYBE WE DONT NEED THIS
    //printf("%s\n", extend);
    while(fgets(text, sizeof(text), fp)){
        if(strstr(text, string) != NULL){
            //printf("Test String: %s\n", string);
            //free(extend);
            return true;
        }
    }
    //free(extend);
    //printf("%s\n", text);
    fclose(fp);
    return false;
}
void write_to_file(char* string, bool user){
    FILE* fp = fopen("login.txt", "a");
    if(fp == NULL){
        return;
    }
    //string = strcat"|";
    if(user){
        fprintf(fp, "%s|", string);
    }
    else{
        fprintf(fp, "%s", string);
    }
    fclose(fp);
}
char* input_call(){
    char* option = (char*) malloc(15);
    printf("Hello, login? new_user?, change_password?\n");
    scanf("%s", option);
    //printf("%d\n", strlen(option));
    if(!strcmp(option, "login")){
        free(option);
        char* username = (char*) malloc(15);
        char* password = (char*) malloc(30);
        printf("Enter Your Username\n");//enter username
        scanf("%s", username);
        if(name_in_text(username)){
            printf("Enter your password\n");//prompt password
            scanf("%s", password);
            printf("%s\n", password);
            if(name_in_text(password)){
                return username;//we're in
            }
        }
        else{
            printf("Username does not exist\n");
        }
        return username;
    }
    //new_user prompts for new username, new password, reenter password
    else if(!strcmp(option, "new_user")){
        free(option);
        char* username = (char*) malloc(15);
        char* password = (char*) malloc(30);
        char* pass_check = (char*) malloc(30);
        printf("Enter your new username: ");//enter new username
        scanf("%s", username);
        printf("Enter your new password: ");
        scanf("%s", password);
        printf("Re-enter your password password: ");
        scanf("%s", pass_check);
        if(!(strcmp(password, pass_check))){
            strcat(password, "\n");
            write_to_file(username, true);
            write_to_file(password, false);
        }
        else{
            printf("Passwords did not match :(\nTry running again\n");
        }
        free(password); 
        free(pass_check);
        return username;
        //make sure it doesnt exist in text file maybe this feature gets removed
        //create password
        //re enter password and make sure they match
    }
    else if(!strcmp(option, "change_password")){
        free(option);
        char* username;
        printf("Enter Your Username\n");//enter username
        scanf("%s", username);
        //enter username, make sure it exists in text file
        //if name in text, search for name, iterate over the parser and replace password

        //replacing password might be a fair amount of work but i have some ideas:
        //  - Clear password, save the text after the password, write the password after the matching username and rewrite the proceeding text in
        //else username doesn't exist
        //enter old password, if it matches prompt change
        //repplace old password with new password
    }
    return option;
}