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

@app.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor()
        username = request.form['username']
        password = request.form['pass']

        cursor.execute('SELECT * FROM users WHERE username = %s AND password = %s', (username, password))

        # Fetch the result
        user = cursor.fetchone()

        print(user)

        # Close the cursor and connection
        cursor.close()
        conn.close()

        if user:
            print('Login successful')
            return render_template("base.html", symptoms=data.sl)
        else:
            return render_template('login.html', info='Invalid username or password')

    return render_template('login.html')

# @app.route('/')
# def first():
#     return render_template("login.html")

# @app.route('/form_login',methods=["POST"])
# def login():
#     try:
#         # Connect to the database
#         conn = mysql.connector.connect(**db_config)
#         cursor = conn.cursor()

#         username = request.form['username']
#         password = request.form['pass']


#         # Execute the query to check if the username and password match
#         cursor.execute('SELECT * FROM users WHERE username = %s AND password = %s', (username, password))

#         # Fetch the result
#         user = cursor.fetchone()

#         print(user)
#         # Close the cursor and connection
#         cursor.close()
#         conn.close()

#         if user:
#             print('Login successful')
#             return render_template("base.html", symptoms=data.sl)
#         else:
#             return 'Invalid username or password'

#     except mysql.connector.Error as e:
#         print("An error occurred:", e)
#         return 'An error occurred while accessing the database.', 500

# @app.route('/')
# def first():
#     return render_template("base.html", symptoms=data.sl)


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
    

    
# @app.route('/form_login',methods=["POST","GET"])
# def login():
#     name1=request.form['username']
#     pass1=request.form['pass']
#     if name1=='supriya' and pass1=='supriya':   
#         return render_template("home.html",name=name1)
#     else:
#         return "<h1>THAPU BRO CORRECT PASSWORD PETU</h1>"
    
@app.route('/register')
def register():
    return render_template("register.html")
 
if __name__ == "__main__":
    # app.run(host='0.0.0.0', debug=True)
    app.run(debug=True)
    # ngrok.set_auth_token ("2cp3wE0TnBbGDuwlraaUxGPXqas_6MvUXCiNetc79PehrVRX5")
    # ngrok_tunnel = ngrok.connect(5000)
    # print('Public URL:', ngrok_tunnel.public_url)
    # app.run()