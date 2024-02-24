from flask import Flask,render_template


app = Flask(__name__)

@app.route('/')
def anything():
    return "Hello World"

if __name__ == "__main__":
    # app.run(host='0.0.0.0', debug=True)
    app.run(debug=True)
