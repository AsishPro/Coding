def shiftr():
    input_str = input("Enter the input string: ")
    # input_str="i*i+i"
    stack = []
    rules = []

    # User input for the number of production rules
    rule_count = int(input("Enter the number of production rules: "))
    # User input for each production rule in the form 'left->right'

    print("Enter the production rules (in the form 'left->right' ): ")
    for _ in range(rule_count):
        temp = input()
        token1, token2 = temp.split("->")
        rules.append((token1, token2))
    i = 0
    while True:
        # If there are more characters in the input string, add the next character to the stack
        if i < len(input_str):
            stack.append(input_str[i])
            i += 1
            print(f"{''.join(stack)}\t{input_str[i:]}\tShift {stack[-1]}")

        # Iterate through the production rules
        reduction_occurred = False
        for rule in rules:
            # Check if the right-hand side of the production rule matches the end of the stack
            if stack[-len(rule[1]):] == list(rule[1]):
                # Replace the matched substring with the left-hand side of the production rule
                stack = stack[:-len(rule[1])] + [rule[0]]
                print(f"{''.join(stack)}\t{input_str[i:]}\tReduce {rule[0]}->{rule[1]}")
                reduction_occurred = True
                break

        # Check if the stack contains only the start symbol and if the entire input string has been processed
        if len(stack) == 1 and stack[0] == rules[0][0] and i == len(input_str):
            print("\nAccepted")
            break

        # Check if the entire input string has been processed but the stack doesn't match the start symbol
        if i == len(input_str) and not reduction_occurred:
            print("\nNot Accepted")
            break


shiftr()
