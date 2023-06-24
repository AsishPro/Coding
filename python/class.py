class Area():
  def init(self,l,b):
    self.l=l
    self.b=b
  def returnArea(self):
    return self.l*self.b

l=int(input("Enter the length of the rectangle: "))
b=int(input("Enter the breadth of the rectangle: "))
a=Area()
a.init(l,b)
print("Area of the rectangle is ",a.returnArea())