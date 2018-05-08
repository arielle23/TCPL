#include<stdio.h>

int main(){
    FILE *fd;
    fd = fopen("test.txt","r");
    int c;
    c = getc(fd);
    // printf("%c",c);
    print();
}

void print(){
    printf("%c",c);
}