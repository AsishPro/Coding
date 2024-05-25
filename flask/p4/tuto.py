from flask import Flask,render_template,request
from flask_mail import Mail,Message
import os

app=Flask(__name__)

app.config['MAIL_SERVER']='smtp.gmail.com'
app.config['MAIL_PORT'] = 465
app.config['MAIL_USERNAME'] = 'lonewold38@gmail.com'
app.config['MAIL_PASSWORD'] = 'Lonewoldasish'
app.config['MAIL_USE_TLS'] = False
app.config['MAIL_USE_SSL'] = True

mail = Mail(app)


@app.route('/home',methods=['POST','GET'])
@app.route('/',methods=['POST','GET'])
def home():
    if request.method=='POST':
        msg=Message("Hey",sender="lonewold38@gmail.com",recipients=['asishmanoj_padala@srmap.edu.in'])
        Message.body="Hey your otp is 999232"
        mail.send(Message)
        return "Sent email."
    return render_template("temp.html")


if __name__=='__main__':
    app.run(debug=True)