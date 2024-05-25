from flask import Flask, request, jsonify
from flask_mail import Mail, Message


app = Flask(__name__)

# Replace placeholders with your test email address and password (NOT your real ones!)
app.config['MAIL_SERVER'] = 'smtp.gmail.com'
app.config['MAIL_PORT'] = 587
app.config['MAIL_USE_TLS'] = True
app.config['MAIL_USERNAME'] = 'kamisettypujitha2005@gmail.com'  # Your email address
app.config['MAIL_PASSWORD'] = 'Puji@2005'  # Your email password

mail = Mail(app)

@app.route('/send-test-email', methods=['POST'])
def send_test_email():
    data = request.get_json()
    recipient_email = data.get('recipient_email')

    if not recipient_email:
        return jsonify({'error': 'Missing recipient email address'}), 400

    message = Message(
        'Test Email from Flask App',
        sender=app.config['MAIL_USERNAME'],
        recipients=[recipient_email],
        body='This is a test email sent from your Flask application.'
    )
    mail.send(message)

    return jsonify({'message': 'Email sent successfully!'})

if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True)
