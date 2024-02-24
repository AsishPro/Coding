class Solution:
    def myAtoi(self, s):
        index = 0
        ans = 0
        sign = 1
        
        # Skip any leading whitespace characters
        while index < len(s) and s[index].isspace():
            index += 1
       
        # Check if the first character is a sign
        if index < len(s) and (s[index] == '+' or s[index] == '-'):
            if s[index] == '-':
                sign = -1
            index += 1
        
        # Process the remaining characters in the string
        while index < len(s) and s[index].isdigit():
            ans = ans * 10 + int(s[index])
            index += 1
        print(index)
        # Apply the sign and check for integer overflow
        ans *= sign
        if ans > 2**31 - 1:
            ans = 2**31 - 1
        elif ans < -2**31:
            ans = -2**31
        
        return ans
    
s="words with 962"
Solution().myAtoi(s)