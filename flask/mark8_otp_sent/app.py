from flask import Flask,render_template,request,session
import numpy as np
import pickle
import data
import onetimepass
import pandas as pd
from pyngrok import ngrok
import mysql.connector

app = Flask(__name__)

otp=''


# print(data.m)
#change your path
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



@app.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor()
        username = request.form['username']
        password = request.form['pass']

        cursor.execute('SELECT * FROM users WHERE username = %s AND password = %s', (username, password))

        user = cursor.fetchone()

        cursor.close()
        conn.close()

        if user:
            print('Login successful')
            return render_template("base.html", symptoms=data.sl)
        else:
            return render_template('login.html', info='Invalid username or password', alert=1)
    
    return render_template('login.html')


@app.route('/register', methods=["POST", "GET"])
def register():
    global otp
    if request.method == 'POST':
        session['user_details'] = request.form
        # data=session.get('user_details')
        # print(data,'asish')
        # print(data['fname'])
        print(request.form['email'])
        otp = onetimepass.otp_function(request.form['email'])
        print(otp + " updated")
        return render_template("register.html", otp=otp)
    else:
        return render_template("register.html")
    

@app.route('/validate_otp', methods=["POST"])
def validate_otp():
    global otp
    if 'otp' in request.form:
        if request.form['otp'] == otp:
            print("Validation Successful")
            print(request.form['otp'], otp)
            data = session.get('user_details')
            if data:
                conn = mysql.connector.connect(**db_config)
                cursor = conn.cursor()
                insert = "INSERT INTO users (username, password) VALUES (%s, %s);"
                val = (data['fname'], data['pass'])
                cursor.execute(insert, val)

                conn.commit()
                cursor.close()
                conn.close()
                print("entry successful")
                return render_template('login.html')
            else:
                return 'User details not found.'
        else:
            return render_template("register.html")
    return render_template("register.html")

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