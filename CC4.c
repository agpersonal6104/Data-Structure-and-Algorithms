#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LEN 32

typedef struct {
    char name[MAX_NAME_LEN];
    char type[16];
    int address;
} Symbol;

Symbol symbol_table[MAX_SYMBOLS]; // Changed to store Symbol structs
int symbol_count = 0;

void add_symbol(const char *name, const char *type, int address) {
    if (symbol_count >= MAX_SYMBOLS) {
        fprintf(stderr, "Symbol table overflow!\n");
        return;
    }

    Symbol symbol;
    strncpy(symbol.name, name, MAX_NAME_LEN - 1);
    symbol.name[MAX_NAME_LEN - 1] = '\0'; // Ensure null-termination
    strncpy(symbol.type, type, 15);
    symbol.type[15] = '\0'; // Ensure null-termination
    symbol.address = address;

    symbol_table[symbol_count++] = symbol;
}

void print_symbol_table() {
    printf("Symbol Table:\n");
    printf("------------\n");
    for (int i = 0; i < symbol_count; i++) {
        printf("Name: %s, Type: %s, Address: %d\n", symbol_table[i].name, symbol_table[i].type, symbol_table[i].address);
    }
}

int main() {
    add_symbol("x", "int", 100);
    add_symbol("y", "float", 200);
    print_symbol_table();
    return 0;
}