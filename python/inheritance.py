class polygon:
    def triangle_d(self):
        self.base=int(input("Enter the base:"))
        self.h=int(input("Enter the height:"))
    def rec_d(self):
        self.l=int(input("Enter the length:"))
        self.b=int(input("Enter the breadth:"))
    def sq(self):
        self.a=int(input("Enter the Side:"))
class tri(polygon):
    def area(self):
        print("The Area of triangle:",self.base*self.h*0.5)
res=tri()
res.triangle_d()
res.area()


