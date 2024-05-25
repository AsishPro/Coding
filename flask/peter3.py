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
def login():
    try:
        # Connect to the database
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor()

        # Get username and password from request
        # username = request.form['username']
        # password = request.form['password']

        username="asish"
        password="asish13"

        # Execute the query to check if the username and password match
        cursor.execute('SELECT * FROM users WHERE username = %s AND password = %s', (username, password))

        # Fetch the result
        user = cursor.fetchone()

        print(user)
        # Close the cursor and connection
        cursor.close()
        conn.close()

        if user:
            return 'Login successful'
        else:
            return 'Invalid username or password'
    except mysql.connector.Error as e:
        print("An error occurred:", e)
        return 'An error occurred while accessing the database.', 500

if __name__ == '__main__':
    app.run(debug=True)
