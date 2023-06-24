class Dog:
  def __init__(self):
    self.name=input()
    self.color=input()
  def bark(self):
    print("Woof!")

fido = Dog()
print(fido.name)
fido.bark()