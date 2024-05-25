import os
import math
import random
import smtplib

def otp_function(email):
    
    digit = "0123456789"
    otp = ""
    for i in range(4):
        z=math.floor(random.random() * 10)
        otp = otp + digit[z]
    print(otp)

    subject = "Your OTP"
    body = f"Your OTP is: {otp}"
    msg = f"Subject: {subject}\n\n{body}"
    s = smtplib.SMTP_SSL("smtp.gmail.com", 465)
    s.ehlo()  # Extended Hello command, not necessary, but may be required by some servers
    Email_id = "v8481373@gmail.com"
    password = "ravd bvpi zpac hiyt"
    s.login(Email_id, password)
    send_to = email

    s.sendmail(Email_id, send_to, msg)
    print("OTP sent successfully.")

    return otp

def verify(otp1,otp2):
    if otp1 == otp2:
        print("Success")
        return 1
    else:
        return 0



# # 

# # Using SMTP_SSL for secure connection



# d = input("Enter Your OTP >>: ")
