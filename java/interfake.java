class A{
    static void print(){
        System.out.print("yes");
    }
}
class B extends A{
    static void print(){
        // super.print();
        
        System.out.print("no");
    }
}
class interfake{
    public static void main(String[] arfs){
        // B o1 = new B();
        B.print();
    }
}