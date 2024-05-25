from flask import Flask,render_template,request
import numpy as np
import pickle
import data
import onetimepass
import pandas as pd
from pyngrok import ngrok

app = Flask(__name__)

otp=''


# print(data.m)
file_path = 'C:/Users/kello/Downloads/vs/flask/updated_model/high_accuracy_named.pkl'

with open(file_path, 'rb') as f:
    model = pickle.load(f)
print(model)



# MySQL configurations
db_config = {
    'host': 'localhost',
    'user': 'root',
    'password': 'root',
    'database': 'phms'
}


@app.route('/')
def first():
    return render_template("base.html",symptoms=data.sl)

@app.route('/predict',methods=["POST","GET"])
def predict():
    l=[]
    selected_symptoms=[]
    form_data=request.form
    print(form_data)


    for key,value in form_data.items():
        print(key,value)
        selected_symptoms.append(value)
        print(data.m[value])
        l.append(data.m[value])
    print(l)
    
    
    while len(l)<17:
        l.append(0)
    
    l=np.reshape(l,(1,-1))

    # l1=[0 for i in range(17)]
    # l1=np.reshape(l,(1,-1))
    # print(model.predict(l1))
    
    result=model.predict(l)
    print(result)

    if l.sum()==0:
        result=[-1]
    
    return render_template("base.html", symptoms=data.sl,selected_symptoms=selected_symptoms,prediction=data.disease[result[0]]) 

    return "<h1>Working</h1>"


@app.route('/medicines_list',methods=["POST","GET"])
def medicines():
    if request.method=="POST":
        selected_disease = request.form.get('disease')
        print(selected_disease)

        row=data.medicines[data.medicines['Disease']==selected_disease].values[0][1:]
        medicines=[i for i in row if not pd.isna(i)]    
        #medicines list

        print(medicines)

        info=[]
        for i in range(len(medicines)):
            str='Unlike food, which can take hours to digest, the body absorbs alcohol quickly — long before most other nutrients. And it takes a lot more time for the body to get rid of alcohol. Most alcohol is processed by the liver.'
            info.append(str)


        dosing = []
        precautions=[]
        side_effects=[]
        for medicine in medicines:
            dose = data.med_detailed[(data.med_detailed['Medicine'] == medicine) & (data.med_detailed['Disease'] == selected_disease)][['Dosing']].values[0]

            precaution = data.med_detailed[(data.med_detailed['Medicine'] == medicine) & (data.med_detailed['Disease'] == selected_disease)][['Precautions']].values[0]

            side = data.med_detailed[(data.med_detailed['Medicine'] == medicine) & (data.med_detailed['Disease'] == selected_disease)][['Side Effects']].values[0]

            dosing.append(dose[0])
            precautions.append(precaution[0])
            side_effects.append(side[0])

        medicines=list(zip(medicines, info,dosing,precautions,side_effects))

        return render_template("medicines_info.html", medicines_info=medicines) 
    
    return render_template("medicines_final.html", diseases=data.dl) 
    

@app.route('/doctors_hosp',methods=["POST","GET"])
def doctors():
    if request.method =="POST":
        selected_disease = request.form.get('disease')
        # print(selected_disease)
        
        category1=data.categories[data.categories['Disease']==selected_disease]['Category1'].values[0]
        category2=data.categories[data.categories['Disease']==selected_disease]['Category2'].values[0]


        doctors1=data.doctor[data.doctor['Category']==category1]['Doctors'].values
        hospitals1=data.doctor[data.doctor['Category']==category1]['Hospitals'].values

        print(doctors1)
        print(hospitals1)
        

        links1=data.doctor[data.doctor['Category']==category1]['Contact'].values


        doctors2=data.doctor[data.doctor['Category']==category2]['Doctors'].values
        hospitals2=data.doctor[data.doctor['Category']==category2]['Hospitals'].values
        links2=data.doctor[data.doctor['Category']==category2]['Contact'].values

       

        return render_template('doctors_hosp.html', selected_disease=selected_disease,doctor_hospitals_links1=zip(doctors1, hospitals1,links1),doctor_hospitals_links2=zip(doctors2, hospitals2,links2),categories=[category1,category2])

    return render_template('doctors_hosp.html',diseases=data.dl)
    

if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True)
    # app.run(debug=True)
    # ngrok.set_auth_token ("2cp3wE0TnBbGDuwlraaUxGPXqas_6MvUXCiNetc79PehrVRX5")
    # ngrok_tunnel = ngrok.connect(5000)
    # print('Public URL:', ngrok_tunnel.public_url)
    # app.run()