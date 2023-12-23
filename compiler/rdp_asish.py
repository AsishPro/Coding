def match(sym):
    global cursor
    if cursor<len(string) and string[cursor]==sym:
        cursor+=1
        return 1
    return 0
def E():
    print(f"{string[cursor:len(string)]<16} E->TE'")
    return T() and Edash()
def T():
    print(f"{string[cursor:len(string)]<16} T->FT'")
    return F() and Tdash()
def Edash():
    if match("+"):
        print(f"{string[cursor:len(string)]<16} E'->+TE'")
        return T() and Edash()
    else:
        print(f"{string[cursor:len(string)]<16} E'->$'")
        return 1
    
def Tdash():
    if match("*"):
        print(f"{string[cursor:len(string)]<16} E'->+TE'")
        return T() and Edash()
    else:
        print(f"{string[cursor:len(string)]<16} E'->$'")
        return 1







cursor=0
string="i+(i+i)*i"