class LLParser:
    def __init__(self, input_string):
        self.input_string = input_string + '$'
        self.index = 0
        self.EOF = '$'
        self.grammar = {
            'E': ['T', 'E1'],
            'E1': ['+', 'T', 'E1'],
            'E1': ['-', 'T', 'E1'],
            'E1': [self.EOF],
            'T': ['F', 'T1'],
            'T1': ['*', 'F', 'T1'],
            'T1': ['/', 'F', 'T1'],
            'T1': [self.EOF],
            'F': ['(', 'E', ')'],
            'F': ['id']
        }
        self.first_sets = {}
        self.follow_sets = {}
        self.construct_first_sets()
        self.construct_follow_sets()

    def parse(self):
        if self.match('E', self.input_string[self.index]) and self.input_string[self.index] == self.EOF:
            print("Parsing successful!")
        else:
            print("Parsing failed!")

    def construct_first_sets(self):
        # Implement logic to compute first sets for grammar symbols
        # For this basic example, I will hardcode the first sets
        self.first_sets = {
            'E': ['(', 'id'],
            'E1': ['+', '-', self.EOF],
            'T': ['(', 'id'],
            'T1': ['*', '/', self.EOF],
            'F': ['(', 'id']
        }

    def construct_follow_sets(self):
        # Implement logic to compute follow sets for grammar symbols
        # For this basic example, I will hardcode the follow sets
        self.follow_sets = {
            'E': [self.EOF, ')'],
            'E1': [self.EOF, ')'],
            'T': ['+', '-', self.EOF, ')'],
            'T1': ['+', '-', self.EOF, ')'],
            'F': ['*', '/', '+', '-', self.EOF, ')']
        }

    def match(self, non_terminal, token):
        if token in self.first_sets[non_terminal]:
            for production in self.grammar[non_terminal]:
                if token in production:
                    for symbol in production:
                        if symbol == token:
                            self.index += 1
                        elif symbol.isupper():
                            if not self.match(symbol, self.input_string[self.index]):
                                return False
                    return True
        elif token in self.follow_sets[non_terminal]:
            return True
        return False


# Example usage
input_string = "id+id-id$"
parser = LLParser(input_string)
parser.parse()
