from flask import Flask,render_template,request
import numpy as np
import pickle
import data
from pyngrok import ngrok

app = Flask(__name__)

# print(data.m)
file_path = 'C:/Users/kello/Downloads/vs/flask/project2 copy/rf.pkl'

with open(file_path, 'rb') as f:
    model = pickle.load(f)
print(model)

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
        l.append(data.m[value])
    
    while len(l)<17:
        l.append(0)
    
    l=np.reshape(l,(1,-1))
    result=model.predict(l)


    return render_template("base.html", symptoms=data.sl,prediction=data.disease[result[0]])
    return "<h1>Working</h1>"
    
# @app.route('/form_login',methods=["POST","GET"])
# def login():
#     name1=request.form['username']
#     pass1=request.form['pass']
#     if name1=='supriya' and pass1=='supriya':   
#         return render_template("home.html",name=name1)
#     else:
#         return "<h1>THAPU BRO CORRECT PASSWORD PETU</h1>"
    
 
if __name__ == "__main__":
    # app.run(host='0.0.0.0', debug=True)
    app.run(debug=True)
    # ngrok.set_auth_token("2cp3wE0TnBbGDuwlraaUxGPXqas_6MvUXCiNetc79PehrVRX5")
    # ngrok_tunnel = ngrok.connect(5000)
    # print('Public URL:', ngrok_tunnel.public_url)
    # app.run()