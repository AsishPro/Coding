import streamlit as st
import pickle


file_path = 'C:/Users/kello/Downloads/vs/flask/updated_model/high_accuracy_named.pkl'

with open(file_path, 'rb') as f:
    model = pickle.load(f)
print(model)

st.title("Disease Prediction App")

st.write("Select the following symptoms:")

    # Dropdown menus for symptom selection
symptoms = {}
for i in range(1, 7):
    symptom_name = f"Symptom {i}"
    selected_symptom = st.selectbox(symptom_name, ["Symptom A","Symptom B", "Symptom C", "Symptom D", "Symptom E"])
    symptoms[symptom_name] = selected_symptom

if st.button("Predict"):
    # Replace this with your prediction logic
    # For demonstration purposes, it just shows selected symptoms
    st.write("Predicted Disease based on symptoms:")
    for symptom, value in symptoms.items():
        st.write(f"{symptom}: {value}")

st.markdown(
    """
    <style>
        #MainMenu {visibility: hidden;}
        footer {visibility: hidden;}
    </style>
    """,
    unsafe_allow_html=True
)