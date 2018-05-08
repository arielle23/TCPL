#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100
void strct(char *,char *);
int strend(char *,char *);
void strncp(char *,char *,int);
void strnct(char *,char *,int);
int strncm(char *,char *,int);
static int a = 2;

int main(){
    char s[MAX_SIZE] = "firststring";
    char t[] = "string";
    strct(s,t);
    a = 3;
    printf("%d",a);
    printf("strcat:%s\n",s);
    printf("strend:%d\n",strend(s,t));
    strncp(s,t,3);
    printf("strncopy:%s\n",s);
    strnct(s,t,4);
    printf("strncat:%s\n",s);
    printf("strncmp:%d",strncm(s,t,3));
    return 0;
}

void strct(char *s,char *t){
    while(*s)
        s++;                        //concatenate t to s
    while(*s++ = *t++)
        ;
}

int strend(char *s,char *t){
    char *p = t;
    while(*s)
        s++;                    
    while(*t)                       //check s end with t
        t++;
    for(;*s == *t;s--,t--)
        ;
    return ((t + 1)== p ) ? 1 : 0;
}

void strncp(char *s,char *t,int n){
    int i;  
    for(i = 0;i < n;i++,s++,t++)    //copy t to s;
        *s = *t;
    *s = '\0';
}

void strnct(char *s,char *t,int n){
    int i;
    while(*s)                       //n characters in t concatenate to s
        s++;
    for(i = 0;i < n;t++,s++,i++)
        *s = *t;
    *s = '\0';
}

int strncm(char *s,char *t,int n){
    int i;
    for(i = 0;i < n && *s == *t;i++,s++,t++)
        ;
    return (i == n - 1) ? 0 : 1;
}
