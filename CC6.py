import re

class RecursiveDescentParser:
    def __init__(self, expression):
        self.tokens = re.findall(r'\d+|[+*/()-]', expression)
        self.index = 0

    def parse(self):
        print("Entering E")
        result = self.expr()
        print("Exiting E")
        return result

    def expr(self):  # E -> T {( '+' | '-' ) T}
        print("Entering T")
        result = self.term()
        print("Exiting T")
        while self.index < len(self.tokens) and self.tokens[self.index] in ('+', '-'):
            operator = self.tokens[self.index]
            print(f"Found operator: {operator}")
            self.index += 1
            print("Entering T")
            right = self.term()
            print("Exiting T")
            result = f"({result} {operator} {right})"
        return result

    def term(self):  # T -> F {( '*' | '/' ) F}
        print("Entering F")
        result = self.factor()
        print("Exiting F")
        while self.index < len(self.tokens) and self.tokens[self.index] in ('*', '/'):
            operator = self.tokens[self.index]
            print(f"Found operator: {operator}")
            self.index += 1
            print("Entering F")
            right = self.factor()
            print("Exiting F")
            result = f"({result} {operator} {right})"
        return result

    def factor(self):  # F -> NUMBER | '(' E ')'
        token = self.tokens[self.index]
        if token.isdigit():
            self.index += 1
            print(f"Exiting F with id: {token}")
            return token
        elif token == '(':
            self.index += 1
            print("Entering E")
            result = self.expr()
            print("Exiting E")
            if self.index < len(self.tokens) and self.tokens[self.index] == ')':
                self.index += 1
                print("Exiting F with parentheses")
                return f"({result})"
            else:
                raise SyntaxError("Expected closing parenthesis")
        else:
            raise SyntaxError(f"Unexpected token: {token}")

if __name__ == "__main__":
    expression = input("Enter an arithmetic expression: ")
    parser = RecursiveDescentParser(expression)

    try:
        parsed_expression = parser.parse()
        print(f"\nParsed expression: {parsed_expression}")
    except Exception as e:
        print("ERROR!", e)