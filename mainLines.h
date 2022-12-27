#ifndef MAINLINES_H
#define MAINLINES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100

//part d
void check_comment (char) ;  // checks for both types of comments, then passes on control to below comments
void block_comment () ;   //  handles block or multiline comments
void single_comment () ;   // handles single line comments
FILE *fp , *fp2;

int mainLines(FILE* fp1, char filename[MAX_FILE_NAME]){
    char c;
    fp = fopen ("readingfile.txt","r") ;   // open the first file in read mode
    fp2 = fopen ("file.txt","w") ;    // open the second file in write mode
    while((c=fgetc(fp))!=EOF)       // read the file character by character
        check_comment(c); 
    fclose(fp);
    fclose(fp2);
    return 0;
}	

void check_comment(char c){
    char d;
    if( c == '#') {
          single_comment();
		}
    else
        fputc(c,fp2);
}

void single_comment(){
 char d,e;
    while((d=fgetc(fp))!=EOF) {
        if(d=='\n') 
            return; 
    }
}

#endif