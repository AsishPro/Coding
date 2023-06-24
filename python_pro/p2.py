import base64
#message - asish
#key - a
def decode(message):
    dec=[]
    message = base64.b64decode(message).decode()
    print(message)
    for i in range(len(message)):
        key_c = key[i % len(key)]
        dec.append(chr((256 + ord(message[i])- ord(key_c)) % 256))  
        '''why 256 added??'''
    print(dec)
    print("".join(dec))


def encode(message):   
   enc=[]
   print(len(message)) 
   for i in range(len(message)):
            key_c = key[i%len(key)]
            enc.append(chr((ord(message[i]) + ord(key_c)) % 256))
   print(enc)
   k=base64.b64encode("".join(enc).encode()).decode()
   print(k)
   return k

message = input("Enter the message to be encoded: ")
key= input("Enter the key: ")
k=encode(message)
decode(k)
