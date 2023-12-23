grammar={
    'E': ['TR'],
    'R': ['+TR', ''],
    'T': ['FY'],
    'Y': ['*FY',''],
    'F': ['(E)','i']
}


first={}
follow={}

def cal_first(sb):
    if sb in first:
        return first[sb]
    fset=set()
    for rules in grammar[sb]:
     
        if rules=='':
            fset.add('')
            continue
        for symbol in rules:
            if not symbol.isupper():
                fset.add(symbol)
                break
            fset.update(cal_first(symbol))
            if '' not in fset:
                break
  
    return fset

def cal_follow(sb):
    if sb in follow:
        return follow[sb]
    flset=set()
    if sb == 'E':
        flset.add('$')
    
    for key,value in grammar.items():
        for rule in value:
           idx=rule.find(sb)
           if idx!=-1:
                if idx==len(rule)-1:
                    if key!=sb:
                        flset.update(cal_follow(key))
                        break
                else:
                    next=rule[idx+1]
                    if not next.isupper():
                       flset.add(next)
                       break
                    first_next=cal_first(next)
                    if '' in first_next:
                        flset.update(cal_follow(key))
                    flset.update(first_next-{''})
    return flset           


            

print("First: ")
for i in grammar: 
    first[i]=cal_first(i)
    follow[i]=cal_follow(i)
    
    print(f"{i} : {first[i]}")
    

print("Follow")
for i in grammar:
    print(f"{i} : {follow[i]}")



