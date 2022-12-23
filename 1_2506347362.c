#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100

// part a
int splittingLine(FILE* ptr, char filename[MAX_FILE_NAME]){
	
	ptr = fopen(filename, "a+");
	if (NULL == ptr) {
		printf("file can't be opened \n");
		return 0;
	}
	
	char str[50];
	printf("content of this file are: \n");
	char * pch;
	while (fgets(str, 50, ptr) != NULL) {
		pch = strtok (str," \n");
		if(strcmp ("EOF", pch) != 0){
			printf("%s\n", pch);
		}
	}
	printf("\n");
	fclose(ptr);
	return 0;
}

// part f
int numberOfLines(FILE* fp, char filename[MAX_FILE_NAME]){
	
	int count = 0;
	char c; // To store a character read from file

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s", filename);
		return 0;
	}
	
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') 
			count = count + 1;

	fclose(fp);
	printf("The file %s has %d lines \n", filename, count);
	printf("\n");

	return 0;
}

// part g
int tenFirstLine(FILE* ptr, char filename[MAX_FILE_NAME]){
	int count = 0;
	ptr = fopen(filename, "a+");
	if (NULL == ptr) {
		printf("file can't be opened \n");
		return 0;
	}
	
	char str[50];
	printf("content of this file are: \n");
	char * pch;
	while (fgets(str, 50, ptr) != NULL && count<10) {
		if(strcmp ("EOF", str) != 0){
			printf("%s", str);
			count = count + 1;
		}
	}
	printf("\n");
	fclose(ptr);
	return 0;
}
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
         if((ch=='/ ')&&(flag==0)){
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

//part d
void check_comment (char) ;  // checks for both types of comments, then passes on control to below comments
void block_comment () ;   //  handles block or multiline comments
void single_comment () ;   // handles single line comments
FILE *fp , *fp2;

void mainLines(FILE* fp1, char filename[MAX_FILE_NAME]){
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
int main()
{
	FILE* ptr;
	char filename[MAX_FILE_NAME];
	splittingLine(ptr, "readingfile.txt");
	numberOfLines(ptr, "readingfile.txt");
	tenFirstLine(ptr, "readingfile.txt");
	rmvEmpty(ptr, "readingfile.txt");
	mainLines(ptr, "readingfile.txt");
}









