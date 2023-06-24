import random
# li = random.sample(range(97, 123), 26)
# print(li)
lst=[1,2,4,5,5,9,11,24]
x = random.sample(lst,4)
print(x)



# import os
# import time 
# import random
# import math
# def start_game(lower,upper,x,y):
#     print("\n\tYou've only ",round(y)," chances to guess the number!\n")
#     count = 0
#     while count < y:
#         count += 1
#         guess = int(input("Guess the number:- "))
#         if x == guess:
#             print("Congratulations your guess is correct ",x,"  play again")
#             time.sleep(5)
#             menu()
#             break
#         elif x > guess:
#             print("You guessed too small!")
#         elif x < guess:
#                 print("You Guessed too high!")
#         if count >=round(y):
#          print("\nThe number is %d" % x)
#          print("\tBetter Luck Next time!")
#          time.sleep(5)
#          menu()
# def menu():
#     os.system('cls')
#     print("1. START THE GAME...........")
#     print("2.EXIT THE GAME :")
#     a=int(input("Enter a choice(1-2) :"))
#     if(a==1):
#         print("********************************************************")
#         lower = int(input("Enter Lower bound:- "))
#         upper = int(input("Enter Upper bound:- "))
#         x = random.randint(lower, upper)
#         y=math.log(upper - lower + 1, 2)
#         start_game(lower,upper,x,y)
#     if(a==2):
#         exit
# menu() 