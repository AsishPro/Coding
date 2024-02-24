from flask import Flask,render_template
import pickle

app=Flask(__name__)
# model=pickle.load(open("model.pkl","rb"))

# print(model)

@app.route('/')
def home():
    # return render_template('test.html')
    return "<h1>Asish</h1>"


if __name__=="__main__":
    #do not need to re run
    # app.run(host='192.168.1.100', debug=True)

    app.run(debug=True)