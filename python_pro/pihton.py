

message = input("Enter the message to be encoded: ")

key= input("Enter the key: ")

encoded_message = ""
for character in message:

   if character.isalpha():
      encoded_message += chr((ord(character)+ord(key) - 97) % 26 + 97)

   else:
        encoded_message += character

print("Encoded message:", encoded_message)



# # Decoding

# message = input("Enter the message to be decoded: ")

# key = int(input("Enter the key: "))

# decoded_message = ""

# for character in message:

# if character.isalpha():

# decoded_message += chr((ord(character) - key - 97) % 26 + 97)

# else:

# decoded_message += character

# print("Decoded message:", decoded_message)