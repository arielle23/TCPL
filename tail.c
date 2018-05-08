/*输入字符串，每行以回车结尾，以空输入结束，可选参数-n，默认打印后2行，或者后N行*/
/*date:2018.3.28*/
/*author:Arielle*/
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100
#define MAX_LINE 100

int getLine(char *line,int);
void write(char *lines[],int nlines,int n);
int getint(char *line);

int main(int argc,char *argv[]){
    int len,n;
    int nline = 0;
    char *lines[MAX_LINE];
    char line[MAX_SIZE];
    while((len = getLine(line,MAX_SIZE)) > 0){
        lines[nline] = malloc(len + 1);
        strcpy(lines[nline++],line);
    }
    if(argc == 1){
        n = 2;
        write(lines,nline,n);
    }
    else if(argc == 2 && **++argv == '-')
        write(lines,nline,getint(*argv));
    else
        printf("error input");
    return 0;
}

int getLine(char *line,int n){
    int i,c;
    for(i = 0;i < n && (c = getchar()) != '\n';i++)
        *line++ = c;
    *line = '\0';
    return i;
}

int getint(char *s){
    s++;
    int ret = 0;
    while(isdigit(*s) && *s != '\0'){
        ret = ret * 10 + (*s++ - '0');  
    }
    if(*s == '\0')
        return ret;
    else
        return -1;
}

void write(char *lines[],int nlines,int n){
    int i;
    if(n > nlines)
        printf("error input");
    for(i = n;i >= 1;i--)
        printf("%s\n",lines[nlines - i]);
}

