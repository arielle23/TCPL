/*输出含有参数内容的行*/

#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100
int getLine(char *,int);

int main(int argc,char *argv[]){
    char line[MAX_SIZE];
    int found = 0;
    if(argc != 2)
        printf("illegal enter\n");
    else{
        while(getLine(line,MAX_SIZE) > 0){
            if(strstr(line,argv[1]) != NULL){
                found++;
                printf("%s\n",line);
            }
        }
    }
    // getLine(line,MAX_SIZE);
    // printf("%s",line);
    return found;
}

int getLine(char *line,int n){
    int i,c;
    for(i = 0;i < n && (c = getchar()) != EOF && c != '\n';i++)
        *line++ = c;
    *line = '\0';
    return i;
}



