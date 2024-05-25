import random
import smtplib
from email.message import EmailMessage

# Function to generate OTP
def generate_otp():
    return str(random.randint(1000, 9999))

# Function to send OTP via email
def send_otp_email(email, otp):
    msg = EmailMessage()
    msg.set_content(f"Your OTP is: {otp}")
    msg['Subject'] = 'OTP Verification'
    msg['From'] = 'v8481373@gmail.com'
    msg['To'] = email

    smtp_server = 'smtp.gmail.com'
    smtp_port = 465
    smtp_username = 'v8481373@gmail.com'
    smtp_password = 'ravd bvpi zpac hiyt'

    with smtplib.SMTP(smtp_server, smtp_port) as server:
        server.starttls()
        server.login(smtp_username, smtp_password)
        server.send_message(msg)

# Verification function
def verify_otp(input_otp, actual_otp):
    return input_otp == actual_otp

# Example usage
email = 'asishmanoj_padala@srmap.edu.in'
otp = generate_otp()
send_otp_email(email, otp)

# Verify the OTP
input_otp = input("Enter the OTP sent to your email: ")
if verify_otp(input_otp, otp):
    print("OTP is verified successfully!")
else:
    print("Invalid OTP!")
