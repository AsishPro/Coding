import base64
from tkinter import *
root= Tk()

canvas1 = Canvas(root, width = 500, height = 200, bg = 'lightsteelblue')
# canvas2=tk.Canvas(root,width=500,height=300,bg='lightpink')

canvas1.pack()
# canvas2.pack()

label1 =Label(root, text='Enter the string: ', bg = 'lightsteelblue')
# label2=tk.Label(root,text='Hellodear',bg='lightpink')


canvas1.create_window(100, 50, window=label1)
# canvas2.create_window(200,50,window=label2)

entry1 = Entry (root, width = 20)
# entry2=tk.Entry(root,width=40)

canvas1.create_window(270, 50, window=entry1)
# canvas2.create_window(270,50,windows=entry2)

def _encode ():

    x1 = str(entry1.get()) 
    encode_string=base64.b64encode(x1.encode())
    print("Encoded string",encode_string)


   
#    print(x2**0.5)

button1 = Button(text='Encode',command=_encode, bg='green', fg='white', font=('helvetica', 9, 'bold'))
# button2 = tk.Button(text='put the Square Root',command=getSquareRoot, bg='green', fg='white', font=('helvetica', 9, 'bold'))
canvas1.create_window(270, 90, window=button1)
# canvas2.create_window(270,50,window=button2)
root.mainloop()