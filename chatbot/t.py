import spacy

# Load spaCy language model
nlp = spacy.load("en_core_web_sm")

# User input
user_input = "Hello, how are you doing?"

# Process the input
doc = nlp(user_input.lower())

# Print the spaCy Doc object
print(type(doc))
for token in doc:
    print(token,token.pos_)
