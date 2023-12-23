SUCCESS = 1
FAILED = 0

cursor = 0
string = ""

def match(expected):
    global cursor
    if cursor < len(string) and string[cursor] == expected:
        cursor += 1
        return SUCCESS
    return FAILED
    
def E():
    print(f"{string[cursor:len(string)]:<16} E -> T E'")
    return T() and Edash()

def Edash():
    global cursor
    if match('+'):
        print(f"{string[cursor:len(string)]:<16} E' -> + T E'")
        return T() and Edash()
    else:
        print(f"{string[cursor:len(string)]:<16} E' -> $")
        return SUCCESS

def T():
    print(f"{string[cursor:len(string)]:<16} T -> F T'")
    return F() and Tdash()

def Tdash():
    global cursor
    if match('*'):
        print(f"{string[cursor:len(string)]:<16} T' -> * F T'")
        return F() and Tdash()
    else:
        print(f"{string[cursor:len(string)]:<16} T' -> $")
        return SUCCESS

def F():
    global cursor
    if match('('):
        print(f"{string[cursor:len(string)]:<16} F -> ( E )")
        result = E() and match(')')
        return result
    elif match('i'):
        print(f"{string[cursor:len(string)]:<16} F -> i")
        return SUCCESS
    return FAILED

print("Enter the string:")
# string = input()
string = "i+(i+i)*i"  # Hardcoded string for testing
cursor = 0

print("\nInput Action")
print("--------------------------------")

if E() and cursor == len(string):
    print("--------------------------------")
    print("String is successfully parsed")
else:
    print("--------------------------------")
    print("Error in parsing String")
