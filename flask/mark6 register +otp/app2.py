from flask import Flask, render_template, request, session
import numpy as np
import pickle
import data
import onetimepass
from pyngrok import ngrok
import mysql.connector

app = Flask(__name__)
app.secret_key = 'asishmanoj'  # Set a secret key for sessions

otp = ''

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
            return render_template('login.html', info='Invalid username or password', alert=1)
    
    return render_template('login.html')

@app.route('/predict', methods=["POST", "GET"])
def predict():
    l = []
    form_data = request.form
    print(form_data)
    for key, value in form_data.items():
        print(key, value)
        print(data.m[value])
        l.append(data.m[value])
    print(l)
    
    while len(l) < 17:
        l.append(0)
    
    l = np.reshape(l, (1, -1))

    result = model.predict(l)
    print(result)

    if l.sum() == 0:
        result = [-1]
    
    return render_template("base.html", symptoms=data.sl, prediction=data.disease[result[0]]) 

@app.route('/register', methods=["POST", "GET"])
def register():
    global otp
    if request.method == 'POST':
        session['user_details'] = dict(request.form)  
        otp = onetimepass.otp_function(request.form['pass'])
        print(otp + " updated")
        return render_template("register.html", otp=otp)
    
    return render_template("register.html")

   
@app.route('/validate_otp', methods=["POST"])
def validate_otp():
    global otp
    print(otp + " This is in validate")
    if 'otp' in request.form:
        if request.form['otp'] == otp:
            print("Validation Successful")
            print(request.form['otp'], otp)
            data = session.get('user_details')
            if data:
                conn = mysql.connector.connect(**db_config)
                cursor = conn.cursor()
                insert = "INSERT INTO users (username, password) VALUES (%s, %s);"
                val = (data['username'], data['pass'])
                cursor.execute(insert, val)

                conn.commit()
                cursor.close()
                conn.close()
                return render_template('login.html')
            else:
                return 'User details not found.'
        else:
            return render_template("register.html")
    return render_template("register.html")

if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True)
