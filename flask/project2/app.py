from flask import Flask,render_template,request


app = Flask(__name__)

@app.route('/')
def first():
    return render_template("login.html")

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
