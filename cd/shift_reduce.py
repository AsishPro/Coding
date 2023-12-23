grammar = [
    ("E", "E + E"),  # Addition
    ("E", "E * E"),  # Multiplication
    ("E", "id")       # Identifier
]

class ShiftReduceParser:
    def __init__(self, grammar, input_string):
        self.grammar = grammar
        self.input_string = input_string
        self.stack = []
        self.index = 0

    def shift(self):
        self.stack.append(self.input_string[self.index])
        self.index += 1

    def reduce(self):
        for rule in self.grammar:
            left_hand_side, right_hand_side = rule
            if self.stack[-len(right_hand_side):] == list(right_hand_side):
                for _ in range(len(right_hand_side)):
                    self.stack.pop()
                self.stack.append(left_hand_side)
                return True
        return False

    def parse(self):
        while self.index < len(self.input_string):
            if self.reduce():
                continue
            self.shift()

        # Check if the final stack contains only the start symbol
        if len(self.stack) == 1 and self.stack[0] == self.grammar[0][0]:
            return True
        else:
            return False

input_string = "id+id*id"
parser = ShiftReduceParser(grammar, input_string)

if parser.parse():
    print("Input string is accepted by the grammar.")
else:
    print("Input string is not accepted by the grammar.")
