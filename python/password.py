import random
    
def generatepass(n):
   total="abcdefghijklmnopqrstABCDEFGHIJKLMNOPQRST~!@#$%^&*_123456789"
   small="abcdefghijklmnopqrst"
   capital="ABCDEFGHIJKLMNOPQRST"
   symbols="~!@#$%^&*_"
   numbers="123456789"
   password=""
   password+=random.choice(capital)
   password+=random.choice(symbols)
   password+=random.choice(numbers)
   password+=random.choice(small)
   for i in range(n-4):
      password+=random.choice(total)
   return password

length=int(input())
try:
   if(length<=3):
       print(2/0)  #intentionally generating zerodiv for length less than 3
   print(generatepass(length))
except ZeroDivisionError:
   print("Length should be minimum 4")
except Exception as e:
   print("Invalid Input")