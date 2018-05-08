/*读取输入行中的数字，支持正负号*/

#include<stdio.h>
#include<ctype.h>
#define BUFSIZE 100
#define MAXSIZE 100

char buf[BUFSIZE];
int bufpointer = 0;

int getCh(){
    return (bufpointer > 0) ? buf[--bufpointer] : getchar();
}

void ungetCh(char c){
    buf[bufpointer++] = c;
}

int getInt(int *px){
    int c,sign;
    while(isspace(c = getCh()))
        ;
    if (!isdigit(c) && c != '+' && c !='-'){
        // ungetCh(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getCh();
    for(*px = 0;isdigit(c);c = getCh())
        *px = 10 * *px + (c - '0');
    *px *= sign;
    if(c != EOF)
        ungetCh(c);
    return c;
}

int main(){
    int x;
    while(getInt(&x) == 0)
        ;
    printf("%d\n",x);
    while(getInt(&x) == 0)
        ;
    printf("%d",x);
    return 0;
}