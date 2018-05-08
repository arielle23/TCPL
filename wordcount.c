/*读取输入中的单词，并统计每个单词出现的次数(单词只能是英文字母组成，并以空格分隔),输入以换行符结束*/
/*date:2018.4.12*/
/*author:Arielle*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100

struct tnode{
    char *word;
    int count;
    struct tnode *leftNode;
    struct tnode *rightNode;
};

int getword(char *word,int max);
void printTree(struct tnode *node);
char *strdrup(char *w);
struct tnode *addTree(struct tnode *node,char *w);
struct tnode *talloc();

int main(){
    struct tnode *root = NULL;
    int c;
    char word[MAXWORD];
    while((c = getword(word,MAXWORD))  > 0){
        root = addTree(root,word);
    }
    printTree(root);
    return 0;
}

void printTree(struct tnode *node){
    if(node != NULL){
        printTree(node -> leftNode);
        printf("%s:%d\n",node -> word,node -> count);
        printTree(node -> rightNode);
    }
    // else{
    //     printf("this node is NULL\n");
    // }
}

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

struct tnode *talloc(){
    return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *addTree(struct tnode *node,char *s){
    int r;
    if(node == NULL){
        if((node = talloc()) == NULL)
            printf("分配空间失败");
        node->count = 1;
        node->word = strdrup(s);
        node->leftNode = node->rightNode = NULL;//if this is a new word,create a new node; 
    }
    else if((r = strcmp(node->word,s)) == 0)
        node->count++;//if it's not the first time the word show up,count++
    else if(r < 0)
        node->rightNode = addTree(node->rightNode,s);
    else if(r > 0)
        node->leftNode = addTree(node->leftNode,s);
    return node;
}

char *strdrup(char *w){
    char *p = (char *)malloc(sizeof(strlen(w)));
    if(p != NULL)
        strcpy(p,w);
    return p;
}

