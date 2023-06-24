# The union operator | combines two sets to form a new one containing items in either
# dictionary is mutable , set does not allow duplicates

# li=[1,56,6,43,34,6]
# s=set(li)
# print(li)
# print(s)

# lst=[1,2,3,4,5]
# for v in enumerate(lst):
#     print(*v)


# lst=[1,2,3,4]
# if all([i>0 for i in lst]):
#     print("yes")
# else:
#     print("no")


# last=[int(i) for i in input().split(" ")]
# print(last)

# a="asosh"
# b=a.upper()
# print(b)    

# print(", ".join(["spam", "eggs", "ham"]))

# lst=' aaaaaaa    '
# print(lst)
# print(lst.strip( ))
# print(lst)

# name = input()
# age = int(input())
# print("{0} is {1} years old".format(name,age))
# #your code goes here


# lst= [i**2 for i in range(0,10) if i**2%2==0 ]
# print(lst)

# cubes = [i**3 for i in range(5)]
# print(cubes)

# sqs = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
# print(sqs[7:5:-1])


# sqs = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
# print(sqs[1::4])


# squares = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
# print(squares[2:])


# tuple = (1, (1, 2, 3))
# print(tuple[1])


# get function will used get and return if found else can use default custom 
# pairs = {1: "apple",
#     "orange": [2, 3, 4], 
# }
# print(pairs.get("orange"))
# print(pairs.get(7,"asish"))
# print(pairs.get(12345, "not in dictionary"))


# k="nebula"
# age={"Asish":43,"raj":56,k:5}
# print(k in age)

# dict={
#   False:123
# }
# print(dict[False])


# a="cool"
# dict={a,"nice"}
# print(dict)
# a="wow"
# print(dict)


# a="cool"
# list=[a,"rock"]
# print(*list)

# t={}
# print(t[0])


# k="killue"
# age={"Asish":43,"raj":56,k:5}
# print(age["Asish"])


# f=print()
# print(f)


# def asish():
#   print("HI!")
# var =asish()
# print(var)
# # output none


# try:
#   print(1)
#   assert 2 + 2 == 5
# except AssertionError:
#   print(3)
# except:
#   print(4)


# try:
#   print(1)
#   print(20/0)
#   print(2)
# except ZeroDivisionError:
#   print(3)
# finally:
#   print(4)


# try:
#    f = open("asish.txt")
#    print(f.read())
#    print(1 / 0)
# finally:
#   f.close()


# lst=['asish','manoj','reddy']

# file=open("test.txt",'w+')
# for i in lst:
#     file.writelines(i)
   
# # print(file.read())

    
# file.write("Asish Is PRO\n")
# file.close()

# file=open("test.txt",'a')
# file.write(" HEk hacker craker")
# file=open("test.txt",'r')
# print(file.seek(5))
# print(file.readline())
# file.close()

# print(len(open('file.txt','r').readlines()))

# print(len(open('file.txt','r').read()))
# '''33'''

# file=open("file.txt")
# print(file.readlines())
# file.close()


# file=open("file.txt")
# file.read()
# print("Read again")
# print(file.read())  
# '''end of the file so prints blank'''
# print("Finished")
# file.close()


# myfile = open("file.txt",'r')
# print(myfile.read(5))
# myfile.close()


# myfile = open("C:\\Users\\kello\\Downloads\\vs\\python\\asish.txt",'w')
# myfile.write("Hello World THis is ")
# myfile.close()


# t=-1
# assert (t>0),"Haha Goteem Ha"

# print(1)
# assert False
# assertion error

# a=int(input())
# assert a==2

# try :
#     Asish=123
#     print(Asish+'123')
# except:
#     print("error Occured")
#     raise

# name = "02"
# raise NameError("Fuk OFF")


# try:
#     print(1/0)
# except ZeroDivisionError:
#     raise ValueError
# both error will come


# print(1)
# raise TypeError
# print(2)


# try: 
#     print(1)
#     print(10/0)
# except ZeroDivisionError:
#     print("AsisH Error")
# finally:
#     print("Code here will RUN Buhaha"


# try:
#   num1=input(':')
#   num2=input(':')
#   print(float(num1))
# except:
#     print("Error")


# try:
#  v=30
#  print(v + "Hello")
# except TypeError:
#     print("Asish Error")

# from math import sqrt as cool
# from math import *
# print(cool(pi))

# import random
# for i in range(5):
#    value=random.randint(1,6)
#    print(value,'',end='')


# def add(x,y):
#     return x+y
# def twice(func):
#     return 2*func
# print(twice(add(2,3)))


# def multiply(x,y):
#       return x*y
# op=multiply
# print(op(2,4))


# def add(x,y):
#     total=x+y
#     return total
#     print("Asish")
# x=2
# y=5
# print(add(2,5))


# def call(word):
#     print(word+'NICE')
# call("Asish")

# def hello():
#     print("Hello World")
# hello() 

# k=list(range(2,20,2))
# print(k)
# list(range(20, 5, -2))

# print(range(20)==range(0,20))

# k=list(range(2,7))
# print(k)


# k=list(range(5))
# print(k)
#                               RANGE FUNCTION
             
# str="testing for letter t: number of times"
# count=0
# for i in str:
#     if i=='t':
#         count=count+1
# print(count)


# words = ['Hello','World','spam','eggs']
# for k in words:
#     print(k+'!')

# i=0
# while True:
#     if i>=5:
#         break
#     else:
#         print(i,end='')
#         i+=1

# i=1
# while i<5:
#     print(i)
#     i+=1
# print("Loop Finished")


# LOOPING


# string='asish'
# print(len(string))

# words=["one",'two']
# print(words.index('two'))

# words=["one",'two']
# index=1
# words.insert(9,'is')
# print(words)

# nums=[1,2,3,4]
# print(len(nums))

# nums=["Asish"]
# nums.append('manoj')
# print(nums[1])

# nums=[1,2,3,4]
# nums.append(5)
# print(nums)

# nums=[1,2,3]
# print(not 4 in nums)

# words=["asish","manoj","Reddy","cool"]
# if('asish' in words):
#  print(1)

# words=["asish","manoj","Reddy","cool"]
# print('asish'in words)

# nums=[2,4,6]
# print(nums*2)

# nums=[1,2,3,4,5]
# nums[2]='f'
# print(nums)

# num=[5,4,3,2,[2],1]
# print(num[0])
# print(num[4])
# print(num[1])

# str="Hello"
# print(str[1])

# m=[ [1,2,3],
#     [4,5,6]
# ]
# print(m[1][2])

# num=3
# things = ['asish',1,[0,5,7],4.16]
# print(things[2][0])

# x=5
# list= []
# print(list)

# num =5
# if num>5:
#     print("greater than 5")
#     if(num<56):
#      print("less than 56")
# else:
#     print("not greater than 5")

# if 5>2:
#  print("Yes")
 
# else:
#   x=5
# print(x)
#  indentation: at least one space




# s1=input("Enter the String1")
# s2=input("Enter String 2")
# print(s1>s2)

# print(x:=input("Enter the String: ")) ***

# x="Asish"
# x*=3
# print(x)

# x="Eggssss"
# y="Toast"
# print(x+y)

# x=43
# print("Your Age is "+str(x))

# x="Thank"
# y="You"
# print(x,y,sep='')

# var ="Asish"
# print(var)

# print("Hello"*2)

# print("Asish"+"is"+"Awesome")

# print("Hello \"s World")

# #print(5//2)==2
# #5/2= 2.5 
