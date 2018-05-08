/*实现从文件中读取复杂声明，并转为文字声明*/
/*Arielle*/
/*date: 2018.4.4*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTOKEN 100

int tokentype;
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char token[MAXTOKEN];
char out[1000];

int gettoken();
void del(void);
void dirdel(void);

enum { PARENTHES = 256, BRAKET, NAME };

int main(int argc, char *argv[]) {
  if (gettoken() == NAME) {
    strcpy(datatype, token);
    del();
    printf("%s: %s %s", name, out, datatype);
    return 0;
  }
  printf("expected datatype\n");
  return -1;
}

void del() {
  int n;
  for (n = 0; gettoken() == '*';)
    n++;
  dirdel();
  while (n-- > 0) {
    strcat(out, " pointer to");
  }
}

void dirdel() {
  int type;
  if (tokentype == '(') {
    del();
    if (tokentype != ')') {
      printf("expected a left parentthes\n");
    }
  } else if (tokentype == NAME) {
    strcpy(name, token);
  }
  while ((type = gettoken()) == PARENTHES || type == BRAKET) {
    if (tokentype == PARENTHES) {
      strcat(out, " function returning");
    } else if (tokentype == BRAKET) {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}

int gettoken() {
  char *p = token;
  int c;
  while ((c = getc(stdin)) == ' ' || c == '\t')
    ;
  if (c == '\n')
    return -1;
  else if (c == '(') {
    if ((c = getc(stdin)) == ')') {
      strcpy(p, "()");
      return tokentype = PARENTHES;
    } else {
      ungetc(c, stdin);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (c = getc(stdin)) != ']';) {
      *p++ = c;
    }
    *p++ = c;
    *p = '\0';
    return tokentype = BRAKET;
  } else if (isalpha(c)) {
    *p++ = c;
    for (; isalnum((c = getc(stdin))) && !isspace(c); p++)
      *p = c;
    *p = '\0';
    ungetc(c, stdin);
    return tokentype = NAME;
  }
  return tokentype = c;
}
