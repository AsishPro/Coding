from flask import Flask,jsonify, request
import os
from dotenv import load_dotenv
import pandas as pd

from datetime import date

import json


import mysql.connector

load_dotenv()


app = Flask(__name__)


def get_db_connection():
    db_host = os.getenv('DB_HOST')
    db_user = os.getenv('DB_USER')
    db_password = os.getenv('DB_PASSWORD')
    db_name=os.getenv('DB_NAME')


    db_config = {
        'host': db_host,
        'user': db_user,
        'password': db_password,
        'database': db_name
    }
    
    
    conn = mysql.connector.connect(**db_config)
    
    return conn



# print(db_host)
# print(db_user)
# print(db_password)
# print(db_name)

class DateEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, date):
            return obj.isoformat()
        return super().default(obj)



@app.route('/compare',methods=['GET'])
def compare():
    
    conn=get_db_connection()
    cursor=conn.cursor(dictionary=True)
    
    
    # table1 = request.args.get('table1')
    # table2 = request.args.get('table2')
    
    table1="data1"
    table2="data2"
    
    try:
        cursor.execute(f"Select * from {table1} where id not in (Select id from {table2})")
        not_in_data2=cursor.fetchall()
        
        cursor.execute(f"Select * from {table2} where id not in (Select id from {table1})")
        not_in_data1=cursor.fetchall()
        
        
        # finding mismatching columns
        
        cursor.execute(f"Select * from {table1}")
        data1=cursor.fetchall()
        
        cursor.execute(f"Select * from {table2}")
        data2=cursor.fetchall()
        
        
        mismatches=[]
        map1={col['id']:col for col in data1}
        map2={col['id']:col for col in data2}
        
        for id in map1.keys():
            if id in map2:
                row1=map1[id]
                row2=map2[id]
                
                row_mismatch = {"id": id, "mismatches": {}}
                
                for column in row2:
                    if column!='id' and row1[column]!=row2[column]:
                        
                        row_mismatch["mismatches"][column]={
                            "old":row2[column],
                            "new":row1[column]
                        }
                        
                # if not empty
                if row_mismatch['mismatches']:
                    mismatches.append(row_mismatch)
                    
        data = {
            "mismatched_rows": mismatches,
            "not_in_data2": not_in_data2,
            "not_in_data1": not_in_data1
        }
        
        # for clarity
        json_data = json.dumps(data, indent=4, cls=DateEncoder)
        print(json_data)
        
        return jsonify(data), 200
                    
    
    except Exception as e:
        print(f"Error occurred: {e}")
        return jsonify({"error": str(e)}), 500

    finally:
        cursor.close()
        conn.close()
    
    
    
@app.route('/print/<table>', methods=['GET'])
def print_tables(table):
    conn = get_db_connection()
    cursor = conn.cursor(dictionary=True)

    try:
        cursor.execute(f"SELECT * FROM {table}")
        data = cursor.fetchall()
        
        
        print(data)
        json_data = json.dumps(data, indent=4, cls=DateEncoder)
        print(json_data)

        # print(cursor.description)

        # print(f"\nTable {table}:")
        # for row in data:
        #     print(row)
        
        # df = pd.DataFrame(data, columns=[column[0] for column in cursor.description])
        
        # print(df)
         
        return jsonify({"table_name": table}), 200

        return "Table printed in the server console.", 200

    except Exception as e:
        print(f"Error occurred: {e}")
        return f"An error occurred: {e}", 500
    
    finally:
        cursor.close()
        conn.close()
        
        
# @app.route('/add', methods=['GET'])
# def print_tables(table):
#     conn = get_db_connection()
#     cursor = conn.cursor(dictionary=True)

#     try:
#         cursor.execute(f"SELECT * FROM {table}")
#         data = cursor.fetchall()
        
        
#         print(data)
#         json_data = json.dumps(data, indent=4, cls=DateEncoder)
#         print(json_data)

#         # print(cursor.description)

#         # print(f"\nTable {table}:")
#         # for row in data:
#         #     print(row)
        
#         # df = pd.DataFrame(data, columns=[column[0] for column in cursor.description])
        
#         # print(df)
         
#         return jsonify({"table_name": table}), 200

#         return "Table printed in the server console.", 200

#     except Exception as e:
#         print(f"Error occurred: {e}")
#         return f"An error occurred: {e}", 500
    
#     finally:
#         cursor.close()
#         conn.close()


app.run(debug=True)