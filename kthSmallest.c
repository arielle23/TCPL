/* Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix. */
/* Note that it is the kth smallest element in the sorted order, not the kth distinct element. */

/* author:Arielle */
/* date:2018.5.24 */

#include<stdio.h>
#include<stdlib.h>

struct node *findMin(struct node *arr,int *size);
int kthSmallest(int matrix[][3],int matrixRowSize,int matrixColSize,int k);

struct node{
    int x;
    int y;
    int val;
};

int main(){
    int matrix[3][3] = {{1,5,9},{10,11,13},{12,13,15}};
    printf("the result:%d",kthSmallest(matrix,3,3,8));
    return 0;
}
int kthSmallest(int matrix[][3], int matrixRowSize, int matrixColSize, int k) {
    struct node *temp;
    int exist[matrixRowSize][matrixColSize];
    int ret,row,col,length;
    struct node arr[matrixRowSize * matrixColSize];
    for(int i = 0;i < matrixRowSize;i++)
        for(int j = 0;j < matrixColSize;j++)
            exist[i][j] = 1;
    length = row = col = 0;
    if(k-- == 1){
        ret = matrix[0][0];
    }
    else{
        for(ret = matrix[0][0]; k > 0; k--){
                if(col < matrixColSize - 1 && exist[row][col + 1]){
                    arr[++length].x = row;
                    arr[length].y = col + 1;
                    arr[length].val = matrix[row][col + 1];
                    exist[row][col + 1] = 0;
                }
                if(row < matrixRowSize - 1 && exist[row + 1][col]){
                    arr[++length].x = row + 1;
                    arr[length].y = col;
                    arr[length].val = matrix[row + 1][col];
                    exist[row + 1][col] = 0;
                }
            temp = findMin(arr,&length);
            row = temp -> x;
            col = temp -> y;
            ret = temp -> val;
            free(temp);
        }
    }
    return ret;
}

struct node *findMin(struct node *arr,int *size){
    struct node *ret = (struct node *)malloc(sizeof(struct node));
    int stat = 1;
    ret -> val= (arr + 1) -> val;
    ret -> x = (arr + 1) -> x;
    ret -> y= (arr + 1) -> y;
    for(int i = 1; i <= *size; i++ ){
        if((arr + i) -> val <  ret -> val){
            stat = 1;
            ret -> val = (arr + i) -> val;
            ret -> x = (arr + i) -> x;
            ret -> y = (arr + i) -> y;
            stat = i;
        }
    }
    if(stat != (*size)){
        (arr + stat) -> val = (arr + (*size)) -> val;
        (arr + stat) -> x = (arr + (*size)) -> x;
        (arr + stat) -> y = (arr + (*size)) -> y;
    }
    --(*size);
    return ret;
}



































































