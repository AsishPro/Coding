from flask_mysqldb import MySQL

import mysql.connector

# Establishing connection to MySQL database
db_connection = mysql.connector.connect(
    host="localhost",
    user="root",
    password="root",
    database="phms"
)

# Creating cursor object to execute SQL queries
cursor = db_connection.cursor()

# Example: Execute a SQL query
cursor.execute("SELECT * FROM users")

# Fetching results
results = cursor.fetchall()

for row in results:
    print(row)

# Closing cursor and database connection
cursor.close()
db_connection.close()
