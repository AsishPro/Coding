class A{
    private A(){
 System.out.print("SUCCESS");
    }
    void show(){
        System.out.print("SCucess 2");
    }
}

public class cons {
    public static void main(String[] args){
       A o1=new A();
       o1.show();
    } 
}
