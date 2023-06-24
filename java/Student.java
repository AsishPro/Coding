import java.util.Scanner;
public class Student {
    String name,address;
    int age;
    Student(){
        name="Unknown";
        age=0;
        address="Not available";
    }
    void setinfo(String name,int age){
        this.name=name;
        this.age=age;
        System.out.println("2 is called");
    }
    void setinfo(String name,int age,String address){
        this.name=name;
        this.age=age;
        this.address=address;
        System.out.println("3 is called");
    }
    void print(){
        System.out.println();
        System.out.println(name);
        System.out.println(age);
        System.out.println(address);
    }
    public static void  main(String[] args){
         Student o1=new Student();
         Scanner sc=new Scanner(System.in);
         String name=sc.next();
         int age=sc.nextInt();
         char ch=sc.next().charAt(0);
         if(ch=='Y'){
         String adress=sc.next();
         o1.setinfo(name,age,adress);
         o1.print();
         }  
         else
         o1.print();
    }

}
