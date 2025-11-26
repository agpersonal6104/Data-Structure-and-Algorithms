class LALRParser:
    def __init__(self, grammar):
        self.grammar = grammar
        self.states = []
        self.action_table = {}
        self.goto_table = {}
        self.build_parser()

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
                    for production in self.grammar[non_terminal]:
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
        print("Building LALR(1) Parsing Table...")
        # Step 1: Construct the canonical collection of LR(1) items
        start_item = ('S\'', self.grammar['S\''][0], 0, '$')
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

        # Step 2: Merge compatible states to create LALR(1) states
        # Placeholder: Implement state merging logic for LALR(1)

        # Step 3: Build ACTION and GOTO tables
        for i, state in enumerate(self.states):
            for item in state:
                head, body, dot_pos, lookahead = item
                if dot_pos == len(body):  # Reduce item
                    if head == 'S\'':
                        self.action_table[(i, '$')] = 'ACCEPT'
                    else:
                        production = f"{head} -> {body}"
                        self.action_table[(i, lookahead)] = f"REDUCE {production}"
                elif dot_pos < len(body):  # Shift or GOTO
                    symbol = body[dot_pos]
                    next_state = self.goto(state, symbol)
                    if next_state in self.states:
                        next_state_index = self.states.index(next_state)
                        if symbol.isupper():  # Non-terminal
                            self.goto_table[(i, symbol)] = next_state_index
                        else:  # Terminal
                            self.action_table[(i, symbol)] = f"SHIFT {next_state_index}"

    def parse(self, input_string):
        print(f"Parsing input: {input_string}")
        # Placeholder: Implement Parsing Logic
        return "Accepted" if input_string else "Rejected"

    def display_tables(self):
        print("\nACTION Table:")
        print(f"{'State':<10}{'Symbol':<10}{'Action':<20}")
        for key, value in sorted(self.action_table.items()):
            print(f"{key[0]:<10}{key[1]:<10}{value:<20}")

        print("\nGOTO Table:")
        print(f"{'State':<10}{'Non-terminal':<15}{'Next State':<10}")
        for key, value in sorted(self.goto_table.items()):
            print(f"{key[0]:<10}{key[1]:<15}{value:<10}")


# Example Grammar
grammar = {
    'S\'': ['E'],
    'E': ['E+T', 'T'],
    'T': ['T*F', 'F'],
    'F': ['(E)', 'id']
}

parser = LALRParser(grammar)
parser.display_tables()