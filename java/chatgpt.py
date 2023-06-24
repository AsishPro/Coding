import openai
# from gtts import gTTS
# from playsound import playsound
import pyttsx3
import os

openai.api_key = "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"
engine = pyttsx3.init()  
while(1):
    print()
    prompt = input()
    model = "text-davinci-002"
    response = openai.Completion.create(
        engine=model,
        prompt=prompt,
        max_tokens=100,
        n=1,
        stop=None,
        temperature=0.7,
    )
    print()
    k=response.choices[0].text.strip()
    print(k)
    engine.say(k)  
    # play the speech  
    engine.runAndWait()
    k=input()
    
    # myobj = gTTS(text=k, lang='en', slow=False)
    # myobj.save("welcome.mp3")
    # print(k)  
    # playsound("welcome.mp3")
