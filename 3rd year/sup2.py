def has_common_digit(x, y):
    x_str = str(x)
    y_str = str(y)
    
    for digit in x_str:
        if digit in y_str:
            return True
    return False

def solution(numbers):
    n = len(numbers)
    max_chosen = 0
    
    for i in range(1 << n):
        current_chosen = [numbers[j] for j in range(n) if (i >> j) & 1 == 1]
        print(current_chosen)
        valid = True
        for x in current_chosen:
            for y in current_chosen:
                if x != y and not has_common_digit(x, y):
                    valid = False
                    break
            if not valid:
                break
        
        if valid:
            max_chosen = max(max_chosen, len(current_chosen))
    
    return max_chosen

if __name__ == '__main__':
    numbers=[50,30,15,51,10,20,15]
    result = solution(numbers)
    print(f"The maximum number of elements that can be chosen together is: {result}")