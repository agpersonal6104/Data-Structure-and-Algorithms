#include <stdio.h>
#include <ctype.h>

char *input;
char lookahead;

void nextToken() {
    lookahead = *input++;
}

void error() {
    printf("Syntax Error\n");
    exit(1);
}

void match(char token) {
    if (lookahead == token) {
        nextToken();
    } else {
        error();
    }
}

void expr();
void term();
void factor();

void expr() {
    term();
    while (lookahead == '+' || lookahead == '-') {
        if (lookahead == '+') {
            match('+');
            term();
            printf("+ ");
        } else if (lookahead == '-') {
            match('-');
            term();
            printf("- ");
        }
    }
}

void term() {
    factor();
    while (lookahead == '*' || lookahead == '/') {
        if (lookahead == '*') {
            match('*');
            factor();
            printf("* ");
        } else if (lookahead == '/') {
            match('/');
            factor();
            printf("/ ");
        }
    }
}

void factor() {
    if (isdigit(lookahead)) {
        printf("%c ", lookahead);
        match(lookahead);
    } else if (lookahead == '(') {
        match('(');
        expr();
        match(')');
    } else {
        error();
    }
}

int main() {
    char inputExpr[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", inputExpr);
    input = inputExpr;
    nextToken();
    expr();
    if (lookahead == '\0') {
        printf("\nParsing completed successfully.\n");
    } else {
        error();
    }
    return 0;
}