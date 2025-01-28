#include <stdio.h>
#include <ctype.h>
#include <string.h>

void identifyToken(char *token) {
    if (isalpha(token[0]) || token[0] == '_') {
        printf("Identifier: %s\n", token);
    } else if (isdigit(token[0])) {
        printf("Constant: %s\n", token);
    } else if (strchr("+-*/%=<>!&|^", token[0])) {
        printf("Operator: %s\n", token);
    } else {
        printf("Unknown: %s\n", token);
    }
}

void analyze(char *code) {
    char token[100];
    int i = 0, j = 0;

    while (code[i] != '\0') {
        if (isspace(code[i])) {
            i++;
            continue;
        }

        if (code[i] == '/' && code[i + 1] == '/') {
            while (code[i] != '\n' && code[i] != '\0') {
                i++;
            }
            printf("Comment: //\n");
            continue;
        }

        if (code[i] == '/' && code[i + 1] == '*') {
            i += 2;
            while (!(code[i] == '*' && code[i + 1] == '/') && code[i] != '\0') {
                i++;
            }
            if (code[i] != '\0') {
                i += 2;
            }
            printf("Comment: /* */\n");
            continue;
        }

        j = 0;
        while (!isspace(code[i]) && code[i] != '\0' && !strchr("+-*/%=<>!&|^", code[i])) {
            token[j++] = code[i++];
        }
        token[j] = '\0';

        if (j > 0) {
            identifyToken(token);
        }

        if (strchr("+-*/%=<>!&|^", code[i])) {
            token[0] = code[i++];
            token[1] = '\0';
            identifyToken(token);
        }
    }
}

int main() {
    char code[] = "#include<stdio.h> void main() { int a,b,c; clrscr(); printf(\"enter two numbers\"); scanf(\"%d%d\",&a,&b); c=a+b; printf(\"Sum of two numbers is %d\",c); getch(); }";
    analyze(code);
    return 0;
}