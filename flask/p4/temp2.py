from flask_mail import Mail, Message
from flask import Flask,request

app = Flask(__name__)
app.config['MAIL_SERVER']='smtp.gmail.com'
app.config['MAIL_PORT'] = 465
app.config['MAIL_USERNAME'] = 'nasanasupriya@gmail.com'
app.config['MAIL_PASSWORD'] = 'nasanasupriya1234'
app.config['MAIL_USE_TLS'] = False
app.config['MAIL_USE_SSL'] = True

mail = Mail(app)


@app.route("/")
def index():
   msg = Message('Hello', sender = 'nasanasupriya@gmail.com', recipients = ['kidofrabbit@gmail.com'])
   msg.body = "Hi this is body send by calmsoul!. i HOpe ThIs WoRkS."
   mail.send(msg)
   return "Sent"

if __name__ == '__main__':
   app.run(debug = True)