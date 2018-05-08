#include<stdio.h>
int main(){
    char temp[10];
    int i = 8;
    strcat(temp,(char)i);
    strcat(temp,'\0');
    printf("%s",temp);
    return 0;
}
