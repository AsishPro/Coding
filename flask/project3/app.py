from flask import Flask, render_template, jsonify
import pandas as pd
import matplotlib.pyplot as plt
import io
import base64

app = Flask(__name__)

# Example route handler function
@app.route('/')
def index():
    # Generate some sample data
    df = pd.DataFrame({'x': range(10), 'y': range(10, 20)})

    # Create a plot using Matplotlib
    plt.plot(df['x'], df['y'])
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Sample Plot')

    # Convert the plot to a PNG image
    img_buffer = io.BytesIO()
    plt.savefig(img_buffer, format='png')
    img_buffer.seek(0)
    img_data = base64.b64encode(img_buffer.getvalue()).decode()

    # Convert the DataFrame to JSON
    df_json = df.to_json(orient='records')

    # Render the template with the plot and DataFrame data
    return render_template('index.html', plot=img_data, dataframe=df_json)

if __name__ == '__main__':
    app.run(debug=True)
