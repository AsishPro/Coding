import base64
def encoder(stri):
    encode_string=base64.b64encode(stri.encode()).decode()
    print("Encoded string",encode_string)
def decode(stri):
    decode_string=base64.b64decode(stri).decode()
    print("Decoded string",decode_string)
a=input()
encoder(a)