//
//  main.c
//  project1
//
//  Created by 김보영 on 2017. 3. 23..
//  Copyright © 2017년 김보영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 987654321
#define INTERACTIVE 1
#define BATCH 2

char **tok(char *inp, char *sep){
    char *ptr;
    char **str_save;
    int length = strlen(inp);
    
    str_save = (char**)malloc(sizeof(char*)*length);
    
    
    int i = 0;
    ptr = strtok(inp, sep);
    
    
    while(ptr != NULL && strlen(ptr) != 0){
        str_save[i] = ptr;
        i++;
    }
    
    while(strlen(ptr) != 0){
        ptr = strtok(NULL, sep);
        str_save[i] = ptr;
        i++;
    }
    
    if(str_save[0] == NULL)
        return NULL;
    else
        return str_save;
    
}

int main(int argc, const char * argv[]) {
    
    FILE *fp;
    
    char str[MAX_SIZE]; //given string
    int check; //interactive or batch (checking)
    int num = 0, num2 = 0, i = 0, j=0; // initializing
    int status;
    
    if(argc > 1){
        check = INTERACTIVE;
        fp = fopen(argv[1], "r");
    }
    
    else if (argc == 1){
        check = BATCH;
        fp = stdin;
    }
    
    else{
        printf("Input file error");
    }
    
    while(1){
        if(check == INTERACTIVE){
            printf("prompt>");
            
        }
        
        fgets(str, MAX_SIZE, fp);
        
        /* using strtok function with ";" */
        char **str_1 = tok(str, ";");
        
        while(str_1 != NULL){
            for(i=0; str_1[i] != NULL; i++){
                num++;
            }
        }
        
        
        /* using strtok function with " " */
        char ***str_2 = (char ***)malloc(sizeof(char **) * num);
        
        for(i=0; i<num; i++){
            str_2[num2] = tok(str_1[i], " ");
            num2++;
        }
        
        
        for(i=0;i<num2;i++){
            pid_t pid;
            
            if (strcmp(str_2[i][0], "quit") == 0)
                exit(0);
            
            if((pid = fork())<0){
                printf("ERROR: forking child process failed\n");
                exit(1);
            }
            
            else if(pid == 0) {
                if (execvp(str_2[i][0], str_2[i]) < 0) {
                    printf("ERROR: exec failed\n");
                    exit(1);
                }
            }
            
            else{
                while (wait(&status) != pid);
            }
            
        }
        
        for(i = 0; i < num2; i++) {
            for(j=0; str_2[i] != NULL;j++){
                free(str_2[i]);
            }
            free(str_2);
            
        }
        
        
        for(i = 0; str_1[i] != NULL; i++){
            free(str_1[i]);
        }
        
        
        //
        //        for(i = 0; i < num2; i++) {
        //            free(str_2[i]);
        //        }
        //        free(str_1);
        //
        //
        
        
        //        pid_t pid;
        //        int status;
        //
        //        if((pid = fork()) <0 ){
        //            printf("error : cannot execute fork function\n");
        //            exit(1);
        //        }
        //
        //        else if (pid == 0){
        //            while(fgets(str, MAX_SIZE, fp)){
        //                idx = tok(str_save, str);
        //            }
        //
        //            for(i = 0 ; i < idx ; i++){
        //                printf("%c\n", str_save[i]);
        //                execvp(str_save[i], str_save);
        //            }
        //
        //            if(execvp(str_save[i], str_save)<0){
        //                printf("error\n");
        //                exit(1);
        //            }
        //            
        //        }
        //        
        //        else {
        //            while (wait(&status) != pid);
        //        }
        //        
        //    }
        
        
    }
    
    
    return 0;
}


