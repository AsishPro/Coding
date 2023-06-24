import java.util.*;
class MyString1{
    int size;
    char ch[];
    MyString1(){};
    MyString1(char chars[]){
      size=chars.length;
      ch=chars;
    }
    public char charAt(int index){
         return ch[index-1];
    }
    public int length(){
        return size;
    }
   public MyString1 substring(int begin,int end){
        char s[]=new char[end-begin];
        int k=0;
        for(int i=begin;i<end;i++){
           s[k]=ch[i];
           k++;
        }
        return (new MyString1(s));
   }
   public static MyString1 valueof(int i){
    char k[]=new char[1];
    k[0]=(char)(i+'0');
        return (new MyString1(k));
    }
    public MyString1 toLowerCase(){
        char k[]=new char[size];
        for(int i=0;i<size;i++){
            k[i]=Character.toLowerCase(ch[i]);
        }
        return (new MyString1(k));
    }
    public boolean equals(MyString1 s){
        if(s.ch==ch)
         return true;
         else
         return false;
    }

    void print(){
        System.out.println(Arrays.toString(ch));
    }

    public static void main(String[] args){
        MyString1 o1=new MyString1(new char[]{'T','E','S','T','1'});
        MyString1 o2=new MyString1(new char[]{'T','E','S','T','2'});
        MyString1 o3=o1.substring(1, 3);
        o3.print();
        System.out.println((o1.charAt(2)));
        MyString1 o4=MyString1.valueof(7);
        MyString1 o5=o1.toLowerCase();
        o5.print();
        o4.print();
        System.out.println(o1.length()); 
        System.out.println(o1.equals(o2));
        
    }
}
