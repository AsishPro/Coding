from flask import Flask,render_template,request
import numpy as np
import pickle
import data
import onetimepass
import pandas as pd
from pyngrok import ngrok

app = Flask(__name__)

otp=''


# print(data.m)
file_path = 'C:/Users/kello/Downloads/vs/flask/updated_model/high_accuracy_named.pkl'

with open(file_path, 'rb') as f:
    model = pickle.load(f)
print(model)



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
    selected_symptoms=[]
    form_data=request.form
    print(form_data)
    for key,value in form_data.items():
        print(key,value)
        selected_symptoms.append(value)
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
    
    return render_template("base.html", symptoms=data.sl,selected_symptoms=selected_symptoms,prediction=data.disease[result[0]]) 

    return "<h1>Working</h1>"


@app.route('/medicines_list',methods=["POST","GET"])
def medicines():
    if request.method=="POST":
        selected_disease = request.form.get('disease')
        print(selected_disease)

        row=data.medicines[data.medicines['Disease']==selected_disease].values[0][1:]

        medicines=[i for i in row if not pd.isna(i)]
        
        
        info=[]
        for i in range(len(medicines)):
            str='Unlike food, which can take hours to digest, the body absorbs alcohol quickly — long before most other nutrients. And it takes a lot more time for the body to get rid of alcohol. Most alcohol is processed by the liver.'
            info.append(str)

        medicines=list(zip(medicines, info))
        print(medicines)

        return render_template("medicines_info.html", medicines=medicines) 
    
    return render_template("medicines_final.html", diseases=data.dl) 
    





if __name__ == "__main__":
    # app.run(host='0.0.0.0', debug=True)
    app.run(debug=True)
    # ngrok.set_auth_token ("2cp3wE0TnBbGDuwlraaUxGPXqas_6MvUXCiNetc79PehrVRX5")
    # ngrok_tunnel = ngrok.connect(5000)
    # print('Public URL:', ngrok_tunnel.public_url)
    # app.run()