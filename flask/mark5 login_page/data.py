import pandas as pd


path = 'C:/Users/kello/Downloads/vs/flask/project2 copy/Symptom-severity.csv'

df1=pd.read_csv(path)
l=[i for i in range(1,len(df1)+1)]
df1['weight']=l


m={}    


for i,j in enumerate(df1['Symptom']):
    if j not in m:
        m[j]=i+1
    else:
        continue
m['none']=0
# print(m)
    

sl=list(m)
# print(m)

disease={
 'Fungal infection': 0,
 'Allergy': 1,
 'GERD': 2,
 'Chronic cholestasis': 3,
 'Drug Reaction': 4,
 'Peptic ulcer diseae': 5,
 'AIDS': 6,
 'Diabetes': 7,
 'Gastroenteritis': 8,
 'Bronchial Asthma': 9,
 'Hypertension': 10,
 'Migraine': 11,
 'Cervical spondylosis': 12,
 'Paralysis (brain hemorrhage)': 13,
 'Jaundice': 14,
 'Malaria': 15,
 'Chicken pox': 16,
 'Dengue': 17,
 'Typhoid': 18,
 'hepatitis A': 19,
 'Hepatitis B': 20,
 'Hepatitis C': 21,
 'Hepatitis D': 22,
 'Hepatitis E': 23,
 'Alcoholic hepatitis': 24,
 'Tuberculosis': 25,
 'Common Cold': 26,
 'Pneumonia': 27,
 'Dimorphic hemmorhoids(piles)': 28,
 'Heart attack': 29,
 'Varicose veins': 30,
 'Hypothyroidism': 31,
 'Hyperthyroidism': 32,
 'Hypoglycemia': 33,
 'Osteoarthristis': 34,
 'Arthritis': 35,
 '(vertigo) Paroymsal  Positional Vertigo': 36,
 'Acne': 37,
 'Urinary tract infection': 38,
 'Psoriasis': 39,
 'Impetigo': 40,
 'no disease':41}

disease=list(disease)
# print(disease)