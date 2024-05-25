from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def index():
    # Sample list to send to HTML page
    sample_list = ['Apple', 'Banana', 'Orange', 'Mango', 'Pineapple']

    return render_template('index.html', items=sample_list)

if __name__ == '__main__':
    app.run(debug=True)
