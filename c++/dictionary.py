class Dictionary:
    def __init__(self):
        self.keys = []
        self.d = [[None]*25] * 48900

    def hash_this(self, key):
        total=0
        for i in range(len(key)):
            total=total + ord(key[i])
        total=total%256
        return total
    
    def hash_2(self,key):
        total=0
        for i in range(len(key)):
            total=total + ord(key[i])
        # print(f"total: {total}")
        total=total%120
        return total
    
    def add(self,name,val):
        print(self.d)
        idx = self.hash_this(name)
        ele_idx = self.hash_2(name)
        self.d[idx][ele_idx] = val
        # self.keys.append(name) 
        # if(self.d[idx]!=None):
        #    idx = self.hash_2(name)
        #    self.d[idx]=val

    def printdict(self):
        print("the dictionary elements are: ")
        for key in self.keys:
            idx = self.hash_this(key)
            if self.d[idx] != None:
                print(f"{key}: {self.d[idx]} ",end=" ")
    

    def get(self,name):
        idx=self.hash_this(name)
        print(f"{name}: {self.d[idx]}")

        # print(self.d[t])


obj=Dictionary()
# print("Enter the number of values to full in dictionary(size): ",end="")
# n=int(input())
# for i in range(n):
#     print("Enter the name: ",end="")
#     name=input()
#     print("Enter the value: ",end="")
#     val=int(input())
#     obj.add(name,val)

# obj.set("asish", 23)  #finds the value 
# obj.set("kailash", 33)  #finds the value 
# obj.printdict()   #prints whole dictionary



obj.add("ashish", 23)

