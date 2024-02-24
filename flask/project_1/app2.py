from flask import Flask,render_template


app = Flask(__name__)

@app.route('/asish')
def anything():
    return render_template('test.html')

if __name__ == "__main__":
    # app.run(host='0.0.0.0', debug=True)
    app.run(debug=True)
