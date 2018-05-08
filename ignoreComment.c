/*将输入行中的C注释去掉*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
#define IN 1
#define OUT 0

int state = 0;
int getLine();
void ignoreComment(char *, int len);
int check(char line[], int len, int begin, const char *target, int targetLen);

int main() {
    int len;
    char line[MAX_SIZE];
    while ((len = getLine(line, MAX_SIZE)) > 0) {
        ignoreComment(line, len);
        printf("%s\n", line);
    }
    return 0;
}

int getLine(char *line, int max) {
    char c;
    int len;
    for (len = 0; len < max && (c = getchar()) != EOF && c != '\n'; ++len) {
        line[len] = c;
    }
    if (c == '\n') {
        line[len] = c;
        len++;
    }
    line[len] = '\0';
    return len;
}

void ignoreComment(char *line, int len) {
    int begin, j, p, k;
    while (1) {
        if (state == IN) {
            if ((p = check(line, len, 0, "*/", 2))) {
                for (begin = 0, j = p + 1; j < len - 1; begin++, j++) {
                    line[begin] = line[j];
                }
                line[begin] = '\0';
                state = OUT;
                if (!check(line,strlen(line), 0, "*/", 2) &&
                    !check(line,strlen(line), 0, "//", 2)) {
                    break;
                }
            } else { // no */
                line[0] = '\0';
                break;
            }
        } else // state = OUT
        {
            if ((p = check(line, len, 0, "//", 2))) {
                line[p - 1] = '\0';
                if (!check(line,strlen(line), 0, "/*", 2))
                    return;
            } else if ((p = check(line,strlen(line), 0, "/*", 2))) {
                state = IN;
                if ((k = check(line, len, p + 1, "*/", 2))) {
                    state = OUT;
                    for (begin = p - 1, j = k + 1; j < len - 1; begin++, j++) {
                        line[begin] = line[j];
                    }
                    line[begin] = '\0';
                    if (check(line,strlen(line), 0, "/*", 2) == 0 &&
                        check(line,strlen(line), 0, "//", 2) == 0) {
                        return;
                    }
                } else {
                    line[p - 1] = '\0';
                    break;
                }
            } else
                break;
        }
    }
}

int check(char line[], int len, int begin, const char *target, int targetLen) {
    for (int j = begin; j < len - strlen(target) + 1; j++) {
        if (!strncmp(line + j, target, targetLen)) {
            return j + 1;
        }
    }
    return 0;
}

