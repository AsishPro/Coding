from flask import Flask,render_template,request
import numpy as np
import pickle
import data
import medicines
import onetimepass
from pyngrok import ngrok

app = Flask(__name__)

otp=''

# print(data.m)
file_path = 'C:/Users/kello/Downloads/vs/flask/updated_model/high_accuracy_named.pkl'

with open(file_path, 'rb') as f:
    model = pickle.load(f)
print(model)

import mysql.connector
from flask import Flask, request

app = Flask(__name__)

# MySQL configurations
db_config = {
    'host': 'localhost',
    'user': 'root',
    'password': 'root',
    'database': 'phms'
}


@app.route('/')
def first():
    return render_template("base.html", symptoms=data.sl)

@app.route('/predict',methods=["POST","GET"])
def predict():
    l=[]
    form_data=request.form
    print(form_data)
    for key,value in form_data.items():
        print(key,value)
        print(data.m[value])
        l.append(data.m[value])
    print(l)
    
    
    while len(l)<17:
        l.append(0)
    
    l=np.reshape(l,(1,-1))

    # l1=[0 for i in range(17)]
    # l1=np.reshape(l,(1,-1))
    # print(model.predict(l1))
    
    result=model.predict(l)
    print(result)

    if l.sum()==0:
        result=[-1]
    
    return render_template("base.html", symptoms=data.sl,prediction=data.disease[result[0]]) 

    return "<h1>Working</h1>"


@app.route('/medicines_list',methods=["POST","GET"])
def medicines():
    if request.method=="POST":
        selected_disease = request.form.get('disease')
        print('Selected disease:', selected_disease)
        return render_template("medicines.html", diseases=data.dl) 
    
    return render_template("medicines.html", diseases=data.dl) 
    





if __name__ == "__main__":
    # app.run(host='0.0.0.0', debug=True)
    app.run(debug=True)
    # ngrok.set_auth_token ("2cp3wE0TnBbGDuwlraaUxGPXqas_6MvUXCiNetc79PehrVRX5")
    # ngrok_tunnel = ngrok.connect(5000)
    # print('Public URL:', ngrok_tunnel.public_url)
    # app.run()