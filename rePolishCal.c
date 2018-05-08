/*输入逆波兰式，得到结果，有回退功能*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define BUFMAX 10
#define NUMMAX 100
#define NUMBER 1

int getop(char *s);
void unGetc(char c);
int getC();
void push(double val);
double pop();

char buffer[BUFMAX];
int bufpointer = 0;
double valstack[NUMMAX];
int stackp = 0;

int main(){
    char s[NUMMAX];
    int type;
    double temp;
    // getop(s);
    // printf("%f",atof(s));
    // printf("%d",stackp);
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            printf("%s\n",s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            temp = pop();
            push(pop() - temp);
            break;
        case '/':
            temp = pop();
            push(pop() / temp);
            break;
        case '\n':
            printf("%0.2f\n",pop());
            break;
        }
    }
    return 0;
}

void push(double val){
    valstack[stackp++] = val;
}

double pop(){
    return valstack[--stackp];
}

int getop(char *s){
    char c;
    int i;
    while(isblank(c = getC()))
        ;
    if(!isdigit(c))
        return c;
    else{
        unGetc(c);
        for(i = 0;isdigit(c = getC());i++){
            s[i] = c;//the interger part
        }
        if(c == '.'){ 
            // printf("!\n");
            s[i++] = c;//the point
            while(isdigit(c = getC())){
                s[i++] = c;//the decimal part
            }
            s[i] = '\0';
            if(c != EOF)
                unGetc(c);
        }
        else{
            s[i] = '\0';
            if(c != EOF)
                unGetc(c);
        }  
        return NUMBER;
    }
}

int getC(){
    return (bufpointer > 0) ? buffer[--bufpointer] :
            getchar();
}

void unGetc(char c){
    if(bufpointer == BUFMAX){
        printf("full!");
    }
    else    
        buffer[bufpointer++] = c;
}
