#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LEN 32

typedef struct {
    char name[MAX_NAME_LEN];
    char type[16];
    int address;
} Symbol;

Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
int address_counter = 0;

void add_symbol(const char *name, const char *type) {
    if (symbol_count >= MAX_SYMBOLS) {
        fprintf(stderr, "Symbol table overflow!\n");
        return;
    }

    Symbol symbol;
    strncpy(symbol.name, name, MAX_NAME_LEN - 1);
    symbol.name[MAX_NAME_LEN - 1] = '\0'; // Ensure null-termination
    strncpy(symbol.type, type, 15);
    symbol.type[15] = '\0'; // Ensure null-termination
    symbol.address = address_counter++;

    symbol_table[symbol_count++] = symbol;
}

void print_symbol_table() {
    printf("Symbol Table:\n");
    printf("------------\n");
    for (int i = 0; i < symbol_count; i++) {
        printf("Name: %s, Type: %s, Address: %d\n", symbol_table[i].name, symbol_table[i].type, symbol_table[i].address);
    }
}

void analyze_code(const char *code) {
    char token[MAX_NAME_LEN];
    int i = 0, j = 0;
    char type[16];

    while (code[i] != '\0') {
        if (isspace(code[i])) {
            i++;
            continue;
        }

        if (isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                token[j++] = code[i++];
            }
            token[j] = '\0';

            if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0 || strcmp(token, "long") == 0) {
                strcpy(type, token);
                while (isspace(code[i])) i++;
                while (code[i] != ';' && code[i] != '\0') {
                    j = 0;
                    while (isalnum(code[i]) || code[i] == '_') {
                        token[j++] = code[i++];
                    }
                    token[j] = '\0';
                    if (j > 0) {
                        add_symbol(token, type);
                    }
                    while (isspace(code[i])) i++;
                    if (code[i] == ',') i++;
                    while (isspace(code[i])) i++;
                }
            }
        } else {
            i++;
        }
    }
}

int main() {
    char code[1000];
    printf("Enter the C program: ");
    fgets(code, sizeof(code), stdin);
    analyze_code(code);
    print_symbol_table();
    return 0;
}