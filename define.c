/*使用哈希表实现字符替换*/
/*date:20182.13*/
/*author:Arielle*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 100
#define MAXWORD 20

struct list{
    struct list *next;
    char *name;
    char *def;
};

int getword(char *word,int max);
unsigned hash(char *s);

int getword(char *word,int max){
    int c,n;
    while((c = getc(stdin))  == ' ' || c == '\t')
        ;
    if(c == '\n')
        return -1;
    for(n = 0;isalpha(c) && n < max;c = getc(stdin),n++)
        *word++ = c;
    if(c == ' ' || c == '\t' || c == '\n'){
        ungetc(c,stdin);
        *word = '\0';
        return 1;
    }
    else{
        printf("error input");
        return -1;
    }
}

unsigned hash(char *s){
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

