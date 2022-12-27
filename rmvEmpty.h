#ifndef RMVEMPTY_H
#define RMVEMPTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100

// part c
int rmvEmpty(FILE* fp1, char filename[MAX_FILE_NAME]){

    int flag=0;
    char ch;
    fp1=fopen(filename,"r");
    if(fp1==NULL)
    {
        printf("Error while opening a file for reading");
        return 0;
    }
    while((ch=fgetc(fp1))!=EOF)
    {
         if((ch=='/')&&(flag==0)){ // should be (ch=='/ ')
            flag=1;
            continue;
        }
        else if((ch=='/')&&(flag==1)){
            flag=2;
            continue;
        }
        else if((ch=='*')&&(flag==1)){
            flag=3;
            continue;
        }
        if(flag==2){
            if(ch=='n')
            {
              flag=0;
            }
            continue;
        }
        if(flag==3){
            if(ch=='*'){
              flag=4;
            }
            continue;
        }
        if(flag==4){
            if(ch=='/'){
              flag=0;
            }
            continue;
        }
        if(flag==0){
            if((ch==13)||(ch==10)){
                continue;
            }
            else if((ch!=' ')){
               printf("%c", ch);
            }
        }
    }
    fclose(fp1);
    fp1=fopen("file1.c","r");
    while((ch=fgetc(fp1))!=EOF){
        printf("%c",ch);
    }
    fclose(fp1);
    return 0;
}


#endif