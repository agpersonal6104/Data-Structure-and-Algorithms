class CLRParser:
    def __init__(self, grammar):
        self.grammar = grammar
        self.states = []
        self.action_table = {}
        self.goto_table = {}
        self.start_symbol = list(grammar.keys())[0]
        self.augmented_grammar = self.augment_grammar()
        self.build_parser()

    def augment_grammar(self):
        augmented_grammar = {'S\'': [self.start_symbol]}  # Add augmented start symbol S'
        augmented_grammar.update(self.grammar)
        return augmented_grammar

    def closure(self, items):
        closure_set = set(items)
        added = True
        while added:
            added = False
            new_items = set()
            for item in closure_set:
                head, body, dot_pos, lookahead = item
                if dot_pos < len(body) and body[dot_pos].isupper():  # Non-terminal after dot
                    non_terminal = body[dot_pos]
                    for production in self.augmented_grammar[non_terminal]:
                        new_item = (non_terminal, production, 0, lookahead)
                        if new_item not in closure_set:
                            new_items.add(new_item)
                            added = True
            closure_set.update(new_items)
        return closure_set

    def goto(self, items, symbol):
        goto_set = set()
        for item in items:
            head, body, dot_pos, lookahead = item
            if dot_pos < len(body) and body[dot_pos] == symbol:
                goto_set.add((head, body, dot_pos + 1, lookahead))
        return self.closure(goto_set)

    def build_parser(self):
        print("Building CLR(1) Parsing Table...")
        # Step 1: Construct the canonical collection of LR(1) items
        start_item = ('S\'', self.start_symbol, 0, '$')
        initial_state = self.closure({start_item})
        self.states.append(initial_state)

        added = True
        while added:
            added = False
            for state in self.states:
                for symbol in set(c for item in state for c in item[1]):
                    new_state = self.goto(state, symbol)
                    if new_state and new_state not in self.states:
                        self.states.append(new_state)
                        added = True

        # Step 2: Build ACTION and GOTO tables
        for i, state in enumerate(self.states):
            for item in state:
                head, body, dot_pos, lookahead = item
                if dot_pos == len(body):  # Reduce item
                    if head == 'S\'':
                        self.action_table[(i, '$')] = 'ACCEPT'
                    else:
                        production = f"{head} -> {body}"
                        self.action_table[(i, lookahead)] = f"REDUCE {production}"
                elif body[dot_pos].isupper():  # Non-terminal
                    next_state = self.goto(state, body[dot_pos])
                    if next_state in self.states:
                        self.goto_table[(i, body[dot_pos])] = self.states.index(next_state)
                else:  # Terminal
                    next_state = self.goto(state, body[dot_pos])
                    if next_state in self.states:
                        self.action_table[(i, body[dot_pos])] = f"SHIFT {self.states.index(next_state)}"

    def parse(self, input_string):
        print(f"Parsing input: {input_string}")
        # Placeholder: Implement Parsing Logic
        # This involves using the ACTION and GOTO tables to parse the input.
        return "Accepted" if input_string else "Rejected"

    def display_tables(self):
        print("\nACTION Table:")
        for key, value in sorted(self.action_table.items()):
            print(f"State {key[0]}, Symbol {key[1]}: {value}")

        print("\nGOTO Table:")
        for key, value in sorted(self.goto_table.items()):
            print(f"State {key[0]}, Non-terminal {key[1]}: {value}")


# Example Grammar
grammar = {
    'E': ['E+T', 'T'],
    'T': ['T*F', 'F'],
    'F': ['(E)', 'id']
}

parser = CLRParser(grammar)
parser.display_tables()