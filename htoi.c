/*将以“0x”开头的16进制数转为10进制*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

int gethNumber(int n, char *number);
int htoi(char *number);

int main() {
    char number[MAX_SIZE];
    if (gethNumber(2, number) > 0) {
        // printf("the number is: %s\n",number);
        printf("the resulet is: %d\n", htoi(number));
        return 0;
    } else
        return -1;
}

int gethNumber(int n, char *number) {
    char c;
    int i;
    for (i = 0; i < MAX_SIZE && (c = getchar()) != '\n'; i++) {
        number[i] = c;
    }
    number[i] = '\0';
    if(strncmp(number,"0x",2) && strncmp(number,"0X",2)){
        printf("wrong format");
        return -1;
    }
    else 
        return i;
}

long htoi(char *number) {
    int len = strlen(number);
    long n = 0;
    for (int i = 2; i < len; i++) {
        if (isdigit(number[i])) {
            n = 16 * n + (number[i] - '0');
        } else if (number[i] >= 'A' && number[i] <= 'F') {
            n = 16 * n + (number[i] - 'A' + 10);
        } else if (number[i] >= 'a' && number[i] <= 'f') {
            n = 16 * n + (number[i] - 'a' + 10);
        } else {
            printf("wrong number");
            exit(EXIT_FAILURE);
        }
    }
    return n;
}

