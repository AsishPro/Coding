class CAR:
    def __init__(self,model,speed,price):
        self.model=model
        self.price=price
        self.speed=speed
class FIRE(CAR):
    def __init__(self,model,speed,price,bullets,fire):
        CAR.__init__(self,model,speed,price)
        self.bullets=bullets
        self.fire=fire

    def print(self):
        print(self.model)
        print(self.speed)
        print(self.price)
        print(self.bullets)
        print(self.fire)
o1=FIRE("model-x",250,99999,45,"360")
o1.print()