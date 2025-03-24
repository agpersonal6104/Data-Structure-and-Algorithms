import re

class RecursiveDescentParser:
    def __init__(self, expression):
        self.tokens = re.findall(r'\d+|[+*/()-]', expression)
        self.index = 0
        self.leftmost_steps = []
        self.rightmost_steps = []

    def parse(self):
        print(f"Enter an arithmetic expression: {' '.join(self.tokens)}\n")

        # Leftmost Derivation
        print("Leftmost Derivation:")
        self.leftmost_steps.append("E")
        result = self.expr(leftmost=True)
        for step in self.leftmost_steps:
            print(step)

        print("\nRightmost Derivation:")
        self.rightmost_steps.append("E")
        self.index = 0  # Reset index for rightmost derivation
        self.expr(leftmost=False)
        for step in reversed(self.rightmost_steps):
            print(step)

        print("\n=== Code Execution Successful ===")

    def expr(self, leftmost=True):
        self.add_derivation("E -> T", leftmost)
        result = self.term(leftmost)
        while self.index < len(self.tokens) and self.tokens[self.index] in ('+', '-'):
            operator = self.tokens[self.index]
            self.index += 1
            self.add_derivation(f"E -> T {operator} E", leftmost)
            right = self.term(leftmost)
            result = f"({result} {operator} {right})"
        return result

    def term(self, leftmost=True):
        self.add_derivation("T -> F", leftmost)
        result = self.factor(leftmost)
        while self.index < len(self.tokens) and self.tokens[self.index] in ('*', '/'):
            operator = self.tokens[self.index]
            self.index += 1
            self.add_derivation(f"T -> F {operator} T", leftmost)
            right = self.factor(leftmost)
            result = f"({result} {operator} {right})"
        return result

    def factor(self, leftmost=True):
        token = self.tokens[self.index]
        if token.isdigit():
            self.index += 1
            self.add_derivation("F -> id", leftmost)
            print(f"Read: {token}")
            return token
        elif token == '(':
            self.index += 1
            self.add_derivation("F -> ( E )", leftmost)
            result = self.expr(leftmost)
            if self.index < len(self.tokens) and self.tokens[self.index] == ')':
                self.index += 1
                return f"({result})"
            else:
                raise SyntaxError("Expected closing parenthesis")
        else:
            raise SyntaxError(f"Unexpected token: {token}")

    def add_derivation(self, rule, leftmost):
        if leftmost:
            self.leftmost_steps.append(rule)
        else:
            self.rightmost_steps.append(rule)

if __name__ == "__main__":
    expression = input("Enter an arithmetic expression: ")
    parser = RecursiveDescentParser(expression)
    try:
        parser.parse()
    except Exception as e:
        print("ERROR!", e)