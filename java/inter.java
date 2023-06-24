
abstract class A{
    int a=20;

    abstract void print();
}
interface B{
    int a=50;
    void print();
}
interface k{
    void print1();
}
class b{
    void print2(){
        System.out.print("ASish");
    }
}
class in implements B,k {
    public void print(){
        a=12;
     System.out.print(a);
    }
}
public class inter {
    public static void main(String[] args){
        A o1;
        o1=new in();
        o1.print();
    }
}
