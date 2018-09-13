#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void backtrack(char **ret,int *returnSize,int max,char *cur,int left,int right);
char **generateParenthesis(int n, int *returnSize);

int main(){
    char **results;
    int n;
    results = generateParenthesis(0,&n);
    for(int i = 0; i < n; ++i){
        printf("i:%d %s, ",i,results[i]);
    }
    for(int j = 0; j < n; ++j)
        free(results[j]);
    free(results);
    return 0;
}
char** generateParenthesis(int n, int* returnSize) {
    char **ret = (char **)malloc(sizeof(char *) * 100000);
    *returnSize = 0;
    char *cur = (char *)malloc(sizeof(char) * 2 * n + 1);
    memset(cur, sizeof(char) * 2 * n + 1, 0);
    backtrack(ret,returnSize,n,cur,0,0);
    // printf("%d\n",*returnSize);
    // free(cur);
    //for(int i=0; i<*returnSize; ++i)printf("%s\n", ret[i]);
    return ret;
}

void backtrack(char **ret,int *returnSize,int max,char *cur,int left,int right){
    // char *temp1 = (char *)malloc(sizeof(char) * 2 * max + 1);
    // char *temp2 = (char *)malloc(sizeof(char) * 2 * max + 1);
    // strcpy(temp1,cur);
    // strcpy(temp2,cur);
    if(strlen(cur) == (2 * max)){
        // ret[*returnSize] = (char *)malloc(sizeof(char) * max * 2 + 1);
        // strcpy(ret[*returnSize],cur);
        // printf("save:%s\n",cur);
        ret[(*returnSize)++] = cur;
        // free(temp1);
        // free(temp2);
        return;
    }
    if(left < max){
        char *temp = (char *)malloc(sizeof(char) * 2 * max + 1);
        memcpy(temp, cur, sizeof(char) * 2 * max + 1);
        strcat(temp,"(");
        backtrack(ret,returnSize,max,temp,(left + 1),right);
    }
    
    if(right < left){
        char *temp = (char *)malloc(sizeof(char) * 2 * max + 1);
        memcpy(temp, cur, sizeof(char) * 2 * max + 1);
        strcat(temp,")");
        backtrack(ret,returnSize,max,temp,left,(right + 1));
    }
    // free(temp1);
    // free(temp2);
    free(cur);
    return;
}

