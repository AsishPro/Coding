import numpy as np
import pandas as pd

df=pd.read_excel('mark7 medicines/med.xlsx')

def find_medicines(m):
    row=df[df['Disease']==m].iloc[0]
    new_row = row.dropna()
    return new_row

