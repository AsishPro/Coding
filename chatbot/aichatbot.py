import spacy

# Load the spaCy language model
nlp = spacy.load("en_core_web_sm")

# Define a function to process user input and generate a response
def process_input(user_input):
    # Tokenize and process the user input
    doc = nlp(user_input.lower())
    print(doc)

    # Define simple rules for generating responses
    if "hello" in user_input:
        return "Hi there! How can I help you?"
    elif "how are you" in user_input:
        return "I'm just a computer program, but I'm doing well. Thanks for asking!"
    elif "bye" in user_input:
        return "Goodbye! If you have more questions, feel free to ask."

    # Default response for unrecognized inputs
    return "I'm sorry, I didn't understand that. Can you please rephrase?"

# Main loop for the chatbot
while True:
    # Get user input
    user_input = input("User: ")

    # Check for exit command
    if user_input.lower() == 'exit':
        print("Chatbot: Goodbye!")
        break

    # Process user input and generate a response
    response = process_input(user_input)

    # Print the chatbot's response
    print("Chatbot:", response)
