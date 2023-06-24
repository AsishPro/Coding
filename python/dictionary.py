import csv

name="C:/Users/kello/Downloads/vs/python/shark_tank_companies.csv"


with open(name) as f:
    reader = csv.DictReader(f)

for row in reader: 
    print(row)