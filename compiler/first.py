# Define a grammar
grammar={
    'E': ['TR'],
    'R': ['+TR', ''],
    'T': ['FY'],
    'Y': ['*FY',''],
    'F': ['(E)','i']
}

# Initialize First and Follow sets
first = {}
follow = {}

def calculate_first(productions, symbol):
    if symbol in first:
        return first[symbol]
    
    first_set = set()
    for production in productions[symbol]:
        if production == '':
            first_set.add('')
        else:
            for char in production:
                if not char.isupper():
                    first_set.add(char)
                    break
                elif char.isupper():
                    first_set.update(calculate_first(productions, char))
                    if '' not in first[char]:
                        break
    first[symbol] = first_set
    return first_set


# Calculate Follow sets
def calculate_follow(productions, symbol):
    if symbol in follow:
        return follow[symbol]
    
    follow_set = set()
    if symbol == 'E':
        follow_set.add('$')
    
    for key, value in productions.items():
        for production in value:
            idx = production.find(symbol)
            if idx != -1:
                if idx == len(production) - 1:
                    if key != symbol:
                        follow_set.update(calculate_follow(productions, key))
                else:
                        next_char = production[idx + 1]
                        if not next_char.isupper() or next_char == '':
                            follow_set.add(next_char)
                        elif next_char.isupper():
                            first_next = calculate_first(productions, next_char)
                            if '' in first_next:
                                follow_set.update(calculate_follow(productions, key))
                            follow_set.update(first_next - {''})
        follow[symbol] = follow_set
    return follow_set

# Calculate First and Follow sets for the given grammar
for symbol in grammar.keys():
    calculate_first(grammar, symbol)
    calculate_follow(grammar, symbol)

# # Print First and Follow sets
# for key, value in first.items():
#     print(f'First({key}) = {value}')

for key, value in follow.items():
    print(f'Follow({key})={value}')