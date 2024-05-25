import mysql.connector
from flask import Flask

app = Flask(__name__)

# MySQL configurations
db_config = {
    'host': 'localhost',
    'user': 'root',
    'password': 'root',
    'database': 'phms'
}

@app.route('/')
def index():
    try:
        # Connect to the database
        conn = mysql.connector.connect(**db_config)
        cursor = conn.cursor()

        # Execute the query to fetch all users
        cursor.execute('SELECT * FROM users')

        # Fetch all the rows from the result
        users = cursor.fetchall()

        # Close the cursor and connection
        cursor.close()
        conn.close()

        # Print the user details
        for user in users:
            print(user)

        return 'User details printed in the console.'
    except mysql.connector.Error as e:
        print("An error occurred:", e)
        return 'An error occurred while accessing the database.', 500

if __name__ == '__main__':
    app.run(debug=True)
