/*参数-n表示以字符串长度升序排序，不加参数按字典顺序排序*/
/*date:2018.3.18*/
/*author:Arielle*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 1000
#define MAXLINE 100

int getLine(char *string,int max);
void writelines(char *lineptr[],int nlines);
int readlines(char *lineptr[],int max);
char *alloc(int n);
void quicksort(void *lineptr[],int left,int right,int (*op)(void *,void *));
int  strlength(char *s);
void swap(void *lineptr[],int i,int j);
int numcmp(void *s,void *t);

char *lineptr[MAXLINE];

int main(int argc,char *argv[]){
    int numric = 0;
    if(argc > 1 && (strcmp(argv[1],"-n") == 0))
        numric = 1;
    int nlines = readlines(lineptr,MAXLINE);
    // swap((void **)lineptr,0,1);
    quicksort((void **)lineptr,0,nlines - 1,(int (*)(void*,void*)) (numric ?  numcmp:strcmp ));
    // quicksort((void **)lineptr,0,nlines - 1,numcmp);
    writelines(lineptr,nlines);
    return 0;
}

int getLine(char *string,int max){
    int c,i;
    for(i = 0;i < max && (c = getchar()) != '\n';i++)
        *string++ = c;
    *string = '\0';
    string -= i;
    // printf("%d\n",i);
    return i;
}

int readlines(char *lineptr[],int max){
    int nlines,len;
    char line[MAXSIZE];
    nlines = 0;
    while((len = getLine(line,MAXSIZE)) > 0){
        printf("read line:%s\n",line);
        lineptr[nlines] = alloc(len + 1);
        strcpy(lineptr[nlines++],line);
    }
    return nlines;
}

void writelines(char *lineptr[],int nlines){
    int i;
    printf("line:%d\n",nlines);
    for(i = 0;i < nlines;i++){
        printf("%s\n",lineptr[i]);
        printf("line length:%d\n",strlength(lineptr[i]));
    } 
}

#define ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if((allocbuf + ALLOCSIZE - allocp) > n)
        allocp += n;
    return allocp - n;
}

void quicksort(void *v[],int left,int right,int (*op)(void *,void *)){
    int last,i;
    if(left >= right)
        return;
    swap(v,left,(left + right) / 2);
    last = left;
    for(i = left + 1;i <= right;i++){
        // if(strlength(v[i]) < strlength(lineptr[left]))
        if(((*op)(v[i],v[left])) < 0)
            swap(v,i,++last);
    }   

    swap(v,last,left);
    quicksort(v, left,last - 1,op);
    quicksort(v,last + 1,right,op); 
}

void swap(void *v[],int i,int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int strlength(char *s){
    int i = 0;
    for(;*s++ != '\0';i++)
        ;
    return i;
}

int numcmp(void *i,void *left){
    if(strlength(i) > strlength(left))
        return 1;
    else
        return 0;
} 
