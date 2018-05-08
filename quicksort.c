/*实现对整形数组内容的快速升序排序*/

#include<stdio.h>
#define MAX_SIZE 10

void quicksort(int v[],int left,int right);
void swap(int v[],int i,int j);

int main(){
    int v[MAX_SIZE];
    int i;
    // printf("!");
    for(i = 0;i < MAX_SIZE;i++){
        scanf("%d",&v[i]);
    }
    quicksort(v,0,MAX_SIZE);
    for(i = 0;i < MAX_SIZE;i++)
        printf("%d ",v[i]);
    // printf("!");
    return 0;
}

void quicksort(int v[],int left,int right){
    int last,i;
    if(left >= right)
        return;
    swap(v,left,(right + left) / 2);
    last = left;
    for(i = left + 1;i <= right;i++){
        if(v[i] < v[left])
            swap(v,++last,i);
    }
    swap(v,left,last);
    quicksort(v,left,last - 1);
    quicksort(v,last + 1,right);
}

void swap(int v[],int i,int j){
    int temp;
    temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}