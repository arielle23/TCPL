/*逆波兰式作为参数输入，可实现加法和乘法*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define STACK_MAX 10
#define NUMBER 1

double valstack[STACK_MAX];
int check(char *);
void push(double);
double pop();

int main(int argc,char *argv[]){
    int i;
    for(i = 1;i < argc;i++){
        switch(check(argv[i])){
            case NUMBER:
                push(atof(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':
                push(pop() * pop());
                break;
        }
    }
    printf("%0.2f",pop());
}

int check(char *s){
    if(isdigit(s[0]))
        return NUMBER;
    else    
        return *s;
}

static int stackp = 0;

void push(double val){
    valstack[stackp++] = val; 
}

double pop(){
    return valstack[--stackp];
}