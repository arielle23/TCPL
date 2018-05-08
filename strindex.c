/*在一串字符串中找另一串的首次出现的位置，返回位置*/
/*date:2018.3.3*/
/*author:Arielle*/

#include<stdio.h>
#define MAX_SIZE 100
int getLine(char *str,int max);
int strIndex(char *source,char *pattern);

int main(){
    int sourcelen,patternlen,ret;
    char source[MAX_SIZE];
    char pattern[MAX_SIZE];
    if((sourcelen = getLine(source,MAX_SIZE)) > 0){
        if((patternlen  = getLine(pattern,MAX_SIZE)) <= sourcelen && patternlen > 0){
            if((ret = strIndex(source,pattern)) > 0){
                printf("find pattern string in: %d\n",ret);
            }
            else    
                printf("can't find pattern string\n");
        }
        else
            printf("worng pattern string\n");
    }
    else
        printf("wrong source string\n");
    return 0;
}

int getLine(char *str,int max){
    int c,i;
    for(i = 0;i < max && (c = getchar()) != '\n'; i++){
        str[i] = c;
    }
    // str[i++] = '\n';
    str[i] = '\0';
    return i;
}

int strIndex(char *source,char *pattern){
    int i,j,k;
    for(i = 0; source[i] != '\0'; i++){
        for(j = i,k = 0;pattern[k] != '\0' && source[j] == pattern[k];j++,k++)
            printf("%d %d %d\n",j,k,i);
        if(k > 0 && pattern[k] == '\0')
            return i;
    }
    return -1;
}

