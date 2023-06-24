class A:
    def __init__(self):
        self.name=input()
        self.age=int(input())
    def __add__(self,other):
        other.name=self.name+other.name
        other.age=self.age+other.age
        return other
    def print(self):
        print(self.name,self.age)
a=A()
b=A()  
c=a+b
c.print()   