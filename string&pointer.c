#include<stdio.h>

void Swap(char *px,char *py);
char *StringCopy(char *stringA,char *stringB);
int strcompare(char *s,char *t);
char *strcat(char *s,char *t);

int main(void){
    char stringA[10] = "";
    char stringB[10] = "";
    // printf("%d\n",strcompare(stringA,stringB));
    // printf("stringA:%s stringB:%s",StringCopy(stringA,stringB),stringB);
    printf("%s",strcat(stringA,stringB));
    return 0;
}

void Swap(char *px,char *py){
    char temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

char *StringCopy(char *stringA,char *stringB){
    while((*(stringA++) = *(stringB++)) != '\0')
        ;
    return stringB;
}

int strcompare(char *s,char *t){
    for(;*s == *t;*s++,*t++ )
        printf("%c,%c\n",*s,*t);
    if(*s == '\0')
        return 0;
    else
        return *s - *t;
}

char *strcat(char *s,char *t){
    int i = 0;
    for(;*s;s++,i++)
        ;
    while(*s++ = *t++)q
        i++;
    ++i;
    return s - i;
}
